/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:43:58 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:43:59 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout<< "Bureaucrat is CONSTRUCTED without arguments." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 0)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
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
    if (this->getGrade() > 1)
    {
        this->_grade--;
        std::cout << this->getName() << " is promoted! New grade is " << this->getGrade() << std::endl;
    }
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signForm(std::string formName, int gradeSign)
{
    if (gradeSign >= this->getGrade())
    {
        std::cout << "Bureaucrat -" << this->getName() << "- succesfully signed Form -" << formName << "-" << std::endl;
    }
    else
        std::cout << "Bureaucrat -" << this->getName() << "- cannot sign Form -" << formName << "- because of lower grade" << std::endl;
}

void Bureaucrat::demote()
{
    if (this->getGrade() < 150)
    {
        this->_grade++;
        std::cout << this->getName() << " is demoted! New grade is " << this->getGrade() << std::endl;
    }
    else
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat's grade is on its upper limit");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat's grade is on its lower limit");
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &src) {
	o << src.getName() << ", bureaucrat grade : " << src.getGrade();
	return o;
}