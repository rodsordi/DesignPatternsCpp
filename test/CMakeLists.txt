set(FONTES_TESTES
    "strategy_test.cpp"
)

add_executable(RodarTestes ${FONTES_TESTES})

target_include_directories(RodarTestes PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(RodarTestes PRIVATE 
    MinhaLibCore 
    Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(RodarTestes)