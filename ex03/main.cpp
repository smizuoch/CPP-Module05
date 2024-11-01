#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm formA("home");
		RobotomyRequestForm formB("robot");
		PresidentialPardonForm formC("Zaphod");

		formA.beSigned(bob);
		bob.executeForm(formA);

		formB.beSigned(bob);
		bob.executeForm(formB);

		formC.beSigned(bob);
		bob.executeForm(formC);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
