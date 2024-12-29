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