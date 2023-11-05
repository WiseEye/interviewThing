#ifndef PIN_HOLE_CAMERA_H
#define PIN_HOLE_CAMERA_H

#include "CameraIntrinsics.h"
#include "BaseCamera.h"

#include <Eigen/Dense>

/**
 * @brief Like the camera on your phone, if your phone was from the 19th century.
 * 
 * In a world of 108MP cameras, this one uses the tried and tested technology of a hole and some math.
 * Vintage chic, mathematical geek.
 */
class PinholeCamera : public GenericCamera<Eigen::Vector3d> {
private:
    CameraIntrinsics intrinsics; ///< The secret sauce that makes the magic happen.

public:
    /**
     * @brief Constructs a camera that squints at the world through a tiny hole.
     * 
     * @param intrinsics The numbers that make the squinting accurate.
     */
    PinholeCamera(const CameraIntrinsics& intrinsics);

    /**
     * @brief Turns those pesky pixel coordinates into a vector. Because why look at images when you can look at vectors?
     * 
     * You give it a dot, it gives you a direction. It's like a magic wand, but for math nerds.
     * 
     * @param pixelData The pixel you're interested in because the rest of the image is just filler.
     * @return Eigen::Vector3d The direction of the pixel's wistful gaze into the abyss.
     */
    Eigen::Vector3d pixelToRay(const PixelData& pixelData) const override;

    /**
     * @brief When you decide those intrinsic numbers could be better and fiddle with them.
     * 
     * Like tuning a guitar, but instead of music, you get a slightly different view of the world.
     * 
     * @param newIntrinsics The new numbers because the old ones just weren't hipster enough.
     */
    void updateIntrinsics(const CameraIntrinsics& newIntrinsics) override;
};

#endif // PIN_HOLE_CAMERA_H
