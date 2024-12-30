/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:44:08 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:44:09 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	Bureaucrat *John = new Bureaucrat("John", 100);
    Form form1("form1",100,100);
    Form form2("form2",100,100);

    std::cout << *John << std::endl;
    std::cout << form1 << std::endl;

    try
    {
        form1.beSigned(*John);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << form1 << std::endl;

    try
    {
        form1.beSigned(*John);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        John->demote();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        form2.beSigned(*John);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << form2 << std::endl;
    delete John;
}