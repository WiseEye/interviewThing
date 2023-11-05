cmake_minimum_required(VERSION 3.15) # Using a newer version for better features
project(HuntTheTurtle VERSION 1.0.0)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Eigen3 library
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Add executable based on the source files
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
    src/PinholeCamera.cpp
    src/SydioX2Drone.cpp
    src/MissionManager.cpp
    src/RayIntersectionSolver.cpp
)

# Use target_include_directories instead of include_directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link Eigen to your executable
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

# Specify the install rules
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Optionally, enable testing and add tests
enable_testing()
# add_subdirectory(tests) # If you have a tests/ directory
