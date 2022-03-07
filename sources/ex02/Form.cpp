#include "Form.hpp"



Form::Form(Form const & in) : _name(in._name), _grade2Sign(in._grade2Sign), _grade2Execute(in._grade2Execute)
{	
	_signed = in._signed;
}

Form::Form(std::string name, int grade2Sign, int grade2Execute) : _name(name), _grade2Sign(grade2Sign), _grade2Execute(grade2Execute)
{
	if (grade2Sign < 1 || grade2Execute < 1)
		throw GradeTooHighException();
	else if (grade2Sign > 150 || grade2Execute > 150)
		throw GradeTooLowException();
	_signed = false;
}

bool	Form::getSigned()
{
	return (this->_signed);
}

std::string const Form::getName() const
{
	return (this->_name);
}

int	Form::getGrade2Execute() const
{
	return (this->_grade2Execute);
}

int	Form::getGrade2Sign() const
{
	return (this->_grade2Sign);
}

bool	Form::beSigned(Bureaucrat &crat)
{
	if (crat.getGrade() < this->_grade2Sign)
	{
		_signed = true;
		return (true);
	}
	else
		throw GradeTooHighException();
	return (false);
}

void	Form::signForm(Bureaucrat &crat)
{	
	try
	{
		if (beSigned(crat))
			std::cout << crat.getName() << " signs " << this->_name << "!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << crat.getName() << " cannot sign " << this->_name << " because " << e.what() << std::endl;
	}
}

Form::~Form() {

}

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << form.getName() << " [Sign: " << form.getGrade2Sign() << "] [Execute: " << form.getGrade2Execute() << "] is " << (form.getSigned() ? "signed!" : "not signed!");

	return (os); 
}

bool	Form::execute(Bureaucrat const & executor) const
{
	if (this->_signed)
	{
		if (executor.getGrade() < this->_grade2Execute)
		{
			this->action();
			return true;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSignedException();
	return false;
}