#include "RobotomyRequestForm.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <random>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  Form("RobtomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & in) : Form(in.getName(), in.getGrade2Sign(), in.getGrade2Execute()), _target(in._target)
{
}

void RobotomyRequestForm::action() const
{
	int pid;

	srand((unsigned int)time(NULL));

	char	*arr[3];
	std::string cmd[2] = {"/usr/bin/afplay","./test.mp3"};
	arr[0] = (char *)cmd[0].c_str();
	arr[1] = (char *)cmd[1].c_str();
	arr[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (execve(arr[0], (char **)arr, envpp) == -1)
			std::cout<< "shit head"<< std::endl;
		exit(1);	
	}
	else
	{
		sleep(10);
		kill(pid, SIGTERM);
	}
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " was not robotomized" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & in)
{
	this->_target = in._target;
	return (*this);
}