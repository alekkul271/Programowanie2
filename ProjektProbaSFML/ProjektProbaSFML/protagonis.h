#include <SFML\Graphics.hpp>
#include "standby.h"

class protagonis
{
public:
	protagonis(sf::Texture* texture,sf::Vector2u imageCount,float switch_time,float speed);
	~protagonis();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& okno_gry);

private:
	sf::RectangleShape body;
	Standby standby;
	unsigned int row;
	float speed;
	bool faceRight;
};