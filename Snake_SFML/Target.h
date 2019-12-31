#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Target : public Drawable
{
private:
	Sprite targetSprite;
	Texture targetTexture;
	string image_files[8];

public:
	Target(void);

	void generatePos(int step);

	void changeTexture();

	void draw(RenderTarget& target, RenderStates states) const;

	Vector2f getPosition();

};

