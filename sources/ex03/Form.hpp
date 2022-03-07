#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form
{
private:

	bool _signed;
	std::string const _name;
	int const _grade2Sign;
	int const _grade2Execute;
	Form &operator=(Form const &form);
	bool	beSigned(Bureaucrat &crat);

	Form() : _grade2Sign(1), _grade2Execute(1){};

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
	class FormNotSignedException : public std::exception
	{
		private:
			std::string msg;
		public:
			FormNotSignedException() : msg("Form is not Signed"){};
			~FormNotSignedException() _NOEXCEPT{};
			const char * what() const throw()
			{
				return msg.c_str();
			}
	};
	
	virtual void	action() const = 0;
	bool	execute(Bureaucrat const & executor) const;	

	bool getSigned();
	std::string const getName() const;
	int	getGrade2Sign() const;
	int	getGrade2Execute() const;
	friend std::ostream &operator<<(std::ostream &os, Form &form);	
	void	signForm(Bureaucrat &crat);
	Form(std::string name, int grade2Sign, int grade2Execute);
	Form(Form const &in);
	virtual ~Form();
};

#endif