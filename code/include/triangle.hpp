#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>
#include <iostream>
using namespace std;

// TODO: implement this class and add more fields as necessary,
class Triangle: public Object3D {
public:
	Triangle() = delete;

    // a b c are three vertex positions of the triangle
	Triangle(const Vector3f& a, const Vector3f& b, const Vector3f& c, Material* m) : Object3D(m) {
		vertices[0] = a;
		vertices[1] = b;
		vertices[2] = c;
		normal = Vector3f::cross(a-b, b-c);
		normal = normal / normal.length();
	}

	bool intersect(const Ray& ray,  Hit& hit , float tmin) override {
        float m = Vector3f::dot(ray.getDirection(), normal);
		bool reverse = false;
		if(m < 0) {
			m = -m;
			reverse = true;
		}
		if(m < eps) {
            return false;
        }
        Vector3f point = vertices[0];
        float t;
        t = Vector3f::dot(point - ray.getOrigin(), normal) / Vector3f::dot(normal, ray.getDirection());
		assert(t >= 0);
        if(t < tmin) {
			return false;
		}
		Vector3f intersectPoint = ray.getOrigin() + t * ray.getDirection();
		// Vector3f _a = vertices[0] - intersectPoint;
		// Vector3f _b = vertices[1] - intersectPoint;
		// Vector3f _c = vertices[2] - intersectPoint;
		// float ab = Vector3f::dot(_a, _b);
		// float ac = Vector3f::dot(_a, _c);
		// float bc = Vector3f::dot(_c, _b);
		// if(ab <= 0 && bc <= 0 && ac <= 0) {
		// 	hit.set(t, material, reverse ? -normal : normal);
		// 	return true;
		// }
		// return false;
		
		Vector3f v0 = vertices[1] - vertices[0];
		Vector3f v1 = vertices[2] - vertices[1];
		Vector3f v2 = vertices[0] - vertices[2];

		Vector3f c0 = Vector3f::cross(v0, intersectPoint - vertices[0]);
		Vector3f c1 = Vector3f::cross(v1, intersectPoint - vertices[1]);
		Vector3f c2 = Vector3f::cross(v2, intersectPoint - vertices[2]);

		if (Vector3f::dot(c0, normal) >= 0 &&
			Vector3f::dot(c1, normal) >= 0 &&
			Vector3f::dot(c2, normal) >= 0) {
			hit.set(t, material, reverse ? -normal : normal);
			return true;
		}
		return false;
	}

	Vector3f normal;
	Vector3f vertices[3];
protected:
	constexpr static float eps = 1e-10;
};

#endif //TRIANGLE_H
