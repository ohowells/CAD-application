#include <iostream>
#include "CAD_Model.h"

using namespace cad;

enum COMP_TYPE { SQUARE = 1, CIRCLE, RECTAN, EDIT, SEE_COMP, NO_COMP };

CAD_Model::CAD_Model(void) 
	: user_exited(false)
{
}

inline void CAD_Model::Initialise(void)
{
	RunModel();
}

void CAD_Model::RunModel(void)
{
	while (!user_exited)
	{
		int selection = DisplayMenu();
		switch (selection)
		{
		case SQUARE:
		case CIRCLE:
		case RECTAN:
			ptr_component = CreateComponent(selection);
			StoreComponent(ptr_component);
			CAD_ViewModel::ShowComponent(ptr_component->GetShape(),
									     ptr_component->GetColour(),
										 ptr_component->GetPosX(),
										 ptr_component->GetPosY());

			CAD_ViewModel::Wait();
			break;
		case EDIT:
			ptr_edit->EditComponent(ptr_component);
			CAD_ViewModel::Wait();
			break;
		case SEE_COMP:
			CAD_ViewModel::ShowComponent(ptr_component->GetShape(),
										 ptr_component->GetColour(),
										 ptr_component->GetPosX(),
										 ptr_component->GetPosY());

			CAD_ViewModel::Wait();
			break;
		case NO_COMP:
			user_exited = true;
			delete ptr_component;
			break;
		default:
			std::cout << "\nInvalid selection, Try again.\n";
			break;
		}
	}
} 

inline int CAD_Model::DisplayMenu(void) const
{
	CAD_ViewModel::DisplayTextMenu();
	return console.GetNum();
}

CAD_Component* CAD_Model::CreateComponent(int type)
{
	CAD_Component* ptr_temp = nullptr;
	switch (type)
	{
	case SQUARE:
		ptr_temp = new CAD_Component("Square", "Red", 100, 220);
		break;
	case CIRCLE:
		ptr_temp = new CAD_Component("Circle", "Blue", 110, 250);
		break;
	case RECTAN:
		ptr_temp = new CAD_Component("Rectangle", "Green", 200, 120);
		break;
	}
	return ptr_temp;
}

inline void CAD_Model::StoreComponent(ptr_comp obj)
{
	container.push_back(obj);
}

inline void CAD_Model::DeleteComponent(ptr_comp obj)
{
	container.erase(FindComponent(obj));
}

ptr_comp_itr CAD_Model::FindComponent(ptr_comp obj)
{
	ptr_comp_itr i = std::find(container.begin(),
							   container.end(),
							   obj);
	return i;
}