#ifndef SYDIO_X2_DRONE_H
#define SYDIO_X2_DRONE_H

#include "BaseDrone.h"
#include "PinholeCamera.h"

/**
 * @brief The SydioX2Drone, because who needs weapons when you've got killer looks and a brainy camera?
 *
 * This drone is the pacifist in a world of combat UAVs, proving that you can achieve a lot without dropping anything... except data packets.
 */
class SydioX2Drone : public BaseDrone<Eigen::Vector3d, PinholeCamera> {
public:
    /**
     * @brief Constructs a SydioX2Drone, which is like the James Bond of drones - suave, sophisticated, and surprisingly non-lethal.
     * 
     * @param pos The undercover position in the world of coordinates - shaken, not stirred.
     * @param head The heading, because every drone needs to know its direction in life.
     * @param camera The PinholeCamera, for when you need to spy on... I mean, observe the world with precision.
     */
    SydioX2Drone(const Eigen::Vector3d& pos, double head, const PinholeCamera& camera)
        : BaseDrone<Eigen::Vector3d, PinholeCamera>(pos, head, camera) {}

    /**
     * @brief Get the direction the camera's pointing in the world, because even drones need a point of view.
     * 
     * @param pixelData The PixelData that helps the drone make sense of the visual world.
     * @return Eigen::Vector3d The direction vector where the drone is pointing - no lasers, just math.
     */
    Eigen::Vector3d getCameraDirectionInWorld(const PixelData& pixelData) const ;
};

#endif // SYDIO_X2_DRONE_H
