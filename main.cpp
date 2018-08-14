#include <iostream>
#include <fstream>
#include "vec3.hpp"
#include "ray.hpp"

using namespace std;

vec3 color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction()); // Scale to [-1, 1]
    float t = 0.5*(unit_direction.y() + 1.0); // Move to [0, 1]
    return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0); // Linear interpolation (white to blue)
}

int main() {
    ofstream file;
    file.open("out.ppm");

    const int nx = 200;
    const int ny = 100;

    file << "P3\n" << nx << " " << ny << "\n255\n";

    // Image 2 x 4
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    for(int j = ny - 1; j >= 0; j--) {
        for(int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            int ir = int(255.99 * col.r());
            int ig = int(255.99 * col.g());
            int ib = int(255.99 * col.b());

            file << ir << " " << ig << " " << ib << "\n";
        }
    }

    file.close();
}