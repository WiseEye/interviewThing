#ifndef RAY_INTERSECTION_SOLVER_H
#define RAY_INTERSECTION_SOLVER_H

#include <Eigen/Dense>
#include <stdexcept>

/**
 * @brief The class where lines in 3D space go on a blind date and we find out where they meet.
 *
 * It's like cupid for geometry - sometimes the arrows meet, and sometimes they just pass by like ships in the night.
 */
class RayIntersectionSolver {
public:
    /**
     * @brief Where the magic happens - or doesn't, if the rays are antisocial and parallel.
     * 
     * If geometry class was a rom-com, this function would be the climactic scene where the two leads finally get together.
     *
     * @param pos1 Starting point of ray 1, because every good story needs a beginning.
     * @param dir1 Direction of ray 1, because even rays need life goals.
     * @param pos2 Starting point of ray 2, this one's got a back story too.
     * @param dir2 Direction of ray 2, it's also striving for greatness.
     * @return Eigen::Vector3d The meet-cute location, or throws a tantrum if it's not meant to be.
     */
    static bool estimateIntersection(
        const Eigen::Vector3d& pos1, const Eigen::Vector3d& dir1,
        const Eigen::Vector3d& pos2, const Eigen::Vector3d& dir2,  Eigen::Vector3d& outMidpoint);
};

#endif // RAY_INTERSECTION_SOLVER_H
