#ifndef _CAD_VIEW_MODEL_
#define _CAD_VIEW_MODEL_

namespace cad
{
	class CAD_ViewModel
	{
	public:
		virtual void Initialise(void) = 0;

		virtual void DisplayTextMenu(void) const
		{
			std::cout << "\nMain Menu:"
					  << "\n\t1 - Square"
					  << "\n\t2 - Circle"
					  << "\n\t3 - Rectangle"
					  << "\n\t4 - Edit"
					  << "\n\t5 - Show Component"
					  << "\n\t6 - Exit"
					  << "\nChoose an option: ";
		}

		virtual void ShowComponent(const std::string& shape, const std::string& colour, 
								   const int& x, const int& y) const
		{ 
			std::cout << "\nComponent type       : " << shape
					  << "\nComponent colour     : " << colour
					  << "\nComponent position x : " << x
					  << "\nComponent position y : " << y
					  << std::endl;
		}

		virtual void Wait(void) const
		{
			std::cout << "\nPress any key to continue";
			std::cin.ignore();
			std::cin.get();
			system("cls");
		}
	};
}
#endif