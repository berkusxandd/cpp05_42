/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:03 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:04 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
Form::Form() : _name("Unnamed Form"), _isSigned(false), _gradeSign(0), _gradeExec(0)
{
    std::cout << "Unnamed Form is constructed." << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    this->_isSigned = false;
    std::cout << "Form -" << name << "- is constructed, required grade to sign: " << gradeSign << " required grade to execute: " << gradeExec << std::endl;
}

Form::~Form()
{
    std::cout << "Form -" << this->_name << " is destructed." << std::endl;
}

Form::Form(Form const &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
    *this = src;
}

Form &Form::operator=(Form const &src)
{
    if (this != &src)
        this->_isSigned = src.getIsSigned();

    return (*this);
}

int Form::getGradeSign() const
{
    return (this->_gradeSign);
}

int Form::getGradeExec() const
{
    return (this->_gradeExec);
}

bool Form::getIsSigned() const
{
    return (this->_isSigned);
}

std::string Form::getName() const
{
    return (this->_name);
}

void Form::beSigned(Bureaucrat &bur)
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
        throw Form::GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw()
{
    return("Bureaucrat's grade is too high to sign this form.");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return("Bureaucrat's grade is too low to sign this form.");
}

std::ostream &	operator<<(std::ostream & o, Form const &src) {
	o << "Form Name: " << src.getName() << std::endl << "Grade to sign : " << src.getGradeSign() << std::endl << "Grade to execute: " << src.getGradeExec() << std::endl << 
    "Is signed: " << src.getIsSigned();
	return o;
}
