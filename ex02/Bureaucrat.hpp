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
        void signForm(std::string formName, int gradeSign);
        void executeForm(std::string formName, int gradeExecute);
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

    class GradeTooLowToExecuteException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &src);

#endif