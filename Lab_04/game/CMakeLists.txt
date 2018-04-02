set(GAME_SRCS
	gameboard.h
	gameboard.cpp
	gametoken.h
	gametoken.cpp
)

add_library(game STATIC
	${GAME_SRCS}
)

target_include_directories(game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)