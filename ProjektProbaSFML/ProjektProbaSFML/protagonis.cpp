#include "protagonis.h"

protagonis::protagonis(sf::Texture* texture, sf::Vector2u imageCount, float switch_time, float speed) : 
	standby(texture,imageCount,switch_time)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(96.0f, 160.0f));
	body.setTexture(texture);
	body.setOrigin(-400, -416);

}

protagonis::~protagonis()
{

}
void protagonis::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	standby.Update(row, deltaTime, faceRight);
	body.setTextureRect(standby.uvRect);
	body.move(movement);
}

void protagonis::Draw(sf::RenderWindow& okno_gry)
{
	okno_gry.draw(body);
}