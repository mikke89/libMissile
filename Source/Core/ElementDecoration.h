/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef ROCKETCOREELEMENTDECORATION_H
#define ROCKETCOREELEMENTDECORATION_H

#include "../../Include/Rocket/Core/Types.h"

namespace Rocket {
namespace Core {

class Decorator;
class Element;

/**
	Manages an elements decorator state

	@author Lloyd Weehuizen
 */

class ElementDecoration
{
public:
	/// Constructor
	/// @param element The element this decorator with acting on
	ElementDecoration(Element* element);
	~ElementDecoration();

	/// Renders all appropriate decorators.
	void RenderDecorators();

	/// Mark decorators as dirty and force them to reset themselves.
	void DirtyDecorators();

private:
	// Loads a single decorator and adds it to the list of loaded decorators for this element.
	int LoadDecorator(std::shared_ptr<Decorator> decorator);
	// Releases existing decorators and loads all decorators required by the element's definition.
	bool ReloadDecorators();
	// Releases all existing decorators and frees their data.
	void ReleaseDecorators();

	struct DecoratorHandle
	{
		std::shared_ptr<Decorator> decorator;
		DecoratorDataHandle decorator_data;
	};

	typedef std::vector< DecoratorHandle > DecoratorList;

	// The element this decorator belongs to
	Element* element;

	// The list of every decorator used by this element in every class.
	DecoratorList decorators;

	// If set, a full reload is necessary
	bool decorators_dirty;
};

}
}

#endif
