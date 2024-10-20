#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat; // 前方宣言

class AForm
{
  private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

  protected:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);

  public:
	// 例外クラス
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		const char *what() const throw();
	};

	virtual ~AForm();

	// ゲッター
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// フォームの署名
	void beSigned(const Bureaucrat &bureaucrat);

	// 純粋仮想関数
	virtual void execute(const Bureaucrat &executor) const = 0;
};

#endif
