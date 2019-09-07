#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"
#include "Surface.h"

class Poo
{
public:
	Poo();
	void Init( const Vec2& pos_in, const Vec2& vel_in );
	void Update( float dt );
	bool TestCollision( const Dude& dude ) const;
	void Draw( Graphics& gfx ) const;
private:
	Vec2 position;
	Vec2 velocity;
	static constexpr float width = 24;
	static constexpr float height = 24;
	bool initialized = false;
	const Surface surface;
};