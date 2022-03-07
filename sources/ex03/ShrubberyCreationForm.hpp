#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

	#include "Form.hpp"

	class ShrubberyCreationForm : public Form
	{
		private:
			std::string _target;
			ShrubberyCreationForm();
		public:
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & in);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & in);
		~ShrubberyCreationForm();
		void	action() const;
	};

#endif