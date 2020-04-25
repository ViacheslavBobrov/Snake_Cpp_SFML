#pragma once
#include <SFML/Graphics.hpp>


class Segment : public sf::Drawable
{
private:
	sf::Sprite shape;
public:
	Segment(float x, float y, sf::Texture& texture);

	sf::Vector2f getPosition();

	void setPosition(sf::Vector2f position);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
