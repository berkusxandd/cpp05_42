#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat *Admin = new Bureaucrat("Admin", 1);
    Intern *InternPaul = new Intern();
    AForm *Forms[4];

    std::cout << std::endl << std::endl << std::endl;
    try
    {
        Forms[0] = InternPaul->makeForm("shrubbery creation","Forest");
        Forms[1] = InternPaul->makeForm("presidential pardon","Guilty");
        Forms[2] = InternPaul->makeForm("robotomy request","forest");
        Forms[3] = InternPaul->makeForm("noname","forest");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl;
    try
    {
        Forms[0]->beSigned(*Admin);
        Forms[0]->execute(*Admin);

        Forms[1]->beSigned(*Admin);
        Forms[1]->execute(*Admin);

        Forms[2]->beSigned(*Admin);
        Forms[2]->execute(*Admin);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl << std::endl << std::endl;
    for (int i=0; i<3;i++)
    {
        delete Forms[i];
    }
    delete InternPaul;
    delete Admin;
}