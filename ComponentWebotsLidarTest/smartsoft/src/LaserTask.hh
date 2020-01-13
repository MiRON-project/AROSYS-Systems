//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef _LASERTASK_HH
#define _LASERTASK_HH

#include "LaserTaskCore.hh"

#include <webots/Robot.hpp>
#include <webots/Lidar.hpp>


// Modifies these parameters for unit consistency
#define M_TO_CM      100.0 // Conversion factor
#define UNIT_FACTOR  100.0 // Value is expressed in 0.01 degree units
#define MEASURE_UNIT 1.0   // From the sensor (1000 for meter, 1 for mm)


class LaserTask  : public LaserTaskCore
{
private:
	int wb_time_step;
	int wb_h_res; // horizontal resolution
	webots::Robot *wb_robot;
	webots::Lidar *wb_lidar;

	unsigned int num_valid_points;
	CommBasicObjects::CommMobileLaserScan scan;

public:
	unsigned long scan_count;
	LaserTask(SmartACE::SmartComponent *comp);
	virtual ~LaserTask();

	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif
