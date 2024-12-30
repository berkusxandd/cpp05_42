/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:12 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:13 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
AForm::AForm() : _name("Unnamed Form"), _isSigned(false), _gradeSign(0), _gradeExec(0)
{
    std::cout << "Unnamed Form is constructed." << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    this->_isSigned = false;
    std::cout << "Form -" << name << "- is constructed, required grade to sign: " << gradeSign << " required grade to execute: " << gradeExec << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form -" << this->_name << " is destructed." << std::endl;
}

AForm::AForm(AForm const &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
    *this = src;
}

AForm &AForm::operator=(AForm const &src)
{
    if (this != &src)
        this->_isSigned = src.getIsSigned();

    return (*this);
}

int AForm::getGradeSign() const
{
    return (this->_gradeSign);
}

int AForm::getGradeExec() const
{
    return (this->_gradeExec);
}

bool AForm::getIsSigned() const
{
    return (this->_isSigned);
}

std::string AForm::getName() const
{
    return (this->_name);
}

void AForm::beSigned(Bureaucrat &bur)
{
    if (this->_isSigned)
    {
        std::cout<<"Form -" << this->getName() << " is already signed." << std::endl;
        return;
    }
    if (bur.getGrade() <= this->getGradeSign())
    {
        bur.signForm(this->getName(), this->getGradeSign());
        this->_isSigned = true;
    }
    else
        throw AForm::GradeTooLowException();
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return("Bureaucrat's grade is too high to sign this form.");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return("Bureaucrat's grade is too low to sign this form.");
}

std::ostream &	operator<<(std::ostream & o, AForm const &src) {
	o << "Form Name: " << src.getName() << std::endl << "Grade to sign : " << src.getGradeSign() << std::endl << "Grade to execute: " << src.getGradeExec() << std::endl << 
    "Is signed: " << src.getIsSigned();
	return o;
}
