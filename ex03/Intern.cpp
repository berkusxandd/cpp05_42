/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:46 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:47 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default CONSTRUCTOR called." << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Intern COPY constructor called." << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern DESTRUCTOR called." << std::endl;
}

Intern &Intern::operator=(Intern const &src) {
	(void)src;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    AForm *	form = NULL;
	AForm *	(Intern::*funcPtr[3])(std::string target) const = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string		forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int		i = -1;

	while (++i < 3) {
		if (forms[i] == formName) {
			form = (this->*funcPtr[i])(target);
			std::cout << "Intern create " << formName << " form." << std::endl;
			return form;
		}
	}
	throw Intern::WrongNameException();
	return NULL;
}

const char * Intern::WrongNameException::what() const throw()
{
    return("Form's name is undefined.");
}

AForm *Intern::makePresidential(std::string target) const {
	AForm *	form = new PresidentialPardonForm(target);
	return form;
}

AForm *Intern::makeRobotomy(std::string target) const {
	AForm *	form = new RobotomyRequestForm(target);
	return form;
}

AForm *Intern::makeShrubbery(std::string target) const {
	AForm *	form = new ShrubberyCreationForm(target);
	return form;
}