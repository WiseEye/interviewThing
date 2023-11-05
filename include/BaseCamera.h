#ifndef BASE_CAMERA_H
#define BASE_CAMERA_H

#include "CameraIntrinsics.h"

// Define PixelData using primitive types
struct PixelData {
    int x; // X coordinate
    int y; // Y coordinate
    
    PixelData(int x_, int y_) : x(x_), y(y_) {}
};


template <typename T>
class GenericCamera {
public:
    virtual ~GenericCamera() {}
    virtual T pixelToRay(const PixelData& pixelData) const = 0;
    virtual void updateIntrinsics(const CameraIntrinsics& newIntrinsics) = 0;
};

#endif