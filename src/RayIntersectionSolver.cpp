#include "RayIntersectionSolver.h"

#include <iostream>  // Include this at the top of your file

// Where the magic happens - finding where two hopeful rays might awkwardly bump into each other.
bool RayIntersectionSolver::estimateIntersection(
    const Eigen::Vector3d& pos1, const Eigen::Vector3d& dir1,
    const Eigen::Vector3d& pos2, const Eigen::Vector3d& dir2,  Eigen::Vector3d& outMidpoint) {

    // Normalize the directions because even rays need to straighten out their lives.
    Eigen::Vector3d dir1Normalized = dir1.normalized();
    Eigen::Vector3d dir2Normalized = dir2.normalized();

    // Cross product, because rays have a complex relationship.
    Eigen::Vector3d crossProd = dir1Normalized.cross(dir2Normalized);

    // Rays too parallel? They've agreed to never meet. Awkward.
    if (crossProd.norm() < 1e-6) { // ok yes magic numbers but like ...  this is fine
        std::cout << "Rays are parallel and do not intersect. It's not me, it's Euclidean geometry" << std::endl;
        return false;
    }

    // Matrix A - the council that decides the fate of our two heroes.
    Eigen::Matrix3d A;
    A << dir1Normalized, -dir2Normalized, crossProd;
    Eigen::Vector3d b = pos2 - pos1; // The difference of their starting points, because every ray has a past.

    // The grand solution - where algebra meets destiny.... Least square stuff is done here
    Eigen::Vector3d X = A.colPivHouseholderQr().solve(b);

    // The point where our rays agree to meet - it's a date!
    outMidpoint = pos1 + X(0) * dir1Normalized;


    return true; // And they lived happily ever after, at a single point in space.... sorta
}
