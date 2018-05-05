set(MAIN_SRCS
	player_game_history.h
	player.h
	game.h
	game_history.h
	main.cpp
)

add_executable(
	main
	${MAIN_SRCS}	
)

target_link_libraries(
	main
	# ncurses
)