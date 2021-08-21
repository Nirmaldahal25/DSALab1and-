project(circularqueue)

include_directories(include)

set(HEADER_FILE ./include/CircularQueue.hpp)

add_executable(${PROJECT_NAME} ./src/CircularQueue.cpp ${HEADER_FILE})