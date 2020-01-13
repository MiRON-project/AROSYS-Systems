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
#include "NavigationVelocityHandler.hh"

#include <iostream>

NavigationVelocityHandler::NavigationVelocityHandler(Smart::InputSubject<CommBasicObjects::CommNavigationVelocity> *subject, const int &prescaleFactor)
:	NavigationVelocityHandlerCore(subject, prescaleFactor)
{
	std::cout << "constructor NavigationVelocityHandler\n";
}
NavigationVelocityHandler::~NavigationVelocityHandler() 
{
	std::cout << "destructor NavigationVelocityHandler\n";
}

void NavigationVelocityHandler::on_NavigationVelocityServiceIn(const CommBasicObjects::CommNavigationVelocity &input)
{
	// implement business logic here
	// (do not use blocking calls here, otherwise this might block the InputPort NavigationVelocityServiceIn)

	// print output
	std::cout << "NavigationVelocity - input = " << input            << std::endl;
	std::cout << "NavigationVelocity - vX = "    << input.get_vX()   << std::endl;
	std::cout << "NavigationVelocity - vY = "    << input.get_vY()   << std::endl;
	std::cout << "NavigationVelocity - omega = " << input.getOmega() << std::endl;

	//const double vLeft  = input.get_vX();
	//const double vRight = input.get_vY();
	//const double omega  = input.get_omega();

	// Get from the port and pass to ComponentWebotsSimulatorCore to be accessible
	COMP->WebotsMutex.acquire();

	COMP->left_velocity  = input.get_vX();
	COMP->right_velocity = input.get_vY(); // not sure if useful, need to be tested
	COMP->turnrate       = input.get_omega();

	COMP->WebotsMutex.release();

}
