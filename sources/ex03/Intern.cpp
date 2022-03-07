#include "Intern.hpp"

static Form	*createPresiForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}
static Form	*createRobotForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}
static Form	*createShrubForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern()
{
}
Intern::Intern(Intern const &in)
{
	(void)in;
}
Intern &Intern::operator=(Intern const &in)
{
	(void)in;
	return (*this);
}
Form	*Intern::makeForm(std::string const &form, std::string const & target)
{
	t_FormShit	shit[] =
	{
		{"PresidentialPardonForm", &createPresiForm},
		{"RobotomyRequestForm", &createRobotForm},
		{"ShrubberyCreationForm", &createShrubForm}
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (shit[i].formType == form)
			return (shit[i].func(target));
	}
	std::cout << "Bad Form Name!" << std::endl;
	return (NULL);
}

Intern::~Intern()
{
}
