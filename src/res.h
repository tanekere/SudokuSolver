#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include "json.hpp"

using json = nlohmann::json;

class Square
{
	int value=0;
public:
	bool isModdable;

	sf::Texture texSheet;
	sf::Sprite valueSprite;
	sf::IntRect textureBounds;


	bool isEmpty() {return !value;}

	Square()
	{
		if(!texSheet.loadFromFile("content/numSprite.png"))
		{
			std::cout<<"import error";
		}
		valueSprite.setTexture(texSheet);
		textureBounds= sf::IntRect(0,0,4,5);
		valueSprite.setTextureRect( textureBounds);
		valueSprite.setScale(sf::Vector2f(5.f, 5.f));
	}

	bool setValue(int _value){

			this->value=_value;
			valueSprite.setTextureRect(sf::IntRect(4*_value,0,4,5));
			return true;

	}

	void setPos(sf::Vector2f pos)
	{
		valueSprite.setPosition(pos);
	}


	void drawTo(sf::RenderWindow &window)
	{
		window.draw(valueSprite);
	}
};

class Board
{

public:
	Square numArray[9][9];

	Board(json &values)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				std::cout<<values[i][j]<<' ';
				std::cout<<'{'<<i*4*5.f<<','<<j*5*5.f<<'}';
				numArray[i][j].setPos({   j*5*5.f  +   5.f*j   ,   i*4*5.f + 10.f*i   });
				numArray[i][j].setValue(values[i][j]);
				if(values[i][j]==0){
					numArray[i][j].isModdable==true;
				}else{
					numArray[i][j].isModdable==false;
				}
			}
		}
	}

	void update(json &values)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				numArray[i][j].setValue(values[i][j]);
			}
		}
	}


void drawTo(sf::RenderWindow &window)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				numArray[i][j].drawTo(window);
			}
		}
	}


};