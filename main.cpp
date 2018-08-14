#include <iostream>
#include <fstream>
#include "vec3.hpp"

using namespace std;
int main() {
    ofstream file;
    file.open("out.ppm");

    const int nrows = 300;
    const int ncols = 300;

    file << "P3\n" << ncols << " " << nrows << "\n255\n";

    for(int i = 0; i < nrows; ++i) {
        for(int j = 0; j < ncols; ++j) {
            vec3 col(float(i) / nrows, float(j) / ncols, 0.2);

            int ir = int(255.99 * col.r());
            int ig = int(255.99 * col.g());
            int ib = int(255.99 * col.b());

            file << ir << " " << ig << " " << ib << "\n";
        }
    }

    file.close();
}