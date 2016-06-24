#CMakeLists.txt

#:Author: ncanestrari
#:Email: ncanestrari@ssp-server.net
#:Date: 2016-06-24 09:28

add_library(Status SHARED status.c)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Status/Include)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Logger/Include)
target_link_libraries(Status Logger)
