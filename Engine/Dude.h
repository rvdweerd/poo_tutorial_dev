#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void ClampToScreen();
	void Respawn(float in_x, float in_y);
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd,float dt );
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
private:
	float x = 400.0f;
	float y = 300.0f;
	static constexpr float speed = 3.0f * 60.0f;
	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;
};