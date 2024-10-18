#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Alice", 2);
		Form formA("FormA", 3, 5);

		std::cout << formA << std::endl;
		bob.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Bob", 10);
		Form formB("FormB", 3, 5);

		std::cout << formB << std::endl;
		alice.signForm(formB); // ここで例外がスローされる
		std::cout << formB << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
