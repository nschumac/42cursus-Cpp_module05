#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat buro("steve", 1);
		Bureaucrat buro2("steve2", 130);
		buro.decrementGrade();
		std::cout << buro;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}