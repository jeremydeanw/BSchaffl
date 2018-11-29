/* DrawingSurface.cpp
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

#include "DrawingSurface.hpp"

namespace BWidgets
{
DrawingSurface::DrawingSurface () : DrawingSurface (0.0, 0.0, BWIDGETS_DEFAULT_WIDTH, BWIDGETS_DEFAULT_HEIGHT, "drawingsurface") {}

DrawingSurface::DrawingSurface (const double x, const double y, const double width, const double height, const std::string& name) :
		Widget (x, y, width, height, name)
{
	drawingSurface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, getEffectiveWidth (), getEffectiveHeight ());
}

DrawingSurface::DrawingSurface (const DrawingSurface& that) :
		Widget (that)
{
	drawingSurface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, getEffectiveWidth (), getEffectiveHeight ());
	//TODO copy surface data
}

DrawingSurface::~DrawingSurface ()
{
	cairo_surface_destroy (drawingSurface);
}

DrawingSurface& DrawingSurface::operator= (const DrawingSurface& that)
{
	Widget::operator= (that);
	if (drawingSurface) cairo_surface_destroy (drawingSurface);
	drawingSurface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, getEffectiveWidth (), getEffectiveHeight ());
	//TODO copy surface data

	return *this;
}

cairo_surface_t* DrawingSurface::getDrawingSurface () {return drawingSurface;}

void DrawingSurface::setWidth (const double width)
{
	double oldEffectiveWidth = getEffectiveWidth ();
	Widget::setWidth (width);

	if (oldEffectiveWidth != getEffectiveWidth ())
	{
		if (drawingSurface) cairo_surface_destroy (drawingSurface);
		drawingSurface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, getEffectiveWidth (), getEffectiveHeight ());
		//TODO copy surface data
	}

	update ();
}

void DrawingSurface::setHeight (const double height)
{
	double oldEffectiveHeight = getEffectiveHeight ();
	Widget::setHeight (height);

	if (oldEffectiveHeight != getEffectiveHeight ())
	{
		if (drawingSurface) cairo_surface_destroy (drawingSurface);
		drawingSurface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, getEffectiveWidth (), getEffectiveHeight ());
		//TODO copy surface data
	}

	update ();
}

void DrawingSurface::setBorder (const BStyles::Border& border)
{
	double oldTotalBorderWidth = getXOffset ();
	border_ = border;

	if (oldTotalBorderWidth != getXOffset ())
	{
		if (drawingSurface) cairo_surface_destroy (drawingSurface);
		drawingSurface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, getEffectiveWidth (), getEffectiveHeight ());
		//TODO copy surface data
	}

	update ();
}

void DrawingSurface::draw (const double x, const double y, const double width, const double height)
{
	if ((!widgetSurface) || (cairo_surface_status (widgetSurface) != CAIRO_STATUS_SUCCESS)) return;

	if ((width_ >= 4) && (height_ >= 4))
	{
		// Draw super class widget elements first
		Widget::draw (x, y, width, height);

		cairo_t* cr = cairo_create (widgetSurface);
		if (cairo_status (cr) == CAIRO_STATUS_SUCCESS)
		{
			// Limit cairo-drawing area
			cairo_rectangle (cr, x, y, width, height);
			cairo_clip (cr);
			//TODO also clip to inner borders

			cairo_set_source_surface (cr, drawingSurface, getXOffset (), getYOffset ());
			cairo_paint (cr);
		}
		cairo_destroy (cr);
	}
}

}
