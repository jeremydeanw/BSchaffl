/* B.Schaffl
 * MIDI Pattern Delay Plugin
 *
 * Copyright (C) 2018 - 2020 by Sven Jähnichen
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef URIDS_HPP_
#define URIDS_HPP_

#include <lv2/lv2plug.in/ns/lv2core/lv2.h>
#include <lv2/lv2plug.in/ns/ext/atom/util.h>
#include <lv2/lv2plug.in/ns/ext/urid/urid.h>
#include <lv2/lv2plug.in/ns/ext/time/time.h>
#include <lv2/lv2plug.in/ns/ext/midi/midi.h>
#include "definitions.hpp"

struct BSchafflURIs
{
	LV2_URID atom_Float;
	LV2_URID atom_Double;
	LV2_URID atom_Int;
	LV2_URID atom_Long;
	LV2_URID atom_String;
	LV2_URID atom_Object;
	LV2_URID atom_Blank;
	LV2_URID atom_eventTransfer;
	LV2_URID atom_Vector;
	LV2_URID time_Position;
	LV2_URID time_bar;
	LV2_URID time_barBeat;
	LV2_URID time_beatsPerMinute;
	LV2_URID time_beatsPerBar;
	LV2_URID time_beatUnit;
	LV2_URID time_speed;
	LV2_URID midi_Event;
	LV2_URID bschaffl_uiOn;
	LV2_URID bschaffl_uiOff;
	LV2_URID bschaffl_statusEvent;
	LV2_URID bschaffl_step;
	LV2_URID bschaffl_latency;
	LV2_URID bschaffl_rate;
	LV2_URID bschaffl_shapeEvent;
	LV2_URID bschaffl_shapeData;
	LV2_URID notify_event;
	LV2_URID notify_key;
	LV2_URID notify_messageEvent;
	LV2_URID notify_message;
	LV2_URID bschaffl_controllerEvent;
	LV2_URID bschaffl_controllerNr;
	LV2_URID bschaffl_controllerValue;
	LV2_URID bschaffl_controllers;
	LV2_URID bschaffl_sharedDataLinkEvent;
	LV2_URID bschaffl_sharedDataNr;
};

void getURIs (LV2_URID_Map* m, BSchafflURIs* uris)
{
	uris->atom_Float = m->map(m->handle, LV2_ATOM__Float);
	uris->atom_Double = m->map(m->handle, LV2_ATOM__Double);
	uris->atom_Int = m->map(m->handle, LV2_ATOM__Int);
	uris->atom_Long = m->map(m->handle, LV2_ATOM__Long);
	uris->atom_String = m->map(m->handle, LV2_ATOM__String);
	uris->atom_Object = m->map(m->handle, LV2_ATOM__Object);
	uris->atom_Blank = m->map(m->handle, LV2_ATOM__Blank);
	uris->atom_eventTransfer = m->map(m->handle, LV2_ATOM__eventTransfer);
	uris->atom_Vector = m->map(m->handle, LV2_ATOM__Vector);
	uris->time_Position = m->map(m->handle, LV2_TIME__Position);
	uris->time_bar = m->map(m->handle, LV2_TIME__bar);
	uris->time_barBeat = m->map(m->handle, LV2_TIME__barBeat);
	uris->time_beatsPerMinute = m->map(m->handle, LV2_TIME__beatsPerMinute);
	uris->time_beatUnit = m->map(m->handle, LV2_TIME__beatUnit);
	uris->time_beatsPerBar = m->map(m->handle, LV2_TIME__beatsPerBar);
	uris->time_speed = m->map(m->handle, LV2_TIME__speed);
	uris->midi_Event = m->map(m->handle, LV2_MIDI__MidiEvent);
	uris->bschaffl_uiOn = m->map(m->handle, BSCHAFFL_URI "#BSchafflUiOn");
	uris->bschaffl_uiOff = m->map(m->handle, BSCHAFFL_URI "#BSchafflUiOff");
	uris->bschaffl_statusEvent = m->map(m->handle, BSCHAFFL_URI "#BSchafflStatusEvent");
	uris->bschaffl_step = m->map(m->handle, BSCHAFFL_URI "#BSchafflStep");
	uris->bschaffl_latency = m->map(m->handle, BSCHAFFL_URI "#BSchafflLatency");
	uris->bschaffl_rate = m->map(m->handle, BSCHAFFL_URI "#BSchafflRate");
	uris->bschaffl_shapeEvent = m->map(m->handle, BSCHAFFL_URI "#bschafflShapeEvent");
	uris->bschaffl_shapeData = m->map(m->handle, BSCHAFFL_URI "#bschafflShapeData");
	uris->notify_event = m->map(m->handle, BSCHAFFL_URI "#NOTIFYev");
	uris->notify_key = m->map(m->handle, BSCHAFFL_URI "#NOTIFYkey");
	uris->notify_messageEvent = m->map(m->handle, BSCHAFFL_URI "#NOTIFYmessageEvent");
	uris->notify_message = m->map(m->handle, BSCHAFFL_URI "#NOTIFYmessage");
	uris->bschaffl_controllerEvent = m->map(m->handle, BSCHAFFL_URI "#BSchafflControllerEvent");
	uris->bschaffl_controllerNr = m->map(m->handle, BSCHAFFL_URI "#BSchafflControllerNr");
	uris->bschaffl_controllerValue = m->map(m->handle, BSCHAFFL_URI "#BSchafflControllerValue");
	uris->bschaffl_controllers = m->map(m->handle, BSCHAFFL_URI "#BSchafflControllers");
	uris->bschaffl_sharedDataLinkEvent = m->map(m->handle, BSCHAFFL_URI "#BSchafflSharedDataLinkEvent");
	uris->bschaffl_sharedDataNr = m->map(m->handle, BSCHAFFL_URI "#BSchafflSharedDataNr");
}

#endif /* URIDS_HPP_ */
