#include <iostream>
#include "../include/snake.hpp"

#define HEIGHT 20
#define WIDTH 50
#define WINDOWVERTICALPOSITION 0
#define WINDOWHORIZONTALPOSITION 0

//Note : 
// - Random Characters Position already finished
// - Random Snake Character for Vertical Position also finished

// To do : 
// - Create class for character

int main() {
	initscr();
	const char gameTitle[] = "[ Snake CLI ]";
	const char scoreTitle[] = "[ Score ]";
	Game* Map = new Game(HEIGHT, WIDTH, WINDOWVERTICALPOSITION, WINDOWHORIZONTALPOSITION, gameTitle, scoreTitle);

	Map->render();
	
	delete Map;
	return 0;
}
