#include <unistd.h>
#include <string.h>
#include "ncurses/ncurses.h"

#ifndef __SNAKE
#define __SNAKE

class Characters;

class Game {
	private: 
		// Member Property to  Windows Size
		int Height;
		int Width;

		// Member Property to Windows Coordinat
		int WindowVerticalPosition;
		int WindowHorizontalPosition;

		// Member Property to Windows Name
		const char* NameTitle;
		const char* ScoreTitle;
		
		// Member Property to Create Windows
		WINDOW *Map;
		WINDOW *Score;

		// Member Property to Get Length Windows Name
		size_t LengthName;
		size_t LengthScore;

		// Member Property to Windows Name Position
		int PositionName;
		int PositionScore;


	public:	
		//Characters Food;
		Game(int, int, int, int, const char*, const char*);
		void render();
		~Game();
};


class Characters {
	private:
		const char* Food = "+";

	public: 
		friend class Game;
		int RandomPositionVertical();
		int RandomPositionHorizontal();
};

#endif



