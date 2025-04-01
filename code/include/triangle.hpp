#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>
#include <iostream>
using namespace std;

// implement this class and add more fields as necessary,
class Triangle: public Object3D {
public:
	Triangle() = delete;

    // a b c are three vertex positions of the triangle
	Triangle(const Vector3f& a, const Vector3f& b, const Vector3f& c, Material* m) : Object3D(m) {
		vertices[0] = a;
		vertices[1] = b;
		vertices[2] = c;
		normal = Vector3f::cross(a-b, b-c).normalized();
	}

	bool intersect(const Ray& ray,  Hit& hit , float tmin) override {
		Matrix3f matrix = Matrix3f(vertices[0]-vertices[1], vertices[0]-vertices[2], ray.getDirection());
		float detM = matrix.determinant();
		if (fabs(detM) < eps) return false; // 确保矩阵可逆

		// Cramer’s Rule
		Matrix3f M1(vertices[0] - ray.getOrigin(), vertices[0] - vertices[2], ray.getDirection());
		Matrix3f M2(vertices[0] - vertices[1], vertices[0] - ray.getOrigin(), ray.getDirection());
		Matrix3f M3(vertices[0] - vertices[1], vertices[0] - vertices[2], vertices[0] - ray.getOrigin());

		float x = M1.determinant() / detM;
		float y = M2.determinant() / detM;
		float t = M3.determinant() / detM;

		// original approach
		// if (fabs(matrix.determinant()) < eps) return false;  // matrix irriversible
		// Vector3f result = matrix.inverse() * (vertices[0] - ray.getOrigin());
		// float x = result[0];
		// float y = result[1];
		// float t = result[2];

		if(t < tmin || x > 1 || y > 1 || x < 0 || y < 0 || x+y > 1) {
			return false;
		}
		Vector3f planeNormal = normal;
		if(Vector3f::dot(planeNormal, ray.getOrigin()-vertices[0]) < 0) {
			planeNormal = -planeNormal;
		}
		return hit.safe_set(t, material, planeNormal);
	}

	Vector3f normal;
	Vector3f vertices[3];

};

#endif //TRIANGLE_H
