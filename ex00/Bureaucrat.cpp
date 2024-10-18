#include "Bureaucrat.hpp"

// デフォルトコンストラクタ
Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{
}

// コピーコンストラクタ
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

// 代入演算子オーバーロード
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		// 名前はconstなので代入できないため、グレードのみをコピー
		this->grade = other.grade;
	}
	return *this;
}

// デストラクタ
Bureaucrat::~Bureaucrat()
{
}

// パラメータ付きコンストラクタ
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

// ゲッター
std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

// グレードの変更
void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
	{
		throw GradeTooLowException();
	}
	grade++;
}

// 例外クラスの実装
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// 出力演算子オーバーロード
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
