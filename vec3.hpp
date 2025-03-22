// ----------
// vec3.hpp
// ----------

/**
 * vec3 class used for representing 3D points or directions
 Rays, points, directions, colors, and surface normals, is represented using 3D vectors. This class makes it easy to do the essential math operations (like addition, scaling, dot products, and cross products) needed to calculate how rays move, bounce, and interact with objects in the scene.
**/

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using namespace std;

class vec3 {
	public:
		// 3D vector
		double e[3];

		// Default constructor
		vec3() : e{0,0,0} {}

		// Param constructor
		vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

		// Accessors
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }
		
		// Vector operators
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) { return e[i]; }

		// Vector in-place modification operators
		vec3& operator+=(const vec3& v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}

		vec3& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}

		vec3& operator/=(double t) {
			return *this *= 1/t;
		}

		// Length and magnitude functions
		double length() const {
			return sqrt(length_squared());
		}

		double length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}
};

// Use point3 for positions in space and vec3 for vectors (semantic clarity)
using point3 = vec3;

// Vector utility functions
inline ostream& operator<<(ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Vector arithmetic operators
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

// Scalar opeartions
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// Dot product of u and v
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// Cross product of u and v
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// Unit vector of v
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}


#endif
