#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Target : public sf::Drawable
{
private:
	sf::Sprite targetSprite;
	sf::Texture targetTexture;
	string image_files[8];

public:
	Target(void);

	void generatePos(int step);

	void changeTexture();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f getPosition();

};

