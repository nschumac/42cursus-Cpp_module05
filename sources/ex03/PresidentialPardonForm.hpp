#ifndef	PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

	#include "Form.hpp"

	extern char **envpp;

	class PresidentialPardonForm : public Form
	{
		private:
			std::string _target;
			PresidentialPardonForm();
		public:
		PresidentialPardonForm &operator=(PresidentialPardonForm const & in);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & in);
		~PresidentialPardonForm();
		void	action() const;
	};

#endif