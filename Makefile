game: game.o map_class.o hero_class.o
	g++ -o game game.o map_class.o hero_class.o -lncurses
game.o: game.cpp game.h
	g++ -c game.cpp -lncurses
map_clas.o: map_class.cpp game.h
	g++ -c map_class.cpp -lncurses
hero_class.o: hero_class.cpp game.h 
	g++ -c hero_class.cpp
