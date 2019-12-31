#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Segment.h"

using namespace sf;
using namespace std;


enum Direction { up, down, left, right };

class Snake : public Drawable
{
private:
	Direction direction;
	Texture segmentTexture;
	Texture headTexture;
	vector<Segment> body;

public:
	Snake();

	void move(int step);
	
	void addSegment(float x, float y);

	Vector2f getHeadPosition();

	Vector2f getTailPosition();

	void setDirection(Direction newDirection);

	Direction getDirection();

	bool isCollision(Vector2f coord);

	void draw(RenderTarget& target, RenderStates states) const;
};



