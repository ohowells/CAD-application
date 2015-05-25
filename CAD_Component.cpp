#include "CAD_Component.h"

using namespace cad;

typedef std::list<CAD_Component> comp_list;

CAD_Component::CAD_Component(std::string shape, std::string colour, int pos_x, int pos_y)
	: shape(shape),
	colour(colour),
	pos_x(pos_x),
	pos_y(pos_y)
{
}

comp_list CAD_Component::GetSubComponents(void) const
{
	return sub_comp;
}

void CAD_Component::ClearSubComponents(void)
{
	sub_comp.clear();
}

std::string CAD_Component::GetShape(void) const
{
	return shape;
}

std::string CAD_Component::GetColour(void) const
{
	return colour;
}

int CAD_Component::GetPosX(void) const
{
	return pos_x;
}

int CAD_Component::GetPosY(void) const
{
	return pos_y;
}

void CAD_Component::SetShape(std::string n_shape)
{
	shape = n_shape;
}

void CAD_Component::SetColour(std::string n_colour) 
{
	colour = n_colour;
}

void CAD_Component::SetPosX(int n_x) 
{
	pos_x = n_x;
}

void CAD_Component::SetPosY(int n_y) 
{
	pos_y = n_y;
}