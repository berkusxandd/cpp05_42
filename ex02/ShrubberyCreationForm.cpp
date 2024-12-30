/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:33 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:34 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shubbery",145,137)
{
    std::cout << "ShrubberyCreationForm CONSTRUCTOR called." << std::endl;
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
    this->target = src.target;
    std::cout << "ShrubberyCreationForm COPY constructor called." << std::endl;
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm DESTRUCTOR called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    if (this != &src)
        this->target = src.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat &executor) const
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
        std::string outfile = this->target + "_shrubbery";
        std::ofstream output(outfile.c_str());
        if (!output)
        {
            std::cout << "File couldn't be opened" << std::endl;
            return;
        }
        output << "       _-_" << std::endl;
		output << "    /~~   ~~\\" << std::endl;
		output << " /~~         ~~\\" << std::endl;
		output << "{               }" << std::endl;
		output << " \\  _-     -_  /" << std::endl;
		output << "   ~  \\ //  ~" << std::endl;
		output << "_- -   | | _- _" << std::endl;
		output << "  _ -  | |   -_" << std::endl;
		output << "      // \\\\" << std::endl;
    }
    else
        std::cout << "ShrubberyCreationForm is not signed." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const &src) {
	o << "Form Name: " << src.getName() << std::endl << "Grade to sign : " << src.getGradeSign() << std::endl << "Grade to execute: " << src.getGradeExec() << std::endl << 
    "Is signed: " << src.getIsSigned();
	return o;
}