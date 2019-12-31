#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Segment : public Drawable
{
private:
	Sprite shape;
public:
	Segment(float x, float y, Texture& texture);

	Vector2f getPosition();

	void setPosition(Vector2f position);

	void draw(RenderTarget& target, RenderStates states) const;
};
