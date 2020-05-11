#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "city.h"
#include "protagonis.h"
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	sf::RectangleShape mouse(sf::Vector2f(34, 22));

	sf::RenderWindow okno_gry(sf::VideoMode(800, 600), "Cyber Drunk", sf::Style::Close | sf::Style::Titlebar );

	sf::String playerInput;
	sf::Font imie_font;
	sf::Text imie_gracza;

	/*
	sf::Music music;
	music.openFromFile("cbp_music.wav");
	music.play();
	*/

	sf::Event okno;

	sf::Texture protagonist_texture;
	sf::Texture ground_texture;
	sf::Texture city_texture;
	sf::Texture sliver_hand_texture;

	sf::Sprite city_sprite;
	sf::Sprite ground_sprite;

	city_texture.loadFromFile("city.png");
	protagonist_texture.loadFromFile("stand&run.png");
	ground_texture.loadFromFile("ground.png");
	sliver_hand_texture.loadFromFile("silver_hand.png");

	imie_font.loadFromFile("Championship.ttf");

	protagonis protagonis(&protagonist_texture, sf::Vector2u(8, 2), 0.125f, 192.0f);

	float deltaTime = 0.0f;
	sf::Clock animation_protag_clock;

	imie_gracza.setFont(imie_font);
	imie_gracza.setCharacterSize(80);
	imie_gracza.setFillColor(sf::Color::Yellow);
	imie_gracza.setFont(imie_font);
	imie_gracza.setString(playerInput);
	imie_gracza.setPosition(0.0f, 0.0f);

	while (okno_gry.isOpen())
	{
		deltaTime = animation_protag_clock.restart().asSeconds();

		while (okno_gry.pollEvent(okno))
		{

			switch (okno.type)
			{
			case sf::Event::Closed:
				okno_gry.close();
				break;
				/*
			case sf::Event::TextEntered:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
				{
					playerInput.erase(playerInput.getSize() - 1, 1);
				}
				else
				{
					playerInput += okno.text.unicode;
					transform(playerInput.begin(), playerInput.end(), playerInput.begin(), ::toupper);
				}
				break;
			*/
			}

		}
		okno_gry.setMouseCursorVisible(false);
		sf::Vector2i position = sf::Mouse::getPosition(okno_gry);
		mouse.setPosition((position.x)-34,(position.y)-22);
		mouse.setTexture(&sliver_hand_texture);

		ground_sprite.setTexture(ground_texture);
		ground_sprite.setScale(sf::Vector2f(4.0f, 4.0f));
		ground_sprite.setPosition(sf::Vector2f(0.0f, 0.0f));

		city_sprite.setTexture(city_texture);
		city_sprite.setPosition(sf::Vector2f(0.0f, 0.0f));

		protagonis.Update(deltaTime);



		okno_gry.draw(city_sprite);
		protagonis.Draw(okno_gry);
		okno_gry.draw(ground_sprite);
		okno_gry.draw(imie_gracza);
		okno_gry.draw(mouse);
		okno_gry.display();
	}
	
	return 0;
}