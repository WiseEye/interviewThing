#ifndef MISSION_MANAGER_H
#define MISSION_MANAGER_H

#include "SydioX2Drone.h"
#include <vector>

/**
 * @brief The all-seeing, all-knowing maestro of the skies... or just a class that thinks it is.
 * 
 * Ever wish you had a control room full of generals staring at maps and pushing little drone models around? 
 * Well, keep wishing, because all you've got is this class and a prayer.
 */
class MissionManager {
private:
    std::vector<SydioX2Drone> drones; ///< The dream team. If by 'dream' you mean 'a list of objects in a computer'.

public:
    /**
     * @brief Adds a drone to your virtual air force. Because who needs friends when you have drones?
     * 
     * Drones are like chips, you can't have just one. So here's a method to add another to your lonely collection.
     * 
     * @param drone The UAV buddy that doesn't judge you for talking to machines.
     */
    void addDrone(const SydioX2Drone& drone);

    /**
     * @brief Does math magic to figure out where things are. It's like GPS, but more nerdy.
     * 
     * Just throw in some pixel data and bam! You'll get a position, give or take a few hundred meters.
     * 
     * @param pixelData1 The first set of data points, because redundancy is key... I guess.
     * @param pixelData2 The second set, because two is better than one, and also it's required.
     * @return Eigen::Vector3d An approximate guess of where your object might be, on a good day.
     */
    bool canTriangulatePosition(const PixelData& pixelData1, const PixelData& pixelData2, Eigen::Vector3d& out_estimate);
};

#endif // MISSION_MANAGER_H
