set(Main_SRCS main.c ../include/queue.h queue.c)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(core ${Main_SRCS})
add_executable(queue main.c)
target_link_libraries(queue core)
