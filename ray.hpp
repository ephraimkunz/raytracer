#ifndef RAYH
#define RAYH

#include "vec3.hpp"

class ray {
public:
    vec3 A; // Origin
    vec3 B; // Direction


    ray() {}
    ray(const vec3& a, const vec3& b) {
        A = a;
        B = b;
    }

    vec3 origin() const { return A; }
    vec3 direction() const { return B; }

    vec3 point_at_parameter(float t) const {
        return A + t*B;
    }
    
};

#endif // RAYH