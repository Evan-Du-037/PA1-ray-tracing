#ifndef SPHERE_H
#define SPHERE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>

// Implement functions and add more fields as necessary

class Sphere : public Object3D {
public:
    Sphere() {
        center = Vector3f::ZERO;
        radius = 1.0f;
    }

    Sphere(const Vector3f &center, float radius, Material *material) : Object3D(material) {
        this->center = center;
        this->radius = radius;
    }

    ~Sphere() override = default;

    bool intersect(const Ray &r, Hit &h, float tmin) override {
        Vector3f PO = center - r.getOrigin();
        float PO_len = PO.length();
        float cast = Vector3f::dot(PO, r.getDirection());
        if(cast < tmin) return false;
        float dist = sqrt(PO_len * PO_len - cast * cast);
        if(dist > radius) return false;
        float t = cast - sqrt(radius * radius - dist * dist);
        if(t < tmin) return false;
        Vector3f intersectPoint = r.getOrigin() + r.getDirection() * t;
        return h.safe_set(t, material, intersectPoint - center);
    }

protected:
    Vector3f center;
    float radius;
};


#endif
