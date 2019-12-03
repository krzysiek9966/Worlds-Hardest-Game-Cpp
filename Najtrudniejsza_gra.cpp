#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Square.h"
#include "Line.h"
#include <iostream>

using namespace sf;
using namespace std;



template <class T1, class T2> bool isIntersecting(T1& A, T2 B)
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(Line& line, Square& square)
{
	if (!isIntersecting(line, square)) {
		return false;
	}
	else {
		if (square.top() <= line.bottom() && square.bottom() > line.bottom()) {
			square.topCollision(false);
		}
		else square.topCollision(true);

		if (square.bottom() >= line.top() && square.top() < line.top()) {
			square.bottomCollision(false);
		}
		else square.bottomCollision(true);

		if (square.right() >= line.left() && square.left() < line.left()) {
			square.rightCollision(false);
		}
		else square.rightCollision(true);

		if (square.left() <= line.right() && square.right() > line.right()) {
			square.leftCollision(false);
		}
		else square.leftCollision(true);
	}
}

int main()
{
	RenderWindow window{ VideoMode{1000,750}, "Najtrudniejsza gra swiata w C++" };
	window.setFramerateLimit(120); 
	Event event;
	SoundBuffer sb;
	
#define countLinesLvl1  16
	float lines1Lvl[countLinesLvl1][4] = { 
		{95,200,6,356},{100,200,156,6},{250,200,6,300},{250,500,56,6},
	{300,250,6,256},{300,250,356,6},{650,200,6,56},{650,200,256,6},
	{900,200,6,356},{750,550,156,6},{750,250,6,300},{700,250,56,6}, 
	{700,250,6,256},{356,500,350,6},{356,500,6,56},{95,550,256,6} };

	vector<Line> lines;
	
	for (int i = 0; i < countLinesLvl1; i++) {
		lines.emplace_back(lines1Lvl[i][0], lines1Lvl[i][1], lines1Lvl[i][2], lines1Lvl[i][3]);
	}

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
		/*collisionTest(line, square);*/

		square.update();

		for (auto& line : lines) collisionTest(line, square);

		for (auto& line : lines) {
			window.draw(line);
		}

		window.draw(square);
		window.display();
	}
	return 0;
}

