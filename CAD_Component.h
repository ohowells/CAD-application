#ifndef _CAD_COMPONENT_
#define _CAD_COMPONENT_

#include <string>
#include <list>

namespace cad
{
	class ComponentMemento;

	class CAD_Component
	{
	public:
		CAD_Component(void) 
		{
		}
		CAD_Component(std::string shape, std::string colour, int pos_x, int pos_y);
		
		std::list<CAD_Component> GetSubComponents(void) const;
		void ClearSubComponents(void);

		std::string GetShape(void) const;
		std::string GetColour(void) const;
		int GetPosX(void) const;
		int GetPosY(void) const;

		void SetShape(std::string n_shape);
		void SetColour(std::string n_colour);
		void SetPosX(int n_x);
		void SetPosY(int n_y);

		//// Helper functions for memento object.
		//ComponentMemento* SaveMemento(void)
		//{
		//	return new ComponentMemento(shape, colour, pos_x, pos_y);
		//}

		//void ReinstateMemento(ComponentMemento& obj)
		//{
		//	this->shape		= obj.GetShape();
		//	this->colour    = obj.GetColour();
		//	this->pos_x		= obj.GetPosX();
		//	this->pos_y		= obj.GetPosY();
		//}

	private:
		std::list<CAD_Component> sub_comp;

		std::string shape;
		std::string colour;

		int pos_x;
		int pos_y;
	};

	// Helper class to build the memento object.
	//class ComponentMemento
	//{
	//public:
	//	ComponentMemento(std::string& shape, std::string& colour, int& pos_x, int& pos_y)
	//		: t_shape(shape),
	//		t_colour(colour),
	//		t_x(pos_x),
	//		t_y(pos_y)
	//	{
	//	}

	//	std::string GetShape(void) const
	//	{
	//		return t_shape;
	//	}
	//	std::string GetColour(void) const
	//	{
	//		return t_colour;
	//	}
	//	int GetPosX(void) const
	//	{
	//		return t_x;
	//	}
	//	int GetPosY(void) const
	//	{
	//		return t_y;
	//	}

	//	void SetShape(std::string n_shape)
	//	{
	//		t_shape = n_shape;
	//	}
	//	void SetColour(std::string n_colour)
	//	{
	//		t_colour = n_colour;
	//	}
	//	void SetPosX(int n_x)
	//	{
	//		t_x = n_x;
	//	}
	//	void SetPosY(int n_y)
	//	{
	//		t_y = n_y;
	//	}
	//private:
	//	std::string	t_shape;
	//	std::string	t_colour;

	//	int	t_x;
	//	int	t_y;
	//};
}
#endif