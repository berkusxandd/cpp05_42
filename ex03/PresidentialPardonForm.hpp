/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:55 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:56 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESEDENTIALPARDONFORM_HPP
#define PRESEDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
        ~PresidentialPardonForm();

        void execute(Bureaucrat &executor) const;
    private:
        std::string target;
};

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &src);

#endif