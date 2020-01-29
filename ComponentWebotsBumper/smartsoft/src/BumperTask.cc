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
#include "BumperTask.hh"
#include "ComponentWebotsBumper.hh"

#include "CommBasicObjects/CommBumperState.hh"

#include <iostream>

#include <webots/Device.hpp>
#include <webots/Node.hpp>

BumperTask::BumperTask(SmartACE::SmartComponent *comp) : BumperTaskCore(comp) {
  std::cout << "constructor BumperTask\n";
}
BumperTask::~BumperTask() { std::cout << "destructor BumperTask\n"; }

int BumperTask::on_entry() {
  // do initialization procedures here, which are called once, each time the
  // task is started it is possible to return != 0 (e.g. when initialization
  // fails) then the task is not executed further

  if (!COMP->webotsRobot)
    return -1;

  // get timestep from the world
  webotsTimeStep = COMP->webotsRobot->getBasicTimeStep();

  // connect to the sensor from Webots
  webotsTouchSensor = NULL;
  for (int i = 0; i < COMP->webotsRobot->getNumberOfDevices(); i++) {
    webots::Device *webotsDevice = COMP->webotsRobot->getDeviceByIndex(i);
    if (webotsDevice->getNodeType() ==
        webots::Node::TOUCH_SENSOR) {
      std::string bumperName = webotsDevice->getName();
      webots::TouchSensor *sensor = COMP->webotsRobot->getTouchSensor(bumperName);
      if (sensor->getType() == webots::TouchSensor::BUMPER) {
		  webotsTouchSensor = sensor;
		  webotsTouchSensor->enable(webotsTimeStep);
		  std::cout << "Device #" << i << " called " << bumperName
					<< " is a bumper." << std::endl;
		  break;
      }
    }
  }

  if (!webotsTouchSensor) {
    std::cout << "No Bumper found, no data sent." << std::endl;
    return -1;
  }

  return 0;
}
int BumperTask::on_execute() {
  // this method is called from an outside loop,
  // hence, NEVER use an infinite loop (like "while(1)") here inside!!!
  // also do not use blocking calls which do not result from smartsoft kernel

  if (COMP->webotsRobot->step(webotsTimeStep) != -1 && webotsTouchSensor) {
    CommBasicObjects::CommBumperEventState bumperEventState;
    if (webotsTouchSensor->getValue() == 1.0)
      bumperEventState.setNewState(CommBasicObjects::BumperStateType::BUMPER_PRESSED);
    else
      bumperEventState.setNewState(CommBasicObjects::BumperStateType::BUMPER_NOT_PRESSED);
    // send out bumper state through port
    bumperEventServiceOutPut(bumperEventState);
  } else
    return -1;

  // it is possible to return != 0 (e.g. when the task detects errors), then the
  // outer loop breaks and the task stops
  return 0;
}
int BumperTask::on_exit() {
  // use this method to clean-up resources which are initialized in on_entry()
  // and needs to be freed before the on_execute() can be called again
  delete COMP->webotsRobot;
  return 0;
}
