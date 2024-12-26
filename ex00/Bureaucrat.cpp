#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout<< "Bureaucrat is CONSTRUCTED without arguments." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout<< "Bureaucrat is CONSTRUCTED with grade: " << grade << " name: " << name << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout<< "Bureaucrat is DECONSTRUCTED" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this=src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &src)
{
    if (this != &src)
    {
        this->_grade = src.getGrade();
    }
    return *this;
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::promote()
{
    if (this->getGrade > )
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrats grade is on its upper limit");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrats grade is on its lower limit");
}