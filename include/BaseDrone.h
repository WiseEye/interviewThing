#ifndef BASE_DRONE_H
#define BASE_DRONE_H

#include "CameraIntrinsics.h"
#include "BaseCamera.h"

/**
 * @brief The BaseDrone class: the foundation of our drone armada.
 * 
 * Imagine a world where drones are as customizable as your morning coffee.
 * This is the espresso shot of that world - a basic drone template that's ready to
 * be topped with the frothy milk of your choice of camera and vector type. Just make sure
 * the camera type isn't decaf and the vector type has that extra sugar.
 * 
 * @tparam VectorType A mathematical magician that can perform arithmetic wonders.
 * @tparam CameraType A camera so smart, it probably has a higher IQ than all of us.
 */
template<typename VectorType, typename CameraType>
class BaseDrone {
protected:
    VectorType position; ///< GPS who? This drone knows where it's at without it.
    double heading;      ///< Like a good scout, always knows which way is north (in radians).
    CameraType camera;   ///< The all-seeing eye, turning the world into a canvas of pixels.

public:
    /**
     * @brief Assembles a drone faster than you can say "Autobots, roll out!"
     * 
     * This constructor is the secret sauce to creating a drone that's got its life together -
     * knows where it is, where it's going, and has a camera to take fancy photos along the way.
     * 
     * @param pos Where in the world is Drone San Diego?
     * @param head Which way to the party?
     * @param camera The paparazzi that tracks everything... Kinda like the NSA, but with a better zoom lens.
     */
    BaseDrone(const VectorType& pos, double head, const CameraType& camera)
    : position(pos), heading(head), camera(camera) {}

    /**
     * @brief Camera Getter .... You get it 
     *      * 
     * @return CameraType& The camera template type thing
     */
    CameraType& getCamera() {
        return camera;
    }

    /**
     * @brief Turns pixels into a homing beacon.
     * 
     * It's not magic, it's science - but let's be real, when pixels turn into directional vectors,
     * it's pretty magical.
     * 
     * @param pixelData The secret code to transform 2D into 3D.
     * @return VectorType A vector that's got places to be in the world.
     */
    VectorType getCameraDirectionInWorld(const PixelData& pixelData) const {
        return camera.pixelToRay(pixelData);
    }

    /**
     * @brief The drone's "You Are Here" sticker.
     * 
     * It's like those mall maps, but for drones - and without the tiny food court.
     * 
     * @return VectorType The drone's current global address.
     */
    VectorType getPosition() const {
        return position;
    }

    /**
     * @brief A new heading for new horizons.
     * 
     * Sometimes, even a drone needs a change of direction in life (measured in radians, because degrees are too mainstream).
     * 
     * @param newHeading The compass of change.
     */
    void setHeading(double newHeading) {
        heading = newHeading;
    }

    /**
     * @brief The drone's internal compass.
     * 
     * It's how the drone knows its 'left' from its 'right' in the grand dance of the skies.
     * 
     * @return double The current heading, because "straight on till morning" isn't precise enough.
     */
    double getHeading() const {
        return heading;
    }

    /**
     * @brief Give your camera a new lease on life.
     * 
     * When the camera says, "It's not you, it's me," this is how you give it the makeover it needs.
     * New intrinsics, new attitude.
     * 
     * @param newIntrinsics The makeover kit for camera specs.
     */
    void updateCameraIntrinsics(const CameraIntrinsics& newIntrinsics) {
        camera.updateIntrinsics(newIntrinsics);
    }
};

#endif // BASE_DRONE_H
