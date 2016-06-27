#CMakeLists.txt

#:Author: ncanestrari
#:Email: ncanestrari@ssp-server.net
#:Date: 2016-06-24 11:00

include(ExternalProject)
# Set default ExternalProject root directory
SET_DIRECTORY_PROPERTIES(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/third_party)

# Add gtest
# http://stackoverflow.com/questions/9689183/cmake-googletest
ExternalProject_Add(
    googletest
    URL http://googletest.googlecode.com/files/gtest-1.6.0.zip
    # TIMEOUT 10
    # # Force separate output paths for debug and release builds to allow easy
    # # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    # CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
    #            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
    #            -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIR ${source_dir}/include)

# Library
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBRARY_PATH ${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GTEST_LIBRARY gtest)
add_library(${GTEST_LIBRARY} SHARED UNKNOWN IMPORTED)
set_property(TARGET ${GTEST_LIBRARY} PROPERTY IMPORTED_LOCATION
                ${GTEST_LIBRARY_PATH} )
add_dependencies(${GTEST_LIBRARY} googletest)

include_directories(${GTEST_INCLUDE_DIR})
include_directories(${FakeLib_SOURCE_DIR}/fff/Include)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Logger/Include)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Status/Include)
include_directories(${FakeLib_SOURCE_DIR}/Sources/Vector/Include)

add_executable(Test_Logger Test_Logger.cpp)
target_link_libraries(Test_Logger Logger ${GTEST_LIBRARY} pthread)

add_executable(Test_Status Test_Status.cpp)
target_link_libraries(Test_Status Status ${GTEST_LIBRARY} pthread)

add_executable(Test_Vector Test_Vector.cpp)
target_link_libraries(Test_Vector Vector ${GTEST_LIBRARY} pthread)
