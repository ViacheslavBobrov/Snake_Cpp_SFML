#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Segment.h"

enum Direction { up, down, left, right };

class Snake : public sf::Drawable
{
private:
	Direction direction;
	sf::Texture segmentTexture;
	sf::Texture headTexture;
	vector<Segment> body;

public:
	Snake();

	void move(int step);
	
	void addSegment(float x, float y);

	sf::Vector2f getHeadPosition();

	sf::Vector2f getTailPosition();

	void setDirection(Direction newDirection);

	Direction getDirection();

	bool isCollision(sf::Vector2f coord);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};



