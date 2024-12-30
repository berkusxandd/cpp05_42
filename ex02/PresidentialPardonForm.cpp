/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:23 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:24 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pardon",25,5)
{
    std::cout << "PresidentialPardonForm CONSTRUCTOR called." << std::endl;
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
    this->target = src.target;
    std::cout << "PresidentialPardonForm COPY constructor called." << std::endl;
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm DESTRUCTOR called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
    if (this != &src)
        this->target = src.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat &executor) const
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
        std::cout << this->target << " is pardoned by Zaphod Beeblebrox." << std::endl;
    }
    else
        std::cout << "PresidentialPardonForm is not signed." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &src) {
	o << "Form Name: " << src.getName() << std::endl << "Grade to sign : " << src.getGradeSign() << std::endl << "Grade to execute: " << src.getGradeExec() << std::endl << 
    "Is signed: " << src.getIsSigned();
	return o;
}