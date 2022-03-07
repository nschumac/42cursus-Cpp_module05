#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1 || grade > 150)
		this->_grade = 150;
	else
		this->_grade = grade;	
}
Bureaucrat::Bureaucrat(Bureaucrat const & in) : _name(in._name){
	this->_grade = in._grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

Bureaucrat::~Bureaucrat()
{

}

std::string const Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &crat)
{
	os << crat.getName() << ", bureacrat grade " << crat.getGrade() << std::endl;
	return (os);
}
