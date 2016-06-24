#CMakelist.txt

#:Author: ncanestrari
#:Email: ncanestrari@ssp-server.net
#:Date: 2016-06-24 09:16
cmake_minimum_required(VERSION 3.0.2)
project(FakeLib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

subdirs(Sources/Logger)
subdirs(Sources/Status)
subdirs(Sources/Vector)
subdirs(GoogleTest)

