cmake_minimum_required(VERSION 3.17)
project(CorrectBracketsSequenceChecker)

set(CMAKE_CXX_STANDARD 20)

add_executable(CorrectBracketsSequenceChecker main.cpp)

SET(CMAKE_INSTALL_RPATH "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory(BracketsLibrary)
target_link_libraries(CorrectBracketsSequenceChecker PUBLIC BracketsLibrary)
add_subdirectory(ContainersLibrary)
target_link_libraries(CorrectBracketsSequenceChecker PUBLIC ContainersLibrary)