#ifndef CAMERA_INTRINSICS_H
#define CAMERA_INTRINSICS_H

/**
 * @brief The secret diary of a camera, detailing its innermost feelings about light and space.
 * 
 * These numbers are like the DNA of camera vision, making sense of the world one pixel at a time.
 * They don't need any fancy math libraries to strut their stuff, but they sure know how to partner with them.
 */
struct CameraIntrinsics {
    double focalLength; ///< The camera's own telescope to the stars.
    double principalPointX; ///< The X marks the spot where the camera says "That's my jam!"
    double principalPointY; ///< The Y where the camera whispers "I see you there."

    /**
     * @brief Creates the camera's ID card because even cameras need to prove they're legit.
     * 
     * It's like a camera's wishlist for Santa: "I want a focal length of this much, and my principal points here and here, please."
     * 
     * @param f The camera's eagle-eye vision range.
     * @param ppX The camera's "You are here" X-coordinate on its internal map.
     * @param ppY The camera's "You are here" Y-coordinate, because X is too mainstream.
     */
    CameraIntrinsics(double f, double ppX, double ppY)
        : focalLength(f), principalPointX(ppX), principalPointY(ppY) {}
};

#endif // CAMERA_INTRINSICS_H
