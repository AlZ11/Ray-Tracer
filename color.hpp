// -----------
// color.hpp
// -----------

/**
 * color class used to write out a single pixel's color to the standard output stream
**/

#ifndef COLOR_HPP
#define COLOR_HPP

#include "vec3.hpp"
#include <iostream>

using namespace std;
using color = vec3;


void write_color(ostream& out, const color& pixel_color) {
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();

	// Translate the [0, 1] component values to the byte range [0, 255]
	int rbyte = int(255.999 * r);
	int gbyte = int(255.999 * g);
	int bbyte = int(255.999 * b);

	// Write out the pixel color components.
	out << rbyte << ' ' << gbyte << ' ' << bbyte << endl;
};

#endif
