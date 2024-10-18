#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat; // 前方宣言

class Form
{
  private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

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

	// コンストラクタとデストラクタ
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	// ゲッター
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// フォームの署名
	void beSigned(const Bureaucrat &bureaucrat);

	// 出力演算子オーバーロード
	friend std::ostream &operator<<(std::ostream &os, const Form &form);
};

#endif
