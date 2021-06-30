list(APPEND MAIN_APP_SOURCES
        main.cpp
        )
list(APPEND MAIN_APP_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}
        "${CMAKE_CURRENT_SOURCE_DIR}/cubiomes"
        )

set(MAIN_APP_LIBRARIES
        cubiomes
        )

set(NAME cubiomes-example)
add_executable(${NAME} ${GUI_TYPE} ${MAIN_APP_SOURCES})
target_include_directories(${NAME} PUBLIC ${MAIN_APP_INCLUDE_DIRS})
target_link_libraries(${NAME} ${MAIN_APP_LIBRARIES})