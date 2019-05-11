set(Test_SRCS AllTests.cpp testQueue.cpp fff.h)

include_directories($ENV{CPPUTEST_HOME_INCLUDE})
include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(cpputest STATIC IMPORTED)
set_property(TARGET cpputest PROPERTY
        IMPORTED_LOCATION $ENV{CPPUTEST_HOME_LIB}/libCppUTest.a)

add_executable(queue-test ${Test_SRCS})
target_link_libraries(queue-test cpputest core)


