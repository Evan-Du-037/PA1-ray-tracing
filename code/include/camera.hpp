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

// TODO: Implement Perspective camera
// You can add new functions or variables whenever needed.

// class PerspectiveCamera : public Camera {

// public:
//     PerspectiveCamera(const Vector3f &center, const Vector3f &direction,
//             const Vector3f &up, int imgW, int imgH, float angle) : Camera(center, direction, up, imgW, imgH) {
//         // angle is in radian.
//         up_bias = 1;
//         horizontal_bias = 1;
//     }

//     Ray generateRay(const Vector2f &point) override {
//         float x = point[0];
//         float y = point[1];
//         float center_x = width / 2.0f;
//         float center_y = height / 2.0f;
//         float x_bias = x - center_x;
//         float y_bias = y - center_y;
//         Vector3f rayOrigin = center + up * y_bias + horizontal * x_bias;
//         Vector3f rayDirection = direction;
//         return Ray(rayOrigin, rayDirection);
//     }
// protected:

//     float up_bias;
//     float horizontal_bias;

// };


class PerspectiveCamera : public Camera {
public:
    PerspectiveCamera(const Vector3f &center, const Vector3f &direction,
                        const Vector3f &up, int imgW, int imgH, float angle)
        : Camera(center, direction, up, imgW, imgH), angle(angle) {}

    Ray generateRay(const Vector2f &point) override {
        // 像素坐标 -> [-0.5, 0.5]
        float normalized_x = (point.x() / width) - 0.5f;
        float normalized_y = 0.5f - (point.y() / height); // y轴反向

        // 宽高比调整
        float aspect_ratio = float(width) / height;
        normalized_x *= aspect_ratio;

        // 焦距，根据视角计算
        float image_plane_height = 2.0f * tan(angle / 2.0f);
        float focal_length = 1.0f / tan(angle / 2.0f);  // 简洁起见：焦距设为 1，或随意放缩也可

        // 图像平面上的点对应的方向
        Vector3f ray_dir = (focal_length * direction + normalized_x * horizontal + normalized_y * up).normalized();
        // Vector3f newCenter = center - (point.x() - width / 2) * horizontal - (point.y() - height / 2) * up;
        return Ray(center, ray_dir);
    }

private:
    float angle;
};

#endif //CAMERA_H
