#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "ray.hpp"
#include "hit.hpp"
#include <iostream>

// Implement Shade function that computes Phong introduced in class.
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
        Vector3f N = hit.getNormal().normalized();
        Vector3f L = dirToLight.normalized();
        Vector3f V = -ray.getDirection().normalized();
        Vector3f H = (L + V).normalized();

        // diffuse shade
        float diffuseFactor = std::max(0.0f, Vector3f::dot(N, L));
        Vector3f diffuseShade = diffuseColor * lightColor * diffuseFactor;

        // specular shade
        float specFactor = std::max(0.0f, Vector3f::dot(N, H));
        Vector3f specularShade = specularColor * lightColor * pow(specFactor, shininess);

        // ambient color neglected
        Vector3f shaded = diffuseShade + specularShade;
        return shaded;
    }

protected:
    Vector3f diffuseColor;
    Vector3f specularColor;
    float shininess;
};


#endif // MATERIAL_H
