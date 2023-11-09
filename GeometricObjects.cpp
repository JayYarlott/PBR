#include <cmath>

class Vector {
public:
	float x, y, z;
	Vector():x(0),y(0),z(0){}
	Vector(float xx, float yy, float zz) :x(xx), y(yy), z(zz) {}
	bool hasNaNs() {
		return isnan(x) || isnan(y) || isnan(z);
	}
	Vector operator+(const Vector& o) const {
		return Vector(x+o.x, y+o.y, z+o.z);
	}
	Vector& operator+=(const Vector& o) {
		x += o.x;
		y += o.y;
		z += o.z;
		return *this;
	}
	Vector operator-() const {
		return Vector(-x, -y, -z);
	}
	Vector operator-(const Vector& o) const {
		return Vector(x - o.x, y - o.y, z - o.z);
	}
	Vector& operator-=(const Vector& o) {
		x -= o.x;
		y -= o.y;
		z -= o.z;
		return *this;
	}
	Vector operator*(float s) const {
		return Vector(x*s, y*s, z*s);
	}
	Vector& operator*=(float s) {
		x *= s; y *= s; z *= s;
		return *this;
	}
	Vector operator/(float s) const {
		float inv = 1 / s;
		return Vector(x * inv, y * inv, z * inv);
	}
	Vector& operator/=(float s) {
		float inv = 1 / s;
		x *= inv; y *= inv; z *= inv;
		return *this;
	}
	Vector cross(const Vector& o) {
		return Vector(	y * o.z - z * o.y, 
						z * o.x - x * o.z, 
						x * o.y - y * o.x);
	}
	float operator*(const Vector& o) const {
		return x*o.x + y*o.y + z*o.z;
	}
	float lengthsquared() const {
		return x * x + y * y + z * z;
	}
	float length() const {
		return sqrtf(lengthsquared());
	}
};

inline Vector operator*(float s, const Vector& v) {
	return v * s;
}
inline Vector normalize(const Vector& v) {
	return v/v.length();
}

class Point {

};

class Ray {
	Point o;
	Vector v;

};

class Shape {

};