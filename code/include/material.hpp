#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "ray.hpp"
#include "hit.hpp"
#include <iostream>

// TODO: Implement Shade function that computes Phong introduced in class.
class Material {
public:

    explicit Material(const Vector3f &d_color, const Vector3f &s_color = Vector3f::ZERO, float s = 0) :
            diffuseColor(d_color), specularColor(s_color), shininess(s) {

    }

    virtual ~Material() = default;

    virtual Vector3f getDiffuseColor() const {
        return diffuseColor;
    }


    Vector3f Shade(const Ray &ray, const Hit &hit,
                   const Vector3f &dirToLight, const Vector3f &lightColor) {
        // Vector3f shaded = Vector3f::ZERO;
        Vector3f L = -ray.getDirection() + dirToLight;
        L = L / L.length();
        Vector3f specularShade = specularColor * lightColor * pow(std::max(0.0f, Vector3f::dot(L, hit.getNormal())), shininess);
        Vector3f diffuseShade = diffuseColor * lightColor * std::max(0.0f, Vector3f::dot(-ray.getDirection(), hit.getNormal()));
        Vector3f shaded = specularColor + diffuseShade;
        return shaded;
    }

protected:
    Vector3f diffuseColor;
    Vector3f specularColor;
    float shininess;
};


#endif // MATERIAL_H
