#include "Square.h"


Square::Square(float t_X, float t_Y)
{
	in_square.setPosition(t_X, t_Y);
	in_square.setSize(Vector2f(this->in_squareEdge, this->in_squareEdge));
	in_square.setFillColor(Color(230, 0, 0));
	in_square.setOrigin(this->in_squareEdge/2, this->in_squareEdge/2);

	ex_square.setPosition(t_X, t_Y);
	ex_square.setSize(Vector2f(this->ex_squareEdge, this->ex_squareEdge));
	ex_square.setFillColor(Color(120, 0, 0));
	ex_square.setOrigin(this->ex_squareEdge/2, this->ex_squareEdge/2);
}

void Square::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->ex_square, state);
	target.draw(this->in_square, state);
}

void Square::update()
{
	ex_square.move(this->velocity);
	in_square.move(this->velocity);

	//Ruch po osi x:
	if ((Keyboard::isKeyPressed(Keyboard::Key::A)|| Keyboard::isKeyPressed(Keyboard::Key::Left))&&freeLeft == true)
	{
		velocity.x = -squareVelocity;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))&&freeRight == true)
	{
		velocity.x = squareVelocity;
	}else velocity.x = 0.f;
	
	//Ruch po osi y:
	if ((Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))&&freeTop == true)
	{
		velocity.y = -squareVelocity;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))&&freeBottom == true)
	{
		velocity.y = squareVelocity;
	}
	else velocity.y = 0.f;
	
	Square::reload();
}

float Square::top()
{
	return this->ex_square.getPosition().y - ex_squareEdge/2;
}
float Square::bottom()
{
	return this->ex_square.getPosition().y + ex_squareEdge/2;
}
float Square::right()
{
	return this->ex_square.getPosition().x + ex_squareEdge/2;
}
float Square::left()
{
	return this->ex_square.getPosition().x - ex_squareEdge/2;
}

void Square::topCollision(bool x)
{
	this->freeTop = x;
}
void Square::bottomCollision(bool x)
{
	this->freeBottom = x;
}
void Square::rightCollision(bool x)
{
	this->freeRight = x;
}
void Square::leftCollision(bool x)
{
	this->freeLeft = x;
}
void Square::reload()
{
	this->freeTop = true;
	this->freeBottom = true;
	this->freeRight = true;
	this->freeLeft = true;
}
