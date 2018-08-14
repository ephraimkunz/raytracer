#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <iostream>

class vec3 {
public:
    float e[3];

    vec3() {}
    vec3(float e0, float e1, float e2) {
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }

    float x(){ return e[0]; }
    float y(){ return e[1]; }
    float z(){ return e[2]; }
    float r(){ return e[0]; }
    float g(){ return e[1]; }
    float b(){ return e[2]; }

    vec3& operator+=(const vec3 &v2) {
        e[0] += v2[0];
        e[1] += v2[1];
        e[2] += v2[2];
        return *this;
    }

    vec3& operator-=(const vec3 &v2) {
        e[0] -= v2[0];
        e[1] -= v2[1];
        e[2] -= v2[2];
        return *this;
    }

    vec3& operator*=(const vec3 &v2) {
        e[0] *= v2[0];
        e[1] *= v2[1];
        e[2] *= v2[2];
        return *this;
    }

    vec3& operator/=(const vec3 &v2) {
        e[0] /= v2[0];
        e[1] /= v2[1];
        e[2] /= v2[2];
        return *this;
    }

    vec3& operator*=(const float t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=(const float t) {
        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
    }

    const vec3& operator+() const { return *this; }
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    float operator[](int i) const { return e[i]; }


    float squared_length() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    float length() const {
        return sqrt(squared_length());
    }

    void make_unit_vector() {
        float scaler = 1 / length();
        e[0] *= scaler;
        e[1] *= scaler;
        e[2] *= scaler;
    }
};

std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.e[0] >> t.e[1] >> t.e[2];
    return is;
}

std::ostream& operator<<(std::ostream &os, vec3&t) {
    os << t.e[0] << " " << t.e[1] << " " << t.e[2];
    return os;
}

vec3 operator+(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

vec3 operator-(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

vec3 operator/(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}

vec3 operator*(float t, const vec3 &v1) {
    return vec3(v1.e[0] * t, v1.e[1] * t, v1.e[2] * t);
}

vec3 operator/(vec3 v, float t) {
    return vec3(v[0] / t, v[1] / t, v[2] / t);
}

vec3 operator*(vec3 v, float t) {
    return vec3(v[0] * t, v[1] * t, v[2] * t);
}

float dot(const vec3 &v1, const vec3 &v2) {
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3( 
        (v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
        (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
        (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])
    );
}

vec3 unit_vector(vec3 v) { 
    return v / v.length();
}

#endif // VEC3H