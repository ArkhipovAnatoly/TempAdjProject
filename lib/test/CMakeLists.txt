


set(Sources ExampleTests.cpp)

add_executable(ExampleTests ${Sources})
target_link_libraries(ExampleTests PUBLIC gtest_main gmock_main sample_lib)
