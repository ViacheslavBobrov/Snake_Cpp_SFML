#include "Snake.h"

Snake::Snake() :segmentTexture()
{
	segmentTexture.loadFromFile("Textures/body.jpg");
	headTexture.loadFromFile("Textures/head.jpg");

	for (int x = 0; x <= 80; x += 20) {
		body.push_back(Segment(x, 20, segmentTexture));
	}
	body.push_back(Segment(100, 20, headTexture));
	direction = Direction::right;
}

void Snake::move(int step)
{
	float x, y;
	Vector2f direct = body[body.size() - 1].getPosition();
	if (direction == Direction::up) {
		direct.y -= step;
	}
	else if (direction == Direction::down) {
		direct.y += step;
	}
	else if (direction == Direction::left) {
		direct.x -= step;
	}
	else if (direction == Direction::right) {
		direct.x += step;
	}

	for (int i = 0; i < body.size() - 1; i++) {
		body[i].setPosition(body[i + 1].getPosition());
	}
	body[body.size() - 1].setPosition(direct);
}
void Snake::addSegment(float x, float y)
{
	body.insert(body.begin(), Segment(x, y, segmentTexture));
}
Vector2f Snake::getHeadPosition()
{
	return body[body.size() - 1].getPosition();
}
Vector2f Snake::getTailPosition()
{
	return body[0].getPosition();
}
void Snake::setDirection(Direction newDirection)
{
	if ((newDirection == Direction::up && direction == Direction::down) ||
		(newDirection == Direction::down && direction == Direction::up) ||
		(newDirection == Direction::left && direction == Direction::right) ||
		(newDirection == Direction::right && direction == Direction::left)) {
		return;
	}
	direction = newDirection;
}
Direction Snake::getDirection()
{
	return direction;
}
bool Snake::isCollision(Vector2f coord)
{
	for (int i = 0; i < body.size() - 1; i++) {
		if (body[i].getPosition() == coord)
			return true;
	}
	return false;
}
void Snake::draw(RenderTarget& target, RenderStates states) const
{
	Vector2f pos;
	for (int i = 0; i < body.size(); i++) {
		body[i].draw(target, states);
	}
}