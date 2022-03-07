#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	try
	{
		Bureaucrat crat("steve", 2);
		Form form("Extremely important document", 2, 3);
		Form form2("You can live", 150, 150);

		form.signForm(crat);

		std::cout << form << std::endl;

		crat.incrementGrade();
		form.signForm(crat);
		form2.signForm(crat);

		std::cout << form << std::endl;
		
		crat.incrementGrade();
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}