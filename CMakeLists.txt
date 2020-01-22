# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("TestSBNWBinaries")


set(LIBS_DIR "${PROJECT_SOURCE_DIR}/libs")
set(INCLUDE_DIR"${PROJECT_SOURCE_DIR}/include")
set(LIBSBML_DRAW_LIB "${LIBS_DIR}/sbml_draw.dll")

message(${LIBSBML_DRAW_LIB})

#include_directories(${INCLUDE_DIR})
#link_libraries(${LIBSBML_DRAW_LIB})

# Include sub-projects.
add_subdirectory ("TestSBNWBinaries")
