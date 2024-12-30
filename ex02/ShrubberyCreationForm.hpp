/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:35 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:36 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat &executor) const;
    private:
        std::string target;
};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const &src);
#endif