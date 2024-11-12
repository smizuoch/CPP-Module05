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

AForm *Intern::createShrubberyForm(const std::string &target)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardonForm(const std::string &target)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return new PresidentialPardonForm(target);
}

// 静的メンバの初期化
Intern::FormEntry Intern::formEntries[] = {{"shrubbery creation", &Intern::createShrubberyForm},
                                           {"robotomy request", &Intern::createRobotomyForm},
                                           {"presidential pardon", &Intern::createPardonForm}};

// makeForm関数のクラス外部での実装
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (size_t i = 0; i < sizeof(formEntries) / sizeof(FormEntry); ++i)
	{
		if (formName == formEntries[i].name)
		{
			return formEntries[i].creator(target);
		}
	}
	std::cout << "Intern couldn't find the requested form: " << formName << std::endl;
	return NULL;
}
