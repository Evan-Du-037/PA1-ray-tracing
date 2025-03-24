#ifndef CAMERA_H
#define CAMERA_H

#include "ray.hpp"
#include <vecmath.h>
#include <float.h>
#include <cmath>


class Camera {
public:
    Camera(const Vector3f &center, const Vector3f &direction, const Vector3f &up, int imgW, int imgH) {
        this->center = center;
        this->direction = direction.normalized();
        this->horizontal = Vector3f::cross(this->direction, up).normalized();
        this->up = Vector3f::cross(this->horizontal, this->direction);
        this->width = imgW;
        this->height = imgH;
    }

    // Generate rays for each screen-space coordinate
    virtual Ray generateRay(const Vector2f &point) = 0;
    virtual ~Camera() = default;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

protected:
    // Extrinsic parameters
    Vector3f center;
    Vector3f direction;
    Vector3f up;
    Vector3f horizontal;
    // Intrinsic parameters
    int width;
    int height;
};

class PerspectiveCamera : public Camera {
public:
    PerspectiveCamera(const Vector3f &center, const Vector3f &direction,
                        const Vector3f &up, int imgW, int imgH, float angle)
        : Camera(center, direction, up, imgW, imgH), angle(angle) {}

    Ray generateRay(const Vector2f &point) override {
        float normalized_x = point.x() / width - 0.5f;
        float normalized_y = point.y() / height - 0.5f;

        float x_angle = (angle * width / height) * normalized_x;
        float y_angle = angle * normalized_y;

        Vector3f rayDir = (direction + tan(x_angle) * horizontal + tan(y_angle) * up).normalized();

        return Ray(center, rayDir);
    }

    // reference from github
    // Ray generateRay(const Vector2f &point) override {
    //     float f=height/(2*tan(angle/2));
    //     Vector3f dir=Matrix3f(up,horizontal,direction)*Vector3f(point[1]-height/2,point[0]-width/2,f);
    //     return Ray(center,dir.normalized());
    // }

private:
    float angle;
};

#endif //CAMERA_H
