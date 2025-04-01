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
        Vector3f dir = r.getDirection().normalized();
        Vector3f l = center - r.getOrigin();
        
        float tp = Vector3f::dot(l, dir);
        float l2 = l.squaredLength();
        float r2 = radius * radius;
        float d2 = l2 - tp * tp;
    
        if (l2 < r2) {
            float t = tp + sqrt(r2 - d2);
            if (t > tmin && t < h.getT()) {
                Vector3f n = (l - dir * t).normalized();
                h.set(t, material, n);
                return true;
            }
            return false;
        } 
        else if (l2 > r2) {
            if (tp < 0 || d2 > r2) return false; 
    
            float t = tp - sqrt(r2 - d2);
            if (t > tmin && t < h.getT()) {
                Vector3f n = (dir * t - l).normalized();
                h.set(t, material, n);
                return true;
            }
        }
        return false;
    }


protected:
    Vector3f center;
    float radius;
};


#endif
