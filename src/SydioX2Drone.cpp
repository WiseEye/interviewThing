#include "SydioX2Drone.h"

// It's like giving a pacifist a paintball gun and saying, "Have at it!"
Eigen::Vector3d SydioX2Drone::getCameraDirectionInWorld(const PixelData& pixelData) const {
    // Here we coax a ray out of the camera, like convincing a Skydio drone that reconnaissance is just
    // "aggressive sightseeing."
    Eigen::Vector3d ray = camera.pixelToRay(pixelData);

    // This rotation matrix is like whispering sweet nothings to the drone, persuading it to face
    // the music (or, you know, the direction we actually want it to look).
    Eigen::Matrix3d rotationMatrix;
    rotationMatrix << cos(heading), -sin(heading), 0,  // "Just pivot gently, no need for dramatics," we say to our non-combatant friend.
                      sin(heading),  cos(heading), 0,  // It's like ballet, but with rotors and a no-fly zone.
                      0,             0,            1;  // Z-axis, the peaceful protester of the matrix world - doesn't get involved.

    // After the peaceful persuasion, our camera ray is aligned with world coordinates,
    // as on-point as a precision strike, minus the strike part because Skydio is all about that non-weaponized life... 
    Eigen::Vector3d worldRay = rotationMatrix * ray;

    // There we have it, our drone is now ready to stare down any target with the intensity
    // of a hawk eyeing a mouse, except this hawk's just here to take pictures and fly home.
    return worldRay;
}
