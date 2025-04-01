#ifndef PLANE_H
#define PLANE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>

// Implement Plane representing an infinite plane
// function: ax+by+cz=d
// choose your representation , add more fields and fill in the functions

class Plane : public Object3D {
public:
    Plane() = delete;

    Plane(const Vector3f &normal, float d, Material *m) : Object3D(m) {
        this->normal = normal.normalized();
        this->d = d;
    }

    ~Plane() override = default;

    bool intersect(const Ray &r, Hit &h, float tmin) override {
        assert(tmin >= 0);
		// find the intersection point with the plane first
        Vector3f P = d * normal;
        Vector3f planeNormal = normal;
        Vector3f OP = P - r.getOrigin();
		float numerator = Vector3f::dot(OP, planeNormal);
        if(numerator > 0) {
            planeNormal = -planeNormal;
			numerator = -numerator;
        }
        
        float denominator = Vector3f::dot(planeNormal, r.getDirection());
        if(abs(denominator) < eps) return false;  // parallel
        float t = numerator / denominator;
        if(t >= tmin) {
            return h.safe_set(t, material, planeNormal);
        }
        return false;
    }

protected:
    Vector3f normal;
    float d;
    
};

#endif //PLANE_H
		

