#ifndef PLANE_H
#define PLANE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>

// TODO: Implement Plane representing an infinite plane
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
        Vector3f P = normal * d;
        Vector3f planeNormal = normal;
        Vector3f OP = P - r.getOrigin();
        if(Vector3f::dot(OP, planeNormal) > 0) {
            planeNormal = -planeNormal;
        }
        
        float m = Vector3f::dot(planeNormal, r.getDirection().normalized());
        if(abs(m) < eps) return false;  // parallel
        float t = Vector3f::dot(OP, planeNormal) / m;
        if(t >= tmin) {
            h.set(t, material, planeNormal);
            return true;
        }
        return false;
    }

protected:
    Vector3f normal;
    float d;
    constexpr static float eps = 1e-10;
};

#endif //PLANE_H
		

