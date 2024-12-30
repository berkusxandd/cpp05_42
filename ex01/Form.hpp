/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:05 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:06 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"
class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExec;
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExec);
        ~Form();
        Form(Form const &src);
        Form & operator=(Form const &src);
        int getGradeSign() const;
        int getGradeExec() const;
        bool getIsSigned() const;
        std::string getName() const;
        void beSigned(Bureaucrat &bur);

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

std::ostream &	operator<<(std::ostream & o, Form const &src);

#endif