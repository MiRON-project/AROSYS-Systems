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
#ifndef _LOCALIZATIONUPDATEHANDLER_CORE_HH
#define _LOCALIZATIONUPDATEHANDLER_CORE_HH

#include <aceSmartSoft.hh>

// include the main input-handler interface
#include "LocalizationUpdateServiceInUpcallInterface.hh"
// include all other input interfaces (if any)

// include all interaction-observer interfaces
#include <LocalizationUpdateHandlerObserverInterface.hh>

class LocalizationUpdateHandlerCore
:	public Smart::InputTaskTrigger<CommBasicObjects::CommBasePositionUpdate>
,	public LocalizationUpdateServiceInUpcallInterface
{
private:
	Smart::StatusCode updateStatus;
	CommBasicObjects::CommBasePositionUpdate lastUpdate;
	
	
	virtual void updateAllCommObjects();
	
	// internal input handling method
	virtual void handle_input(const CommBasicObjects::CommBasePositionUpdate& input) {
		this->updateAllCommObjects();
		// call the input handler method (which has to be implemented in derived classes)
		this->on_LocalizationUpdateServiceIn(input);
		// notify all attached interaction observers
		this->notify_all_interaction_observers();
		// call implementation of base class
		Smart::InputTaskTrigger<CommBasicObjects::CommBasePositionUpdate>::handle_input(input);
	}
	
/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<LocalizationUpdateHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(LocalizationUpdateHandlerObserverInterface *observer);
	void detach_interaction_observer(LocalizationUpdateHandlerObserverInterface *observer);
	
protected:

public:
	LocalizationUpdateHandlerCore(
		Smart::InputSubject<CommBasicObjects::CommBasePositionUpdate> *subject,
		const int &prescaleFactor=1);
	virtual ~LocalizationUpdateHandlerCore();
};
#endif
