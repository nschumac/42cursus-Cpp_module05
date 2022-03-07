#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <stdexcept>

class Form;

# define LOG(x) std::cout << x;
# define LOGN(x) std::cout << x << std::endl;

class Bureaucrat
{
private:
	std::string const _name;
	Bureaucrat &operator=(Bureaucrat const &buro);
	int	_grade;
	Bureaucrat(){};
public:
	class GradeTooHighException : public std::exception
	{
		private:
			std::string msg;
		public:
			GradeTooHighException():msg("Grade Too High Exception"){};
			~GradeTooHighException() _NOEXCEPT {};
			const char * what() const throw()
			{
				return msg.c_str();
			}
	};	
	class GradeTooLowException : public std::exception
	{
		private:
			std::string msg;
		public:
			GradeTooLowException():msg("Grade Too Low Exception"){};
			~GradeTooLowException()_NOEXCEPT{};
			const char * what() const throw()
			{
				return msg.c_str();
			}
	};
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &in);
	std::string const	getName() const;
	void	executeForm(Form const & form);
	int	getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &crat);
	~Bureaucrat();
};

#endif