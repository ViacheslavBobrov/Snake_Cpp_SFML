#include "Target.h"


Target::Target(void): image_files{ "Diamond circle.gif", "Emerald circle.gif", "Ruby heart.gif",
		"Yellow square.gif","Sapphire circle.gif","Purple heart.gif","Emerald square.gif","Orange circle.gif" }
{
	generatePos(20);
	targetSprite.scale(0.7, 0.7);
	targetSprite.setOrigin(4, 4);
	changeTexture();

}
void Target::generatePos(int step)
{
	int x = 1 + rand() % (40 - 1);
	int y = 1 + rand() % (30 - 1);
	targetSprite.setPosition(x * step, y * step);
}
void Target::changeTexture()
{
	int i = rand() % 7;
	targetTexture.loadFromFile("Textures/" + image_files[i]);
	targetSprite.setTexture(targetTexture);
}
void Target::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(targetSprite, states);
}
Vector2f Target::getPosition()
{
	return targetSprite.getPosition();
}
