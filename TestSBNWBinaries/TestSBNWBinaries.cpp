// TestSBNWBinaries.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "TestSBNWBinaries.h"
#include "windows.h"

using namespace std;

typedef int(_cdecl *DLLPROC)(LPWSTR);

HINSTANCE loadDLL(LPCSTR name) {
	HINSTANCE hinstDLL = LoadLibrary(name);
	if (!hinstDLL) {
		std::cout << "could not load the dynamic library" << std::endl;
		exit(1);
	}
	return hinstDLL;
}

DLLPROC loadFunc(HINSTANCE hInstance, LPCSTR name) {
	DLLPROC proc = (DLLPROC)GetProcAddress(hInstance, name);
	if (proc == NULL) {
		std::cout << "Could not get function name: " << name << endl;
	}
	return proc;
}



int main()
{
	LPCSTR path= "D:\\TestSBNWBinaries\\libs\\sbml_draw.dll";
	HINSTANCE libsbmlDraw= loadDLL(path);

	// This is now a function pointer
	DLLPROC gf_SBMLModel = loadFunc(libsbmlDraw, "gf_SBMLModel");

	std::string model_path = "D:\\TestSBNWBinaries\\TestSBNWBinaries\\network.sbml";


	(gf_SBMLModel);

	FreeLibrary(libsbmlDraw);

	
	return 0;
}
