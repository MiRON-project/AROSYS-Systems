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
#ifndef _PIONEER3DXTASK_HH
#define _PIONEER3DXTASK_HH

#include "Pioneer3DXTaskCore.hh"

#include <webots/Motor.hpp>
#include <webots/Robot.hpp>
#include <webots/Device.hpp>
#include <webots/Node.hpp>

// Pioneer 3-DX specification
#define WHEEL_GAP    0.269  // in meter
#define WHEEL_RADIUS 0.0975 // in meter


class Pioneer3DXTask  : public Pioneer3DXTaskCore
{

private:
	int wb_time_step;
	double motor_max_speed; // in rad/s
	webots::Robot *wb_robot;
	webots::Motor *wb_right_motor;
	webots::Motor *wb_left_motor;


public:
	Pioneer3DXTask(SmartACE::SmartComponent *comp);
	virtual ~Pioneer3DXTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif
