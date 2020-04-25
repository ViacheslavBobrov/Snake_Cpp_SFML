#include "Segment.h"

using namespace sf;

Segment::Segment(float x, float y, Texture& texture)
{
	shape.setTexture(texture);
	shape.setPosition(x, y);
}
Vector2f Segment::getPosition()
{
	return shape.getPosition();
}
void Segment::setPosition(Vector2f position)
{
	shape.setPosition(position);
}
void Segment::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(shape, states);
}