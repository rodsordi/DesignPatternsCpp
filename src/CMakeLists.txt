set(SOURCE_LIB  "strategy/MagicCardStrategy.cpp" "strategy/TrapCardStrategy.cpp" "strategy/Card.cpp" )

set(HEADER_LIB "strategy/MagicCardStrategy.h" "strategy/TrapCardStrategy.h" "strategy/Card.h" "strategy/CardStrategy.h" "singleton/GameImmutableInfo.h" "builder/GameMatch.h" "builder/GameMatchDirector.h" "abstract_factory/BaseEnemy.h" "abstract_factory/GoblinEnemy.h" "abstract_factory/KoboldEnemy.h" "abstract_factory/EnemySpawn.h" "abstract_factory/GoblinSpawn.h" "abstract_factory/KoboldSpawn.h" "abstract_factory/BaseSpawn.h" "abstract_factory/ItemSpawn.h" "abstract_factory/BaseItem.h")

add_library(LibCore STATIC
    ${SOURCE_LIB}
    ${HEADER_LIB}
 )

add_executable(DesignPatternsCpp main.cpp)

target_link_libraries(DesignPatternsCpp PRIVATE LibCore)