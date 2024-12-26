#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &src);
        Bureaucrat& operator=(Bureaucrat const &src);

        int getGrade() const;
        std::string getName() const;
        void promote();
        void demote();

    private:
        std::string const _name;
        int _grade;

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

#endif