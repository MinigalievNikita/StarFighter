#include <math.h>
#include "Vector2.h"

vec2::vec2() {}

vec2::vec2(float xx, float yy) : x(xx), y(yy) {}

vec2 vec2::operator *(float k) const {
    return vec2(x * k, y * k);
}

vec2 vec2::operator /(float k) const {
    return vec2(x / k, y / k);
}

vec2 vec2::operator + (const vec2 &v) const{
    return vec2(x + v.x, y + v.y);
}

vec2 vec2::operator - (const vec2 &v) const{
    return vec2(x - v.x, y - v.y);
}

vec2 vec2::operator * (const vec2 &v) const{
    return vec2(x * v.x, y * v.y);
}

vec2 vec2::operator / (const vec2 &v) const{
    return vec2(x / v.x, y / v.y);
}

vec2& vec2::operator += (const vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
}

vec2& vec2::operator -= (const vec2 &v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

vec2& vec2::operator *= (const vec2 &v) {
    x *= v.x;
    y *= v.y;
    return *this;
}

vec2& vec2::operator /= (const vec2 &v) {
    x /= v.x;
    y /= v.y;
    return *this;
}

vec2& vec2::operator *= (float k){
    x = x * k;
    y = y * k;
    return *this;
}

vec2& vec2::operator /= (float k){
    x = x / k;
    y = y / k;
    return *this;
}

vec2 vec2::operator -(){
    return vec2(-x, -y);
}

bool vec2::operator == (const vec2 &v) const {
    return (x == v.x && y == v.y);
}

bool vec2::operator != (const vec2 &v) const{
    return (x != v.x && y != v.y);
}

float vec2::len(){
    return sqrt(x * x + y * y);
}

vec2 vec2::perpen(){
    return vec2(-y,x);
}

vec2 vec2::norm(){
    return vec2(x / (sqrt(x*x + y*y)), y / (sqrt(x*x + y*y)));
}

vec2& vec2::getrotate(float angle){
    x = x * cosf(angle) - y * sinf(angle);
    y = x * sinf(angle) + y * cosf(angle);
    return *this;
}

vec2 vec2::rotated(float angle) const{
    return vec2(x * cosf(angle) - y * sinf(angle), x * sinf(angle) + y * cosf(angle));
}

vec2 operator * (float k, const vec2 &v) {
    return vec2(v.x * k, v.y * k);
}

float operator|(const vec2 &v1, const vec2 &v2){
    return v1.x * v2.x + v1.y * v2.y;
}

float operator^(const vec2 &v1, const vec2 &v2){
    return v1.x * v2.y - v1.y * v2.x;
}
    
std::ostream& operator<<(std::ostream &stream, const vec2 &v) {
    stream << v.x << "  " << v.y;
    return stream;
}

std::istream& operator>>(std::istream &stream, vec2 &v){
    stream >> v.x >> v.y;
    return stream;
}
