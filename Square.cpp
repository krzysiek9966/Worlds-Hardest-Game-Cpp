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
	if (Keyboard::isKeyPressed(Keyboard::Key::A)|| Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		velocity.x = -squareVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		velocity.x = squareVelocity;
	}else velocity.x = 0.f;
	
	//Ruch po osi y:
	if (Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		velocity.y = -squareVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		velocity.y = squareVelocity;
	}
	else velocity.y = 0.f;
	
	
}