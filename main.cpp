#include "color.hpp"
#include "vec3.hpp"

#include <iostream>

using namespace std;

int main() {
	int image_width = 256;
	int image_height = 256;

	cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++) {
		clog << "\rScalines remaining: " << (image_height - j) << ' ' << flush;
		for (int i = 0; i < image_width; i++) {
			auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 3.4);
			write_color(cout, pixel_color);
		}	
	}

	clog << "\rDone.                 \n";

}
