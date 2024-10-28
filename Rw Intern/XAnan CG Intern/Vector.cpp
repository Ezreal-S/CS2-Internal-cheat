#include <cmath> 
#include "Vector.h"

Vector3 Vector3::operator+(Vector3 d)
{
    return { x + d.x, y + d.y, z + d.z };
}

Vector3 Vector3::operator-(Vector3 d)
{
    return { x - d.x, y - d.y, z - d.z };
}

Vector3 Vector3::operator*(Vector3 d)
{
    return { x * d.x, y * d.y, z * d.z };
}

Vector3 Vector3::operator*(float d)
{
    return { x * d, y * d, z * d };
}

Vector4 Vector4::operator+(Vector4 d)
{
    return { x + d.x, y + d.y, w + d.w, h + d.h };
}

Vector4 Vector4::operator-(Vector4 d)
{
    return { x - d.x, y - d.y, w - d.w, h - d.h };
}

Vector4 Vector4::operator*(Vector4 d)
{
    return { x * d.x, y * d.y, w * d.w, h * d.h };
}

Vector4 Vector4::operator*(float d)
{
    return { x * d, y * d, w * d, h * d};
}

// ���������ĳ���
float Vector3::Length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// ��һ������
Vector3 Vector3::Normalized() const {
    float length = Length();
    if (length == 0) return Vector3(0, 0, 0); // ���������
    return Vector3(x / length, y / length, z / length);
}


Vector3 Vector3::Lerp(const Vector3& target, float t) const
{
    return Vector3(
        this->x + (target.x - this->x) * t,
        this->y + (target.y - this->y) * t,
        this->z + (target.z - this->z) * t
    );
}