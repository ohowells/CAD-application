#ifndef _CARETAKER_
#define _CARETAKER_

#include "CAD_Component.h"

namespace cad
{
	class Caretaker
	{
	public:
		void SetMemento(ComponentMemento _memento)
		{
			memento = _memento;
		}

		ComponentMemento GetMemento(void) const
		{
			return memento;
		}

	private:
		ComponentMemento memento;
	};
}
#endif