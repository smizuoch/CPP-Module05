#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

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

	// Orthodox Canonical Form
	Bureaucrat();                                   // デフォルトコンストラクタ
	Bureaucrat(const Bureaucrat &other);            // コピーコンストラクタ
	Bureaucrat &operator=(const Bureaucrat &other); // 代入演算子オーバーロード
	~Bureaucrat();                                  // デストラクタ

	// パラメータ付きコンストラクタ
	Bureaucrat(const std::string &name, int grade);

	// ゲッター
	std::string getName() const;
	int getGrade() const;

	// グレードの変更
	void incrementGrade();
	void decrementGrade();

	// 出力演算子オーバーロード
	friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

	// フォームの署名
	void signForm(class Form &form);
};

#endif
