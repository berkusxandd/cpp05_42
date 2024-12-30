/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:48 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:49 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class AForm;
class Bureaucrat;

class Intern 
{
    public:
        Intern();
        ~Intern();
        Intern(Intern const &src);
        Intern &operator=(Intern const &src);
        AForm *makeForm(std::string formName, std::string target);
    private:
        AForm *	makePresidential(std::string target) const;
		AForm *	makeRobotomy(std::string target) const;
		AForm *	makeShrubbery(std::string target) const;
    class WrongNameException : public std::exception
    {
         public:
            virtual const char * what() const throw();
    };
};
#endif