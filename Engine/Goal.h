#pragma once

#include "Graphics.h"
#include "Dude.h"
#include "Vec2.h"

class Goal
{
public:
	Goal( float in_x,float in_y )
		:
		position( in_x, in_y )
	{}
	void Draw( Graphics& gfx ) const
	{
		gfx.DrawRectDim( int( position.x ),int( position.y ),int( dimension ),int( dimension ),c );
	}
	bool TestCollision( const Dude& dude ) const
	{
		const float duderight = dude.GetX() + dude.GetWidth();
		const float dudebottom = dude.GetY() + dude.GetHeight();
		const float pooright = position.x + dimension;
		const float poobottom = position.y + dimension;

		return
			duderight >= position.x &&
			dude.GetX() <= pooright &&
			dudebottom >= position.y &&
			dude.GetY() <= poobottom;
	}
	void Respawn( float in_x,float in_y )
	{
		position.x = in_x;
		position.y = in_y;
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