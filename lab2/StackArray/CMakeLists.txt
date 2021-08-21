project(stackarray)

include_directories(include)

set(HEADER_FILE ./include/StackArray.hpp)

add_executable(${PROJECT_NAME} ./src/StackArray.cpp ${HEADER_FILE})