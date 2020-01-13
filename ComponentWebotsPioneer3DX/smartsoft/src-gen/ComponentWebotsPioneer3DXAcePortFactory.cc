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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#include "ComponentWebotsPioneer3DXAcePortFactory.hh"

// create a static instance of the default AcePortFactory
static ComponentWebotsPioneer3DXAcePortFactory acePortFactory;

ComponentWebotsPioneer3DXAcePortFactory::ComponentWebotsPioneer3DXAcePortFactory()
{  
	componentImpl = 0;
	ComponentWebotsPioneer3DX::instance()->addPortFactory("ACE_SmartSoft", this);
}

ComponentWebotsPioneer3DXAcePortFactory::~ComponentWebotsPioneer3DXAcePortFactory()
{  }

void ComponentWebotsPioneer3DXAcePortFactory::initialize(ComponentWebotsPioneer3DX *component, int argc, char* argv[])
{
	if(component->connections.component.defaultScheduler != "DEFAULT") {
		ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(component->connections.component.defaultScheduler == "FIFO") {
			sched_params.policy(ACE_SCHED_FIFO);
			sched_params.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(component->connections.component.defaultScheduler == "RR") {
			sched_params.policy(ACE_SCHED_RR);
			sched_params.priority(ACE_THR_PRI_RR_MIN);
		}
		// create new instance of the SmartSoft component with customized scheuling parameters 
		componentImpl = new ComponentWebotsPioneer3DXImpl(component->connections.component.name, argc, argv, sched_params);
	} else {
		// create new instance of the SmartSoft component
		componentImpl = new ComponentWebotsPioneer3DXImpl(component->connections.component.name, argc, argv);
	}
}

int ComponentWebotsPioneer3DXAcePortFactory::onStartup()
{
	return componentImpl->startComponentInfrastructure();
}


Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState> * ComponentWebotsPioneer3DXAcePortFactory::createBaseStateAnswerer(const std::string &serviceName)
{
	return new SmartACE::QueryServer<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState>(componentImpl, serviceName);
}

Smart::IPushServerPattern<CommBasicObjects::CommBaseState> * ComponentWebotsPioneer3DXAcePortFactory::createBaseStateServiceOut(const std::string &serviceName)
{
	return new SmartACE::PushServer<CommBasicObjects::CommBaseState>(componentImpl, serviceName);
}

Smart::IEventServerPattern<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState> * ComponentWebotsPioneer3DXAcePortFactory::createBatteryEventServiceOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState>> batteryEventServiceOutEventTestHandler)
{
	return new SmartACE::EventServer<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState>(componentImpl, serviceName, batteryEventServiceOutEventTestHandler);
}

Smart::ISendServerPattern<CommBasicObjects::CommBasePositionUpdate> * ComponentWebotsPioneer3DXAcePortFactory::createLocalizationUpdateServiceIn(const std::string &serviceName)
{
	return new SmartACE::SendServer<CommBasicObjects::CommBasePositionUpdate>(componentImpl, serviceName);
}

Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> * ComponentWebotsPioneer3DXAcePortFactory::createNavigationVelocityServiceIn(const std::string &serviceName)
{
	return new SmartACE::SendServer<CommBasicObjects::CommNavigationVelocity>(componentImpl, serviceName);
}


SmartACE::SmartComponent* ComponentWebotsPioneer3DXAcePortFactory::getComponentImpl()
{
	return componentImpl;
}

int ComponentWebotsPioneer3DXAcePortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	componentImpl->stopComponentInfrastructure(timeoutTime);
	return 0;
}

void ComponentWebotsPioneer3DXAcePortFactory::destroy()
{
	// clean-up component's internally used resources (internally used communication middleware) 
	componentImpl->cleanUpComponentResources();
	delete componentImpl;
}
