cmake_minimum_required(VERSION 3.12)
set (CMAKE_CXX_STANDARD 17)
project(my_data_analysis)

#Helps a lot with debugging the build
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#Find our library and link to it
find_package(protolib REQUIRED)
add_executable(e1 src/example_1.cpp)
target_link_libraries(e1 PRIVATE protolib::protolib)

#including ROOT
find_package(ROOT 6.16 CONFIG REQUIRED)
add_executable(e2 src/root_example.cpp )
target_link_libraries(e2 PRIVATE ROOT::Hist ROOT::Core ROOT::Gpad ROOT::Rint protolib::protolib)