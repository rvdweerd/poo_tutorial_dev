#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

Poo::Poo()
	:
	surface("Images\\poo.bmp")
{
}

void Poo::Init( const Vec2& pos_in, const Vec2& vel_in )
{
	assert( initialized == false );
	position = pos_in;
	velocity = vel_in;
	initialized = true;
}

void Poo::Update( float dt )
{
	assert( initialized == true );
	position += velocity * dt;
	//x += vx * dt;
	//y += vy * dt;

	const float right = position.x + width;
	if( position.x < 0 )
	{
		position.x = 0;
		velocity.x = -velocity.x;
	}
	else if( right >= float( Graphics::ScreenWidth ) )
	{
		position.x = float( Graphics::ScreenWidth - 1 ) - width;
		velocity.x = -velocity.x;
	}

	const float bottom = position.y + height;
	if( position.y < 0 )
	{
		position.y = 0;
		velocity.y = -velocity.y;
	}
	else if( bottom >= float( Graphics::ScreenHeight ) )
	{
		position.y = float( Graphics::ScreenHeight - 1 ) - height;
		velocity.y = -velocity.y;
	}
}

bool Poo::TestCollision( const Dude& dude ) const
{
	assert( initialized == true );
	const float duderight = dude.GetPosition().x + dude.GetWidth();
	const float dudebottom = dude.GetPosition().y + dude.GetHeight();
	const float pooright = position.x + width;
	const float poobottom = position.y + height;

	return
		duderight >= position.x &&
		dude.GetPosition().x <= pooright &&
		dudebottom >= position.y &&
		dude.GetPosition().y <= poobottom;
}

void Poo::Draw( Graphics& gfx ) const
{
	assert( initialized == true );

	const int x_int = int( position.x );
	const int y_int = int( position.y );
	gfx.DrawSprite(x_int, y_int, surface, Colors::White);
	/*
	gfx.PutPixel( 14 + x_int,0 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,1 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,2 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,3 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,4 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,5 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,6 + y_int,138,77,0 );
	gfx.PutPixel( 20 + x_int,6 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,7 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,7 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,7 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,7 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,8 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,9 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,9 + y_int,102,57,0 );
	gfx.PutPixel( 13 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,9 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,9 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,10 + y_int,102,57,0 );
	gfx.PutPixel( 13 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,10 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,10 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,11 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,11 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,11 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,12 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,12 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,12 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,12 + y_int,111,62,0 );
	gfx.PutPixel( 13 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 14 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 15 + x_int,12 + y_int,102,57,0 );
	gfx.PutPixel( 16 + x_int,12 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,13 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,13 + y_int,109,61,0 );
	gfx.PutPixel( 11 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,13 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,13 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,14 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,14 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,15 + y_int,116,65,0 );
	gfx.PutPixel( 8 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,15 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 17 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 18 + x_int,15 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,16 + y_int,116,65,0 );
	gfx.PutPixel( 8 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,16 + y_int,109,61,0 );
	gfx.PutPixel( 14 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,16 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,16 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,16 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 2 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 3 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 4 + x_int,17 + y_int,87,49,0 );
	gfx.PutPixel( 5 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,17 + y_int,43,24,0 );
	gfx.PutPixel( 8 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,17 + y_int,40,22,0 );
	gfx.PutPixel( 14 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,17 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,17 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,17 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,18 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,18 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 22 + x_int,18 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 8 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,19 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,19 + y_int,138,77,0 );
	gfx.PutPixel( 22 + x_int,19 + y_int,65,36,0 );
	gfx.PutPixel( 23 + x_int,19 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 7 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 8 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 9 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 10 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 11 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 12 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 13 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 14 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 15 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 16 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 17 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 18 + x_int,20 + y_int,123,69,0 );
	gfx.PutPixel( 19 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 21 + x_int,20 + y_int,138,77,0 );
	gfx.PutPixel( 22 + x_int,20 + y_int,65,36,0 );
	gfx.PutPixel( 23 + x_int,20 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 2 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 3 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 4 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 5 + x_int,21 + y_int,138,77,0 );
	gfx.PutPixel( 6 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 7 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 8 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 9 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 10 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 11 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 12 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 13 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 14 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 15 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 16 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 17 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 18 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 20 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 21 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 22 + x_int,21 + y_int,51,28,0 );
	gfx.PutPixel( 0 + x_int,22 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 2 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 3 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 4 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 5 + x_int,22 + y_int,65,36,0 );
	gfx.PutPixel( 6 + x_int,22 + y_int,51,28,0 );
	gfx.PutPixel( 1 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 2 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 3 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 4 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 5 + x_int,23 + y_int,51,28,0 );
	gfx.PutPixel( 6 + x_int,23 + y_int,51,28,0 );
	*/
}