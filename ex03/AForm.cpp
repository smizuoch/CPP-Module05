#include "AForm.hpp"

// コンストラクタ
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw GradeTooLowException();
	}
}

// デストラクタ
AForm::~AForm()
{
}

// ゲッター
std::string AForm::getName() const
{
	return name;
}
bool AForm::getIsSigned() const
{
	return isSigned;
}
int AForm::getGradeToSign() const
{
	return gradeToSign;
}
int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

// フォームの署名
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
	{
		throw GradeTooLowException();
	}
	isSigned = true;
}

// 例外クラスの実装
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed!";
}
