set(MAIN_SRCS
	gameboard.h
	render_engine.h
	main.cpp
)

add_executable(
	main
	${MAIN_SRCS}	
)

target_link_libraries(
	main
	ncurses
)