#include "MissionManager.h"
#include "RayIntersectionSolver.h"

#include <iostream>  

// Add a drone to the party. It's not fun without friends.
void MissionManager::addDrone(const SydioX2Drone& drone) {
    drones.push_back(drone); // More the merrier!
}

// The mystical art of finding where in the world is Carmen Sandiego... or just a regular object.
bool MissionManager::canTriangulatePosition(const PixelData& pixelData1, const PixelData& pixelData2, Eigen::Vector3d& out_estimate) {
    // If there aren't two drones, then we're basically trying to clap with one hand.
    if (drones.size() < 2) {
        throw std::runtime_error("Need at least two drones to triangulate. It's like trying to high-five with one hand!");
    }

    // Time is money, and I've got neither, so let's just assume the first two drones are the ones we're after.
    // In a perfect world you could find the 2 drones with sensors that had overlapping cones that model their
    //senor but like... im not writing all that 
    const SydioX2Drone& drone1 = drones[0];
    const SydioX2Drone& drone2 = drones[1];

    // These drones are going to spit out vectors like they're in a geometry rap battle.
    Eigen::Vector3d dir1 = drone1.getCameraDirectionInWorld(pixelData1);
    Eigen::Vector3d dir2 = drone2.getCameraDirectionInWorld(pixelData2);

    // Snagging their locations. It's like Pokemon Go, but you're always finding drones.
    Eigen::Vector3d pos1 = drone1.getPosition();
    Eigen::Vector3d pos2 = drone2.getPosition();

    //  Use RayIntersectionSolver, because who has time to do things manually?
    bool canEstimate = RayIntersectionSolver::estimateIntersection(pos1, dir1, pos2, dir2, out_estimate);

    if (!canEstimate)
    {
        std::cout << "could not generate estimate of ray intersection... Bruh why" << std::endl;
        return false;
    }
    
    return true;
}
