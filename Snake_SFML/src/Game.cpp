#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Target.h"

using namespace sf;
using namespace std;


class Game
{
private:

	RenderWindow window;
	Texture backgroundTexture;
	Sprite background;
	Snake snake;
	Target target;
	int score;
	float timestep;


	void handleEvents()
	{
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case Event::KeyPressed: handleKeyboardEvent(event.key.code); return; break;
			case Event::Closed:	window.close(); break;
			}
		}
	}

	void handleKeyboardEvent(Keyboard::Key key)
	{
		if (key == Keyboard::W) {
			snake.setDirection(Direction::up);
		}
		else if (key == Keyboard::S) {
			snake.setDirection(Direction::down);
		}
		else if (key == Keyboard::A) {
			snake.setDirection(Direction::left);
		}
		else if (key == Keyboard::D)
			snake.setDirection(Direction::right);
	}

	void render()
	{
		window.clear(Color(255, 255, 255));
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 10; j++) {
				background.setPosition(64 * i, 64 * j);
				window.draw(background);
			}
		}
		window.draw(target);
		window.draw(snake);
		window.display();
	}

	bool isWallHit()
	{
		return (
			(snake.getHeadPosition()).x < 0 || (snake.getHeadPosition()).x >(window.getSize()).x - 20 ||
			(snake.getHeadPosition()).y < 0 || (snake.getHeadPosition()).y >(window.getSize()).y - 20);
	}

	void changeSpeed()
	{
		if (timestep > 0.01) {
			timestep -= 0.003;
		}
	}

	bool performGameStep()
	{
		Vector2f Tail = snake.getTailPosition();
		snake.move(20.0f);
		if (snake.isCollision(snake.getHeadPosition()) || isWallHit()) {
			return false;
		}
		if (snake.getHeadPosition() == target.getPosition()) {
			snake.addSegment(Tail.x, Tail.y);
			do {
				target.generatePos(20);
			} while (snake.isCollision(target.getPosition()) || target.getPosition() == snake.getHeadPosition());
			target.changeTexture();
			score++;
			changeSpeed();
		}

		return true;
	}


public:

	Game() : window(VideoMode(800, 600), "Snake"), score(0), timestep(0.2), target()
	{
		backgroundTexture.loadFromFile("Textures/sand.png");
		background.setTexture(backgroundTexture);
	}

	void run()
	{
		Time timeSinceLastUpdate = Time::Zero;
		Clock clock;
		render();
		while (window.isOpen()) {
			if ((clock.getElapsedTime()).asSeconds() < timestep) {
				continue;
			}
			clock.restart();
			handleEvents();
			if (performGameStep()) {
				render();
			}
			else {
				cout << "Game over. Score: " << score << endl;
				break;
			}
		}
	}
};


int main()
{
	srand(time(NULL));
	Game game;
	game.run();
}