#### ------ COMPILING OPTIONS ----- ####
# RELEASE for client delivery: cmake -DCMAKE_BUILD_TYPE=Release ..
# DEBUG for dev debugging : cmake -DCMAKE_BUILD_TYPE=Debug ..
# RELEASE with DEBUG Symbols for profiling  : cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
#### ------ COMPILING OPTIONS ----- ####

#set cmake version
cmake_minimum_required (VERSION 2.8)

#set project_name
project ("UDP_LISTENER")

#set some basic flags like for gdb use -g.
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall ")
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin) #
set(CMAKE_LIBRARY_DIR ${CMAKE_SOURCE_DIR}/bin/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_DIR})





# Add source to this project's executable.
add_executable (UDP_LISTENER "main.cpp" "src/UDP_LISTENER.cpp"  "src/logging/NanoLog.cpp")

target_link_libraries( UDP_LISTENER
-lpthread
)
