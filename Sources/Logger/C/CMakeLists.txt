#CMakelist.txt

#:Author: ncanestrari
#:Email: ncanestrari@ssp-server.net
#:Date: 2016-06-24 09:20

add_library(Logger SHARED logger.c)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Logger/Include)
