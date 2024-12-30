/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:39 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:40 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExec);
        virtual ~AForm();
        AForm(AForm const &src);
        AForm & operator=(AForm const &src);
        int getGradeSign() const;
        int getGradeExec() const;
        bool getIsSigned() const;
        std::string getName() const;
        void beSigned(Bureaucrat &bur);
        virtual void execute(Bureaucrat & bur) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
};

std::ostream &	operator<<(std::ostream & o, AForm const &src);

#endif