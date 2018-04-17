# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(ZenroomCPP_SOURCES main.cpp)

add_executable(zenroom ${ZenroomCPP_SOURCES})

