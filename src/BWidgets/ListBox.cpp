/* ListBox.cpp
 * Copyright (C) 2018  Sven Jähnichen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "ListBox.hpp"

namespace BWidgets
{
ListBox::ListBox () : ListBox (0.0, 0.0, 0.0, 0.0, "choicebox", {""}, 1.0) {}

ListBox::ListBox (const double x, const double y, const double width, const double height, const std::string& name,
					  std::vector<std::string> items, double preselection) :
		ChoiceBox (x, y, width, height, name, items, preselection)

{
	if (items.empty ()) listTop = 0.0;
	else listTop = 1.0;

	upButton.setCallbackFunction (BEvents::EventType::BUTTON_PRESS_EVENT, ListBox::handleButtonClicked);
	downButton.setCallbackFunction (BEvents::EventType::BUTTON_PRESS_EVENT, ListBox::handleButtonClicked);
}

ListBox::ListBox (const ListBox& that) : ChoiceBox (that), listTop (that.listTop) {}

ListBox::~ListBox () {}

ListBox& ListBox::operator= (const ListBox& that)
{
	listTop = that.listTop;

	Widget::operator= (that);
	return *this;
}

void ListBox::setTop (const double top)
{
	double oldtop = listTop;

	if (items.empty ()) listTop = 0.0;

	else
	{
		size_t size = items.size ();
		int topint = int (top + 0.5);
		if (topint <= 0) listTop = 1.0;
		else if (topint <= size) listTop = topint;
		else listTop = size;

		double lines = getLines ();
		if ((getBottom () > size) && (size - lines > 1)) listTop = size - lines + 1;
	}

	if (oldtop != listTop) update ();
}

double ListBox::getTop () const {return listTop;}

void ListBox::handleButtonClicked (BEvents::Event* event)
{
	if (event && (event->getEventType () == BEvents::EventType::BUTTON_PRESS_EVENT) && event->getWidget ())
	{
		BEvents::PointerEvent* ev = (BEvents::PointerEvent*) event;
		Button* w = (Button*) ev->getWidget ();
		if (w->getParent ())
		{
			ListBox* p = (ListBox*) w->getParent ();
			if (p->getParent ())
			{
				if (w == (Button*) &(p->upButton)) p->setTop (p->getTop () - 1);
				if (w == (Button*) &(p->downButton)) p->setTop (p->getTop () + 1);
			}
		}
	}
}

void ListBox::updateLabels ()
{
	validateLabels ();

	double x0 = getXOffset ();
	double y0 = getYOffset ();
	double width = getEffectiveWidth ();
	double height = getEffectiveHeight ();
	double labelHeight = (height >= 2 * BWIDGETS_DEFAULT_CHOICEBOX_BUTTON_HEIGHT ? height - 2 * BWIDGETS_DEFAULT_CHOICEBOX_BUTTON_HEIGHT : 0);
	double upButtonHeight = (height >= BWIDGETS_DEFAULT_CHOICEBOX_BUTTON_HEIGHT ? BWIDGETS_DEFAULT_CHOICEBOX_BUTTON_HEIGHT : height);
	double lines = floor (labelHeight / BWIDGETS_DEFAULT_CHOICEBOX_LABEL_HEIGHT) + 1;

	for (int i = 0; i < labels.size (); ++i)
	{
		if ((i + 1 >= listTop) && (i + 1 < listTop + lines))
		{
			labels[i]->moveTo (x0 + BWIDGETS_DEFAULT_CHOICEBOX_PADDING, y0 + upButtonHeight + (i + 1 - listTop) * BWIDGETS_DEFAULT_CHOICEBOX_LABEL_HEIGHT);
			labels[i]->setWidth (width > 2 * BWIDGETS_DEFAULT_CHOICEBOX_PADDING ? width - 2 * BWIDGETS_DEFAULT_CHOICEBOX_PADDING : 0);

			if (i + 1 == (int) (getBottom () + 0.5)) labels[i]->setHeight (labelHeight - (lines - 1) * BWIDGETS_DEFAULT_CHOICEBOX_LABEL_HEIGHT);
			else labels[i]->setHeight (BWIDGETS_DEFAULT_CHOICEBOX_LABEL_HEIGHT);

			if (i + 1 == (int) (getValue () + 0.5)) labels[i]->setState (BColors::ACTIVE);
			else labels[i]->setState (BColors::NORMAL);

			labels[i]->show ();
		}
		else
		{
			labels[i]->hide ();
		}

	}
}

double ListBox::getLines ()
{
	double height = getEffectiveHeight ();
	double labelHeight = (height >= 2 * BWIDGETS_DEFAULT_CHOICEBOX_BUTTON_HEIGHT ? height - 2 * BWIDGETS_DEFAULT_CHOICEBOX_BUTTON_HEIGHT : 0);
	double lines = floor (labelHeight / BWIDGETS_DEFAULT_CHOICEBOX_LABEL_HEIGHT) + 1;
	return lines;
}

}
