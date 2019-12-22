#include "Main.hpp"
#include "res.h"
#include "solvehelp.h"
#include <array>
#include <thread>

int boardSource[][9] = {
    {7,8,0,4,0,0,1,2,0},
    {6,0,0,0,7,5,0,0,9},
    {0,0,0,6,0,1,0,7,8},
    {0,0,7,0,4,0,2,6,0},
    {0,0,1,0,5,0,9,3,0},
    {9,0,4,0,6,0,0,0,5},
    {0,7,0,3,0,0,0,1,2},
    {1,2,0,0,0,7,4,0,0},
    {0,4,9,2,0,6,0,0,7}
};

int game();
bool back_solver(int boardSource[][9]);
void solve();

int main()
{
	std::thread t1(game);
	std::thread t2(solve);
	t2.join();
	t1.join();

}

void solve()
{
	while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sf::sleep(sf::milliseconds(1));
		}

	if (!SolveSudoku(boardSource) == true)
		cout << "No solution exists";
}

bool back_solver(int boardSource[][9])
{

	int x,y;
	if(getEmpty(boardSource,x,y))
		return true;

	for (int i = 1; i < 10; i++)
	{
		if (valid(boardSource,i,x,y))
		{
			boardSource[x][y]==i;

			if(back_solver(boardSource))
				return true;

			boardSource[x][y] = 0;
		}
	}
	return false;

}

int game()
{
#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

//***********DEBUG VARIABLES**************************


//****************************************************

// #if defined(_DEBUG)
// 	std::cout << "Hello World!" << std::endl;
// #endif




	sf::RenderWindow window(sf::VideoMode(300,300), "PREESS SPACE TO BEGIN",sf::Style::Titlebar | sf::Style::Close);
// #ifdef SFML_SYSTEM_WINDOWS
//	__windowsHelper.setIcon(window.getSystemHandle());
// #endif

	sf::CircleShape shape(window.getSize().x/2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	sf::Event event;



	Board board(boardSource);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
///////////////////////////////////////////////////////////////////////////
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			;
		}
///////////////////////////////////////////////////////////////////////////

		board.update(boardSource);

		window.clear(sf::Color::White);
		//window.draw(shape);
		board.drawTo(window);
		window.display();
	}

	return 0;
}

