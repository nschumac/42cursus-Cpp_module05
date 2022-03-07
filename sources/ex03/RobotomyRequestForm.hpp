#ifndef	ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

	#include "Form.hpp"

	extern char **envpp;

	class RobotomyRequestForm : public Form
	{
		private:
			std::string _target;
			RobotomyRequestForm();
		public:
		RobotomyRequestForm &operator=(RobotomyRequestForm const & in);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & in);
		~RobotomyRequestForm();
		void	action() const;
	};

#endif