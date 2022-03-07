#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

char **envpp = NULL;

int main(int argc, char *argv[], char **envp)
{
	(void)argc;
	(void)argv;

	envpp = envp;

	Bureaucrat				Bob("Bob", 150);
	Bureaucrat				Steve("Steve", 100);
	Bureaucrat				Trump("Trump", 1);
	
	ShrubberyCreationForm	shrubForm("Bob's_garden");
	RobotomyRequestForm		robotForm("Steve");
	PresidentialPardonForm	PresiForm("Trump");
	
	try
	{
		std::cout << Bob << std::endl;
		std::cout << shrubForm << std::endl;
		Bob.executeForm(shrubForm);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		int incr = Bob.getGrade() - shrubForm.getGrade2Execute() + 1;
		for(int i = 0; i < incr; i++)
			Bob.incrementGrade();
		std::cout << Bob << std::endl;
		shrubForm.signForm(Bob);
		Bob.executeForm(shrubForm);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	

	try
	{
		std::cout << Steve << std::endl;
		std::cout << robotForm << std::endl;
		Steve.executeForm(robotForm);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		int incr = Steve.getGrade() - robotForm.getGrade2Execute() + 1;
		for(int i = 0; i < incr; i++)
			Steve.incrementGrade();
		std::cout << Steve << std::endl;
		robotForm.signForm(Steve);
		Steve.executeForm(robotForm);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	try
	{
		std::cout << Trump << std::endl;
		PresiForm.signForm(Trump);
		Trump.executeForm(PresiForm);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

}