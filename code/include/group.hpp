#ifndef GROUP_H
#define GROUP_H


#include "object3d.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include <iostream>
#include <vector>

using std::vector;

// TODO: Implement Group - add data structure to store a list of Object*
class Group : public Object3D {

public:

    Group() {
        numObjects = 0;
    }

    explicit Group (int num_objects) {
        numObjects = num_objects;
        for(int i = 0; i < num_objects; ++i) {
            objects.push_back(nullptr);
        }
    }

    ~Group() override {
        for(Object3D* object: objects) {
            if(object != nullptr) {
                delete object;
            }
        }
    }

    bool intersect(const Ray &r, Hit &h, float tmin) override {
        bool flag = false;
        for(Object3D* object: objects) {
            flag |= object->intersect(r, h, tmin);
        }
        return flag;
    }

    void addObject(int index, Object3D *obj) {
        // objects.insert(objects.begin() + index, obj);
        objects[index] = obj;
    }

    int getGroupSize() {
        return numObjects;
    }

private:
    vector<Object3D*> objects;
    int numObjects;
};

#endif
	
