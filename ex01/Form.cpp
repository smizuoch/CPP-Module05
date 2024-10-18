#include "Form.hpp"

// コンストラクタ
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
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

// コピーコンストラクタ
Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

// 代入演算子オーバーロード
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

// デストラクタ
Form::~Form()
{
}

// ゲッターの実装
std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

// フォームを署名する
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
	{
		throw GradeTooLowException();
	}
	isSigned = true;
}

// 例外クラスの実装
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// 出力演算子オーバーロード
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ", requires grade " << form.getGradeToSign() << " to sign and "
	   << form.getGradeToExecute() << " to execute, signed status: " << (form.getIsSigned() ? "signed" : "not signed");
	return os;
}
