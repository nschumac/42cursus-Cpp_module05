#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

		typedef struct s_FormShit
		{
			std::string	const	formType;
			Form *(*func)(std::string const & target);
		}				t_FormShit;

	public:
		Intern();
		Intern(Intern const &in);
		Intern &operator=(Intern const &in);
		Form	*makeForm(std::string const &form, std::string const & target);
		~Intern();
};


#endif