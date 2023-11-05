#include "MissionManager.h"
#include "SydioX2Drone.h"
#include "PinholeCamera.h"
#include <iostream>

// Where the magic happens... or the mayhem, depending on the day.
int main() {
    // These numbers are like the secret sauce to camera deliciousness.
    CameraIntrinsics intrinsics(270.0, 320.0, 240.0);

    // Spawn two cameras because one is lonely and zero is just sad.
    PinholeCamera camera1(intrinsics);
    PinholeCamera camera2(intrinsics);

    // Two drones, because the second one is a backup dancer.
    SydioX2Drone drone1(Eigen::Vector3d(5, 2, 1), -20 * M_PI / 180.0, camera1);
    SydioX2Drone drone2(Eigen::Vector3d(8.5, 2.5, 2), 30 * M_PI / 180.0, camera2);

    // Karen called the manager....
    MissionManager missionManager;

    // Let's add our drones, because what's a mission without a squad?
    missionManager.addDrone(drone1);
    missionManager.addDrone(drone2);

    // Pixely things that drones dream about.
    PixelData pixelData1(360, 300);
    PixelData pixelData2(140, 404);

    Eigen::Vector3d objectPosition;

    // The grand moment of mathematical truth!
    if(missionManager.canTriangulatePosition(pixelData1, pixelData2, objectPosition ))
    {
    // Drum roll and... ta-da! The estimated object position.
        std::cout << "Estimated Object Position: " << objectPosition.transpose() << std::endl;
    }

    // Return 0 because we're optimistic like that.
    return 0;
}
