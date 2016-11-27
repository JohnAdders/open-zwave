//-----------------------------------------------------------------------------
//
//	Schedule.cpp
//
//	Implementation of the Z-Wave COMMAND_CLASS_SCHEDULE
//
//	Copyright (c) 2016 John Adcock <adcockj@users.sourceforge.net>
//
//	SOFTWARE NOTICE AND LICENSE
//
//	This file is part of OpenZWave.
//
//	OpenZWave is free software: you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published
//	by the Free Software Foundation, either version 3 of the License,
//	or (at your option) any later version.
//
//	OpenZWave is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with OpenZWave.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------------

#include "command_classes/CommandClasses.h"
#include "command_classes/Schedule.h"
#include "Defs.h"
#include "Msg.h"
#include "Driver.h"
#include "Node.h"
#include "platform/Log.h"

#include "tinyxml.h"

using namespace OpenZWave;

//-----------------------------------------------------------------------------
// <Schedule::ReadXML>
// Read the saved change-counter value
//-----------------------------------------------------------------------------
void Schedule::ReadXML
(
	TiXmlElement const* _ccElement
)
{
	CommandClass::ReadXML( _ccElement );

	int intVal;
	if( TIXML_SUCCESS == _ccElement->QueryIntAttribute( "change_counter", &intVal ) )
	{
		m_changeCounter = (uint8)intVal;
	}
}

//-----------------------------------------------------------------------------
// <Schedule::WriteXML>
// Write the change-counter value
//-----------------------------------------------------------------------------
void Schedule::WriteXML
(
	TiXmlElement* _ccElement
)
{
	CommandClass::WriteXML( _ccElement );

	char str[8];
	snprintf( str, 8, "%d", m_changeCounter );
	_ccElement->SetAttribute( "change_counter", str );
}

//-----------------------------------------------------------------------------
// <Schedule::RequestState>
// Request current state from the device
//-----------------------------------------------------------------------------
bool Schedule::RequestState
(
	uint32 const _requestFlags,
	uint8 const _instance,
	Driver::MsgQueue const _queue
)
{
	return false;
}

//-----------------------------------------------------------------------------
// <Schedule::RequestValue>
// Request current value from the device
//-----------------------------------------------------------------------------
bool Schedule::RequestValue
(
	uint32 const _requestFlags,
	uint8 const _dummy1,	// = 0 (not used)
	uint8 const _instance,
	Driver::MsgQueue const _queue
)
{
	return true;
}

//-----------------------------------------------------------------------------
// <Schedule::HandleMsg>
// Handle a message from the Z-Wave network
//-----------------------------------------------------------------------------
bool Schedule::HandleMsg
(
	uint8 const* _data,
	uint32 const _length,
	uint32 const _instance	// = 1
)
{
	return false;
}

//-----------------------------------------------------------------------------
// <Schedule::SetValue>
// Set a value in the device
//-----------------------------------------------------------------------------
bool Schedule::SetValue
(
	Value const& _value
)
{
	return true;
}

//-----------------------------------------------------------------------------
// <Schedule::CreateVars>
// Create the values managed by this command class
//-----------------------------------------------------------------------------
void Schedule::CreateVars
(
	uint8 const _instance
)
{
}

