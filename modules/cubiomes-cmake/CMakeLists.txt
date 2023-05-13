get_filename_component(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(CUBIOMES_SRC_DIR ${THIRD_PARTY_DIR}/cubiomes)

list(APPEND CUBIOMES_PUBLIC_HEADERS
        "${CUBIOMES_SRC_DIR}/javarnd.h"
        "${CUBIOMES_SRC_DIR}/generator.h"
        "${CUBIOMES_SRC_DIR}/layers.h"
        "${CUBIOMES_SRC_DIR}/quadbase.h"
        "${CUBIOMES_SRC_DIR}/finders.h"
        "${CUBIOMES_SRC_DIR}/util.h"
        "${CUBIOMES_SRC_DIR}/noise.h"
        )


list(APPEND CUBIOMES_SOURCES
        "${CUBIOMES_SRC_DIR}/finders.c"
        "${CUBIOMES_SRC_DIR}/noise.c"
        "${CUBIOMES_SRC_DIR}/quadbase.c"
        "${CUBIOMES_SRC_DIR}/biome_tree.c"
        "${CUBIOMES_SRC_DIR}/layers.c"
        "${CUBIOMES_SRC_DIR}/util.c"
        "${CUBIOMES_SRC_DIR}/generator.c"
        )

list(APPEND CUBIOMES_PUBLIC_INCLUDE_DIRS
        ${CUBIOMES_SRC_DIR}
        )

list(APPEND CUBIOMES_PUBLIC_LIBRARIES

        )

set(NAME cubiomes)
add_library(${NAME} STATIC ${CUBIOMES_SOURCES})
target_link_libraries(${NAME} PUBLIC ${CUBIOMES_PUBLIC_LIBRARIES})
target_include_directories(${NAME}
        PUBLIC  ${CUBIOMES_PUBLIC_INCLUDE_DIRS}
        PRIVATE ${CUBIOMES_PRIVATE_INCLUDE_DIRS}
        )