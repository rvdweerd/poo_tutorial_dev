#pragma once

class Vec2 
{
public:
	Vec2();
	Vec2(float x_in , float y_in);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs) const;

	//Vec2 operator-() const;
	Vec2 operator*(const float k) const;
	friend Vec2 operator*(float lhs, const Vec2& rhs);
	Vec2& operator*=(const float k);

	bool operator==(Vec2 rhs);
	bool operator!=(Vec2 rhs);
	bool operator>(Vec2 rhs);
	bool operator<(Vec2 rhs);
	bool operator>=(Vec2 rhs);
	bool operator<=(Vec2 rhs);
	
private:
	float x;
	float y;

};