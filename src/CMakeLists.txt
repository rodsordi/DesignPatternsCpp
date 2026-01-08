set(FONTES_LIB
    strategy.cpp
)

set(HEADERS_LIB
    strategy.hpp
)

add_library(MinhaLibCore STATIC
    ${FONTES_LIB}
    ${HEADERS_LIB}
)

add_executable(DesignPatternsCpp main.cpp)

target_link_libraries(DesignPatternsCpp PRIVATE MinhaLibCore)