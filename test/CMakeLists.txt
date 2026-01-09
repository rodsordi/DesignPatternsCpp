set(SOURCE_TEST "StrategyTest.cpp" "SingletonTest.cpp")

add_executable(RunTests ${SOURCE_TEST})

target_include_directories(RunTests PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(RunTests PRIVATE 
    LibCore 
    Catch2::Catch2WithMain
)

target_compile_definitions(RunTests PRIVATE TEST_MODE)

include(Catch)
catch_discover_tests(RunTests)