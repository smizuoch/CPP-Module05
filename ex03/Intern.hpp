#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <map>
#include <string>

class Intern
{
  public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target);

  private:
	typedef AForm *(*FormCreator)(const std::string &target);

	struct FormEntry
	{
		const char *name;
		FormCreator creator;
	};

	static AForm *createShrubberyForm(const std::string &target);
	static AForm *createRobotomyForm(const std::string &target);
	static AForm *createPardonForm(const std::string &target);

	static FormEntry formEntries[];
};

#endif
