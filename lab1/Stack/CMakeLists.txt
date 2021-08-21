project(stack)

include_directories(include)

get_filename_component(PARENT_DIR ../ ABSOLUTE)
set(HEADER_FILE ./include/Stack.hpp ${PARENT_DIR}/LinkedList/include/LinkedList.hpp)


add_executable(${PROJECT_NAME} ./src/Stack.cpp ${HEADER_FILE})
target_include_directories(${PROJECT_NAME} BEFORE PUBLIC ${PARENT_DIR}/LinkedList/include)