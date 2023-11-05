#include "PinholeCamera.h"

// Initializing our vintage PinholeCamera - where old school meets high tech.
PinholeCamera::PinholeCamera(const CameraIntrinsics& intrinsics) : intrinsics(intrinsics) {}

// Takes a pixel and dreams about the ray it wants to be when it grows up.
Eigen::Vector3d PinholeCamera::pixelToRay(const PixelData& pixelData) const {
    // Here's where we take those pixels on a trip from Flatland to Spaceland.
    Eigen::Vector2d normalized(
        (pixelData.x - intrinsics.principalPointX) / intrinsics.focalLength,
        (pixelData.y - intrinsics.principalPointY) / intrinsics.focalLength
    );

    // And voila, we've got ourselves a ray! Straight outta the camera, through the pixel, into infinity (and beyond?).
    return Eigen::Vector3d(normalized.x(), normalized.y(), 1.0).normalized();
}

// When you need to update your camera's guts because the world has moved on from 640x480.
void PinholeCamera::updateIntrinsics(const CameraIntrinsics& newIntrinsics) {
    intrinsics = newIntrinsics; // New intrinsics, who dis?
}
