#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy",72,45)
{
    std::cout << "RobotomyRequestForm CONSTRUCTOR called." << std::endl;
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
    this->target = src.target;
    std::cout << "RobotomyRequestForm COPY constructor called." << std::endl;
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm DESTRUCTOR called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
    if (this != &src)
        this->target = src.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const
{
    if (this->getIsSigned() == 1)
    {
        try
        {
            executor.executeForm(this->getName(), this->getGradeExec());
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return;
        }
        std::cout << this->target << " is being robotomized." << std::endl;
        std::cout << "*Zz Drilling noises zZ*" << std::endl;

        std::srand(std::time(NULL));
        if (std::rand() % 2 == 0)
            std::cout << "Robotomy succeeded." << std::endl;
        else
            std::cout << "Robotomy failed." << std::endl;
    }
    else
        std::cout << "RobotomyRequestForm is not signed." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &src) {
	o << "Form Name: " << src.getName() << std::endl << "Grade to sign : " << src.getGradeSign() << std::endl << "Grade to execute: " << src.getGradeExec() << std::endl << 
    "Is signed: " << src.getIsSigned();
	return o;
}