#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat *Admin = new Bureaucrat("Admin", 1);
    Bureaucrat *John = new Bureaucrat("John", 144);

    ShrubberyCreationForm SForm("forest");
    RobotomyRequestForm RForm("Sickman");
    PresidentialPardonForm PForm("Guilty");

    std::cout << std::endl << std::endl << std::endl;

    // << overload test
    std::cout << SForm << std::endl;
    std::cout << RForm << std::endl;
    std::cout << PForm << std::endl;

    //no sign, try to execute
    RForm.execute(*Admin);

    //not enough grade to sign
    try
    {
        PForm.beSigned(*John);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //enough grade to sign but not enough grade to execute
    try
    {
        SForm.beSigned(*John);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    SForm.execute(*John);

    //execute succesfully
    SForm.execute(*Admin);
    try
    {
        RForm.beSigned(*Admin);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        PForm.beSigned(*Admin);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    RForm.execute(*Admin);
    PForm.execute(*Admin);

    std::cout << std::endl << std::endl << std::endl;
    delete John;
    delete Admin;
}