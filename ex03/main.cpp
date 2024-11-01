#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Intern intern;
	Bureaucrat bob("Bob", 1);

	// 正常なフォーム作成のテスト
	AForm *formA = intern.makeForm("shrubbery creation", "home");
	if (formA)
	{
		formA->beSigned(bob);
		bob.executeForm(*formA);
		delete formA;
	}

	AForm *formB = intern.makeForm("robotomy request", "Bender");
	if (formB)
	{
		formB->beSigned(bob);
		bob.executeForm(*formB);
		delete formB;
	}

	AForm *formC = intern.makeForm("presidential pardon", "Zaphod");
	if (formC)
	{
		formC->beSigned(bob);
		bob.executeForm(*formC);
		delete formC;
	}

	// 無効なフォーム名のテスト
	AForm *invalidForm = intern.makeForm("invalid form", "test");
	if (!invalidForm)
	{
		std::cout << "Form creation failed for invalid form type." << std::endl;
	}

	return 0;
}
