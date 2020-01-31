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
#include "BaseStateQueryHandler.hh"
#include "ComponentWebotsPioneer3DX.hh"

BaseStateQueryHandler::BaseStateQueryHandler(IQueryServer *server)
:	BaseStateQueryHandlerCore(server)
{

}


void BaseStateQueryHandler::handleQuery(const Smart::QueryIdPtr &id, const CommBasicObjects::CommVoid& request)
{

	CommBasicObjects::CommBaseState answer;

	// implement your query handling logic here and fill in the answer object

	this->server->answer(id, answer);
}
