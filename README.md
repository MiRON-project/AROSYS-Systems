# AROSYS

[![Build Status](https://travis-ci.com/cyberbotics/AROSYS.svg?token=F34e6fzg7bnX1UAbdRpa&branch=master)](https://travis-ci.com/cyberbotics/AROSYS)
[![Safety](https://img.shields.io/badge/safety-secure-brightgreen.svg)](https://app.gitguardian.com)
[![Software License](https://img.shields.io/badge/license-Apache--2.0-brightgreen.svg)](LICENSE) 

## Systems
The following systems are examples to be able to test new components.

### SystemLaserObstacleAvoidTiagoWebotsSimulator
This system is a copy of the `SystemLaserObstacleAvoidTiagoGazeboSimulator` in order to show that the new components developed to use Webots simulator are working since the robot has the same behavior as expected.

A [TIAGo Iron](https://cyberbotics.com/doc/guide/tiago-iron) is used with a lidar that seems to be a [Sick TIM150-3010300](https://www.sick.com/ca/en/detection-and-ranging-solutions/2d-lidar-sensors/tim1xx/tim150-3010300/p/p595144?ff_data=JmZmX2lkPXA1OTUxNDQmZmZfbWFzdGVySWQ9cDU5NTE0NCZmZl90aXRsZT1UaU0xNTAtMzAxMDMwMCZmZl9xdWVyeT0mZmZfcG9zPTImZmZfb3JpZ1Bvcz0yJmZmX3BhZ2U9MSZmZl9wYWdlU2l6ZT0yNCZmZl9vcmlnUGFnZVNpemU9MjQmZmZfc2ltaT05MS4w) with a range of 10 meters and an aperture angle of 200 degree.

### SystemLaserObstacleAvoidP3dxWebotsSimulator
This system is a copy of the `SystemLaserObstacleAvoidP3dxPlayerStageSimulator` in order to show that the new components developed to use Webots simulator are working since the robot has the same behavior as expected.

A [Pioneer 3-DX](https://cyberbotics.com/doc/guide/pioneer-3dx) is used with a lidar that seems to be a [Sick TIM150-3010300](https://www.sick.com/ca/en/detection-and-ranging-solutions/2d-lidar-sensors/tim1xx/tim150-3010300/p/p595144?ff_data=JmZmX2lkPXA1OTUxNDQmZmZfbWFzdGVySWQ9cDU5NTE0NCZmZl90aXRsZT1UaU0xNTAtMzAxMDMwMCZmZl9xdWVyeT0mZmZfcG9zPTImZmZfb3JpZ1Bvcz0yJmZmX3BhZ2U9MSZmZl9wYWdlU2l6ZT0yNCZmZl9vcmlnUGFnZVNpemU9MjQmZmZfc2ltaT05MS4w) with a range of 10 meters and an aperture angle of 180 degree.

### SystemWebotsPioneer3DXNavigation
This system shows a complete example of communication between a [lidar sensor](https://cyberbotics.com/doc/guide/lidar-sensors) (`ComponentWebotsLidar`) used by a [Pioneer 3-DX](https://cyberbotics.com/doc/guide/pioneer-3dx) robot (`ComponentWebotsPioneer3DX`) to navigate in a square arena filled with obstacles. It works with the new components developped to use Webots.

### SystemWebotsRobotino3Navigation
This system shows a complete example of communication between a [lidar sensor](https://cyberbotics.com/doc/guide/lidar-sensors) (`ComponentWebotsLidar`) used by a [Robotino 3](https://cyberbotics.com/doc/guide/robotino3) robot (`ComponentWebotsRobotino3`) to navigate in a square arena filled with obstacles. It works with the new components developped to use Webots.

### SystemWebotsTiagoNavigation
This system is a copy of the `SystemTiagoNavigation` in order to show that the new components developed to use Webots simulator are working since the robot has the same behavior as expected.
