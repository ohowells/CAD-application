#ifndef _CAD_EDIT_COMPONENT_
#define _CAD_EDIT_COMPONENT_

#include <iostream>
#include "CAD_Component.h"
#include "ConsoleIn.h"

namespace cad
{
	typedef CAD_Component* ptr_comp;

	class CAD_EditComponent
	{
	public:
		CAD_EditComponent(ptr_comp obj);
		~CAD_EditComponent(void);

		void EditComponent(ptr_comp obj);
		void EditAttribute(int type, ptr_comp obj);

		int DisplayMenu(void) const;

	private:
		::ConsoleIn<int> console;
	};
}
#endif