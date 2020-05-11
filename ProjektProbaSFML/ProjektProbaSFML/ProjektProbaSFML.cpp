/*
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Music.hpp"
using namespace std;

int main()
{

	int x = 800, y = 600, move1=27,move2=27,przl=0,move_ya_ass=6;
	bool zmiana = true;
	sf::RenderWindow window(sf::VideoMode(x, y), "game");
	sf::Music music;
	if (!music.openFromFile("cbp_music.wav"))
		return -1; // error
	music.play();
	music.setLoop(true);
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		sf::Texture background;
		sf::Texture bridge;
		sf::Texture guy;
		sf::Font cyberfont;



		sf::Sprite background_1;
		sf::Sprite bridge_1;
		sf::Sprite guy_1;
		sf::Text text;
		text.setFont(cyberfont);
		if (!cyberfont.loadFromFile("Championship.ttf"))
		{
			// error...
		}
		if (!background.loadFromFile("background.png"))
		{

		}
		if (!bridge.loadFromFile("bridge.png"))
		{

		}
		if (!guy.loadFromFile("guy.png", sf::IntRect(move1, 0, move2, 40)))
		{

		}
		text.setString("CYBER DRUNK");
		text.setCharacterSize(120);
		text.setFillColor(sf::Color::Yellow);
		text.setPosition(sf::Vector2f(50,40));
		background_1.setPosition(sf::Vector2f(0, 0));
		bridge_1.setPosition(sf::Vector2f(0, 0));
		guy_1.setPosition(sf::Vector2f(move_ya_ass, 400));
		guy_1.setScale(sf::Vector2f(5, 5));
		background_1.setTexture(background);
		bridge_1.setTexture(bridge);
		guy_1.setTexture(guy);
		window.draw(text);
		window.draw(background_1);
		window.draw(bridge_1);
		window.draw(guy_1);
		window.display();

		//przl++;
		//if (move1 == 54 && przl == 4)
		//{
		//	move1 = 0;
//
		//}
		//if (przl == 4)
		//{
		//	move1 = move1 + 27;
		//	przl = 0;
		//	move_ya_ass = move_ya_ass + 27;
		//}
		//if (move_ya_ass == 600)
		//{
		//	move_ya_ass = 6;
		//}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			move1 = move1 + 27;
			move_ya_ass = move_ya_ass + 27;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			move1 = move1 - 27;
			move_ya_ass = move_ya_ass - 27;
		}
		if (move1 == 54)
		{
			move1 = 0;

		}
		if (move_ya_ass == 600)
		{
			move_ya_ass = 6;
		}
	}
	return 0;
}
*/