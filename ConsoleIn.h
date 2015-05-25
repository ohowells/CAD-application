// 
//			***********ConsoleIn template class***********
//
// Arthur: Owain Howells - 2014
//
// Handles input from a user through a console window
//
// ---------------------------Methods--------------------------------
//
// GetNum() - For numeric data types (int, float, doudle, short etc.)
//
// GetStr() - For strings and chars
//
// ContainsNum() - Validation for char or string type inputs.
//               
//

#ifndef _CONSOLE_IN_
#define _CONSOLE_IN_

#include <iostream>
#include <string>

namespace
{
	template<typename T>
	class ConsoleIn
	{
	public:
		// Throws invalid input if a char is persent
		T GetNum(void) const
		{
			T data;
			bool is_valid = false;
			while (!is_valid)
			{
				std::cin >> data;
				if (std::cin.fail())
				{
					std::cout << "Invalid input, please re-enter: ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else is_valid = true;
			}
			return data;
		}

		std::string GetStr(void)
		{
			std::string data;
			std::cin >> data;
			return data;
		}
		
		// Checks if a string or contains a number.
		bool ContainsNum(const T& input) const 
		{
			return (input.find_first_of("0123456789") != std::string::npos);
		}
	};
}
#endif