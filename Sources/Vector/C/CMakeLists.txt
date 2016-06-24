#CMakeLists.txt

#:Author: ncanestrari
#:Email: ncanestrari@ssp-server.net
#:Date: 2016-06-24 09:29

add_library(Vector SHARED vector.c)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Logger/Include)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Status/Include)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Vector/Include)
target_link_libraries(Vector Status Logger)

