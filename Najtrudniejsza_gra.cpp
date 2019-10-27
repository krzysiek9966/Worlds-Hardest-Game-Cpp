#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Square.h"
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window{ VideoMode{1000,750}, "Najtrudniejsza gra świata w C++" };
	window.setFramerateLimit(120); 
	Event event;
	SoundBuffer sb;

	Square square(20, 200);

	//Muzyka:
	sb.loadFromFile("music.ogg");
	Sound s;
	s.setBuffer(sb);
	s.play();

	while (true)
	{
		window.clear(Color(153, 153, 255));

		window.pollEvent(event);
		if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
		{
			window.close();
			break;
		}

		square.update();

		window.draw(square);
		window.display();
	}
	return 0;
}

