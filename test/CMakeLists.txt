set(SOURCE_TEST "StrategyTest.cpp" "GameInfoTest.cpp")

add_executable(RunTests ${SOURCE_TEST})

target_include_directories(RunTests PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(RunTests PRIVATE 
    LibCore 
    Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(RunTests)