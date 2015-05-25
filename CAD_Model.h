#ifndef _CAD_MODEL_
#define _CAD_MODEL_

#include <list>
#include "ConsoleIn.h"
#include "CAD_Component.h"
#include "CAD_ViewModel.h"
#include "CAD_EditComponent.h"

namespace cad
{
	typedef std::list<CAD_Component*>	ptr_comp_list;
	typedef CAD_Component*				ptr_comp;
	typedef ptr_comp_list::iterator		ptr_comp_itr;

	class CAD_Model
		: public CAD_ViewModel
	{
	public:
		CAD_Model(void);

		virtual void Initialise(void);

	private:
		// Template class for user input.
		::ConsoleIn<int> console;

		ptr_comp ptr_component;
		CAD_EditComponent* ptr_edit;
		ptr_comp_list container;

		bool user_exited;

		// Pushs comp_obj to an STL coontainer.
		void StoreComponent(CAD_Component* obj);

		// Controls how each model will function.
		void RunModel(void);
		ptr_comp_itr FindComponent(ptr_comp obj);
		void DeleteComponent(ptr_comp obj);

		int DisplayMenu(void) const;

		ptr_comp CreateComponent(int comp_type);
	};
}
#endif