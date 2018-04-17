# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(ZenroomCPP_SOURCES main.cpp)

add_executable(zenroom ${ZenroomCPP_SOURCES})

# gtest
enable_testing()
find_package(GTest REQUIRED) # Find the google testing framework on your system
include_directories(${GTEST_INCLUDE_DIRS})
target_link_libraries(zenroom ${GTEST_LIBRARIES} pthread)
#

