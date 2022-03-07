#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & in) : Form(in.getName(), in.getGrade2Sign(), in.getGrade2Execute()), _target(in._target)
{
}

void ShrubberyCreationForm::action() const
{
	std::ofstream file(_target + "_shrubbery");

	if (file.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			file	<< "      /\\      "		<< std::endl
					<< "     /\\*\\     "		<< std::endl
					<< "    /\\O\\*\\    "		<< std::endl
					<< "   /*/\\/\\/\\   "		<< std::endl
					<< "  /\\O\\/\\*\\/\\  "	<< std::endl
					<< " /\\*\\/\\*\\/\\/\\ "	<< std::endl
					<< "/\\O\\/\\/*/\\/O/\\"	<< std::endl
					<< "      ||      "			<< std::endl
					<< "      ||      "			<< std::endl
					<< "      ||      "			<< std::endl
					<< std::endl;
		}
		file.close();
	}
	else
	{
		throw "Cannot open File";
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & in)
{
	this->_target = in._target;
	return (*this);
}