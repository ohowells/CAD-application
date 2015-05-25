#include "CAD_EditComponent.h"

using namespace cad;

enum EDIT_STATE { SHAPE = 1, COLOUR, POSX, POSY, DELETE, QUIT };

CAD_EditComponent::CAD_EditComponent(ptr_comp obj)
{
	EditComponent(obj);
}

CAD_EditComponent::~CAD_EditComponent(void)
{
}

void CAD_EditComponent::EditComponent(ptr_comp obj)
{
	int select = DisplayMenu();
	switch (select)
	{
	case SHAPE:
	case COLOUR:
	case POSX:
	case POSY:
	case DELETE:
		EditAttribute(select, obj);
		break;
	case QUIT:
		break;
	default:
		std::cout << "\nInvalid selection, Try again.\n";
		break;
	}
}

void CAD_EditComponent::EditAttribute(int type, ptr_comp obj)
{
	switch (type)
	{
	case SHAPE:
		std::cout << "\nCurrent value: " << obj->GetShape();
		std::cout << "\nNew value: ";	obj->SetShape(console.GetStr());
		break;
	case COLOUR:
		std::cout << "\nCurrent value: " << obj->GetColour();
		std::cout << "\nNew value: ";	obj->SetColour(console.GetStr());
		break;
	case POSX:
		std::cout << "\nCurrent value: " << obj->GetPosX();
		std::cout << "\nNew value: ";	obj->SetPosX(console.GetNum());
		break;
	case POSY:
		std::cout << "\nCurrent value: " << obj->GetPosY();
		std::cout << "\nNew value: ";	obj->SetPosY(console.GetNum());
		break;
	case DELETE:
		obj->ClearSubComponents();
		break;
	default:
		break;
	}
}

inline int CAD_EditComponent::DisplayMenu(void) const
{
	std::cout << "\nEdit Menu:"
			  << "\n\t1 - Shape"
			  << "\n\t2 - Colour"
			  << "\n\t3 - PosX"
			  << "\n\t4 - PosY"
			  << "\n\t5 - Delete SubComps"
			  << "\n\t6 - Go back"
			  << "\nChoose an option: ";
	return console.GetNum();
}