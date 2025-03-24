#ifndef SPHERE_H
#define SPHERE_H

#include "object3d.hpp"
#include <vecmath.h>
#include <cmath>

// TODO: Implement functions and add more fields as necessary

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
        Vector3f oc = r.getOrigin() - center;
        Vector3f dir = r.getDirection();
    
        float a = Vector3f::dot(dir, dir);  // = 1 if dir is normalized
        float b = 2.0f * Vector3f::dot(dir, oc);
        float c = Vector3f::dot(oc, oc) - radius * radius;
    
        float discriminant = b * b - 4 * a * c;
    
        if (discriminant < 0) return false;
    
        float sqrtD = sqrt(discriminant);
        float t1 = (-b - sqrtD) / (2.0f * a);
        float t2 = (-b + sqrtD) / (2.0f * a);
    
        // 选择满足条件的最小 t
        float t;
        if (t1 >= tmin) {
            t = t1;
        } else if (t2 >= tmin) {
            t = t2;
        } else {
            return false;  // 两个交点都在 tmin 左边
        }
    
        Vector3f point = r.pointAtParameter(t);
        Vector3f normal = (point - center).normalized();
        h.safe_set(t, material, normal);
        return true;
    }

protected:
    Vector3f center;
    float radius;
};


#endif
