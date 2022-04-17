#pragma once
#include <iostream>
struct vec2{
    float x, y;
    vec2();
    vec2(float xx = 0, float yy = 0);
    
    vec2 operator *(float k) const;
    vec2 operator /(float k) const;
    
    vec2 operator + (const vec2 &v) const;
    vec2 operator - (const vec2 &v) const;
    vec2 operator * (const vec2 &v) const;
    vec2 operator / (const vec2 &v) const;
    
    vec2& operator += (const vec2 &v);
    vec2& operator -= (const vec2 &v);
    vec2& operator *= (const vec2 &v);
    vec2& operator /= (const vec2 &v);
    
    vec2& operator *= (float k);
    vec2& operator /= (float k);
    
    vec2 operator -();
    
    bool operator == (const vec2 &v) const;
    bool operator != (const vec2 &v) const;
    
    vec2& getrotate(float angle);
    vec2 rotated(float angle) const;
    
    float len();
    
    vec2 norm();
    
    vec2 perpen();
    
};

vec2 operator * (float k, const vec2 &v);

float operator|(const vec2 &v1, const vec2 &v2);
float operator^(const vec2 &v1, const vec2 &v2);
    
std::ostream& operator<<(std::ostream &stream, const vec2 &v);
std::istream& operator>>(std::istream &stream, vec2 &v);

