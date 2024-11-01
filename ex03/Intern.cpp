#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	if (formName == "shrubbery creation")
	{
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request")
	{
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon")
	{
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
	{
		std::cout << "Intern couldn't find the requested form: " << formName << std::endl;
		return NULL;
	}
}
