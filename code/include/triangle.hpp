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
		assert(tmin > 0);
		Matrix3f matrix = Matrix3f(vertices[0]-vertices[1], vertices[0]-vertices[2], ray.getDirection());
		if (fabs(matrix.determinant()) < 1e-6) return false;  // matrix irriversible
		Vector3f result = matrix.inverse() * (vertices[0] - ray.getOrigin());
		float x = result[0];
		float y = result[1];
		float t = result[2];
		if(t < tmin || x > 1 || y > 1 || x < 0 || y < 0 || x+y > 1) {
			return false;
		}
		Vector3f planeNormal = normal;
		if(Vector3f::dot(planeNormal, ray.getOrigin()-vertices[0]) < 0) {
			planeNormal = -planeNormal;
		}
		hit.set(t, material, planeNormal);
		return true;
	}

	Vector3f normal;
	Vector3f vertices[3];
protected:
	constexpr static float eps = 1e-10;
};

#endif //TRIANGLE_H
