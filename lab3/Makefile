game: game.o map_class.o hero_class.o get_command.o enemy_class.o
	g++ -o game game.o map_class.o hero_class.o get_command.o enemy_class.o -lncurses
game.o: game.cpp game.h
	g++ -c game.cpp 
map_clas.o: map_class.cpp game.h
	g++ -c map_class.cpp 
hero_class.o: hero_class.cpp game.h 
	g++ -c hero_class.cpp 
enemy_class.o: enemy_class.cpp game.h
	g++ -c enemy_class.cpp
get_command.o: get_command.cpp game.h
	g++ -c get_command.cpp
