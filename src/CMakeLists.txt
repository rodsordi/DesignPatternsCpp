set(SOURCE_LIB
    "person.cpp"
    "strategy/magic_card_strategy.cpp"
 "strategy/trap_card_strategy.cpp" "strategy/card.cpp")

set(HEADER_LIB
    "person.h"
    "strategy/magic_card_strategy.h"
    "strategy/trap_card_strategy.h" "strategy/card.h")

add_library(LibCore STATIC
    ${SOURCE_LIB}
    ${HEADER_LIB}
 )

add_executable(DesignPatternsCpp main.cpp )

target_link_libraries(DesignPatternsCpp PRIVATE LibCore)