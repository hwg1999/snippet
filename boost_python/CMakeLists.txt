cmake_minimum_required(VERSION 3.22)
project(boost_python LANGUAGES CXX)

find_package(Boost REQUIRED COMPONENTS python)
find_package(PythonLibs REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/export/*cpp")

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    string(REGEX REPLACE "^[0-9]+_" "" FILE_NAME ${FILE_NAME})
    add_library(${FILE_NAME} SHARED ${SOURCE_FILE})
    target_link_libraries(${FILE_NAME} Boost::python ${PYTHON_LIBRARIES})
    set_target_properties(${FILE_NAME} PROPERTIES PREFIX "")
endforeach()