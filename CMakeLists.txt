cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

project(hero)

file(GLOB_RECURSE SOURCE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/*")
file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/include/*")

set(INCLUDES "")
set(SOURCES "")

foreach(ITEM ${SOURCE_DIRS})
    if(NOT IS_DIRECTORY ${ITEM})
        list(APPEND SOURCES ${ITEM})
    endif()
endforeach()

foreach(ITEM ${INCLUDE_DIRS})
    if(IS_DIRECTORY ${ITEM})
        list(APPEND INCLUDES ${ITEM})
    endif()
endforeach()

list(APPEND INCLUDES "${CMAKE_SOURCE_DIR}/include/")

message(STATUS "Sources found: ${SOURCES}")
message(STATUS "Include directories found: ${INCLUDES}")

include_directories(${INCLUDES})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include/glad/glad.o GL glfw X11 pthread Xrandr Xi dl m)