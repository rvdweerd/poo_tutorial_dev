#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

class Goal
{
public:
	Goal( const Vec2& pos_in )
		:
		position( pos_in )
	{}
	void Draw( Graphics& gfx ) const
	{
		gfx.DrawRectDim( int( position.x ),int( position.y ),int( dimension ),int( dimension ),c );
	}
	bool TestCollision( const Dude& dude ) const
	{
		const float duderight = dude.GetPosition().x + dude.GetWidth();
		const float dudebottom = dude.GetPosition().y + dude.GetHeight();
		const float pooright = position.x + dimension;
		const float poobottom = position.y + dimension;

		return
			duderight >= position.x &&
			dude.GetPosition().x <= pooright &&
			dudebottom >= position.y &&
			dude.GetPosition().y <= poobottom;
	}
	void Respawn( const Vec2& pos_in )
	{
		position = pos_in;
	}
	void UpdateColor()
	{
		if( colorIncreasing )
		{
			if( c.GetR() >= 253 )
			{
				colorIncreasing = false;
			}
			else
			{
				c = Color( c.GetR() + 2,c.GetG() + 4,c.GetB() + 4 );
			}
		}
		else
		{
			if( c.GetR() <= 127 )
			{
				colorIncreasing = true;
			}
			else
			{
				c = Color( c.GetR() - 2,c.GetG() - 4,c.GetB() - 4 );
			}
		}
	}
private:
	static constexpr float dimension = 20;
	Color c = { 127,0,0 };
	bool colorIncreasing = true;
	Vec2 position;
};