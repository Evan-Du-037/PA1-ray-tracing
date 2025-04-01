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
        if (d2 > r2) return false; 
        float sqrt_discriminant = sqrt(r2 - d2); 
        float t;
        if (l2 < r2) { 
            t = tp + sqrt_discriminant;
        } else {
            if (tp < 0) return false;  
            t = tp - sqrt_discriminant;
        }
        if (t <= tmin || t >= h.getT()) return false;
        Vector3f n = (r.pointAtParameter(t) - center).normalized();
        h.set(t, material, n);
        return true;
    }


protected:
    Vector3f center;
    float radius;
};


#endif
