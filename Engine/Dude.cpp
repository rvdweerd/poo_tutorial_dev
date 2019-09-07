#include "Dude.h"
#include "Graphics.h"
#include "Vec2.h"

Dude::Dude()
	:
	surface("Images\\awsom.bmp")
{
}

void Dude::ClampToScreen()
{
	const float right = position.x + width;
	if( position.x < 0 )
	{
		position.x = 0;
	}
	else if( right >= float( Graphics::ScreenWidth ) )
	{
		position.x = float( Graphics::ScreenWidth - 1 ) - width;
	}

	const float bottom = position.y + height;
	if(position.y < 0 )
	{
		position.y = 0;
	}
	else if( bottom >= float( Graphics::ScreenHeight ) )
	{
		position.y = float( Graphics::ScreenHeight - 1 ) - height;
	}
}

void Dude::Respawn( const Vec2 pos_in)
{
	position = pos_in;
}

void Dude::Draw( Graphics& gfx ) const
{
	const int x_int = int( position.x );
	const int y_int = int( position.y );
	gfx.DrawSprite(x_int, y_int, surface);
}

void Dude::Update( const Keyboard & kbd, Mouse& mouse, float dt )
{
	Vec2 delta(0, 0);
	Vec2 mousePosition(0,0), dudeCenter(0,0);

	if (mouse.LeftIsPressed())
	//if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		//position.x += speed * dt;
		mousePosition = Vec2(float(mouse.GetPosX()), float(mouse.GetPosY()));
		dudeCenter = (position + Vec2(float(width) / 2, float(height) / 2));
		delta = mousePosition - dudeCenter;
	
		//position += delta.GetNormalized() * speed * dt;
		if (delta.LengthSq() <= 2.0f)
		{
			position = mousePosition - Vec2(float(width) / 2, float(height) / 2);
		}
		else
		{
			delta.Normalize();
			position += delta * speed * dt;
		}
	}
	/*if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		delta.x = -1;
		//position.x -= speed * dt;
	}
	if( kbd.KeyIsPressed( VK_DOWN ) )
	{
		delta.y = 1;//position.y += speed * dt;
	}
	if( kbd.KeyIsPressed( VK_UP ) )
	{
		delta.y = -1;//position.y -= speed * dt;
	}*/

	
}

Vec2 Dude::GetPosition() const
{
	return position;
}

/*float Dude::GetY() const
{
	return position.y;
}*/

float Dude::GetWidth() const
{
	return width;
}

float Dude::GetHeight() const
{
	return height;
}
