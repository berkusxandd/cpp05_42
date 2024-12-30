/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:59 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:45:00 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);
        ~RobotomyRequestForm();

        void execute(Bureaucrat &executor) const;
    private:
        std::string target;
};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &src);

#endif