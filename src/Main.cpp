#include "Main.hpp"
#include "res.h"
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

int main()
{
	std::thread t1(game);
	t1.join();
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




	sf::RenderWindow window(sf::VideoMode(800,600), "SFML works!",sf::Style::Titlebar | sf::Style::Close);
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

