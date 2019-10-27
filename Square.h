#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Square : public sf::Drawable
{
public:
	Square(float t_X, float t_Y);
	Square() = delete;
	~Square() = default;

	void update();

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape in_square,ex_square;
	const float in_squareEdge{26.f};
	const float ex_squareEdge{36.f};
	const float squareVelocity{1.5f };
	Vector2f velocity{ 0.f, 0.f };
};
  
