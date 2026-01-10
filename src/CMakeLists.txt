set(SOURCE_LIB "Person.cpp" "strategy/MagicCardStrategy.cpp" "strategy/TrapCardStrategy.cpp" "strategy/Card.cpp" )

set(HEADER_LIB "Person.h" "strategy/MagicCardStrategy.h" "strategy/TrapCardStrategy.h" "strategy/Card.h" "strategy/CardStrategy.h" "singleton/GameImmutableInfo.h")

add_library(LibCore STATIC
    ${SOURCE_LIB}
    ${HEADER_LIB}
 )

add_executable(DesignPatternsCpp main.cpp)

target_link_libraries(DesignPatternsCpp PRIVATE LibCore)