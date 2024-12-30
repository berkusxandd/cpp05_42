/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:43:55 by bince             #+#    #+#             */
/*   Updated: 2024/12/30 13:43:56 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *Mbappe = new Bureaucrat("Mbappe", 5);
	Bureaucrat *John = new Bureaucrat("John", 146);

    std::cout << *Mbappe << std::endl;
    std::cout << *John << std::endl;
    try 
    {
        Mbappe->promote();
    }
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

     try 
    {
        Mbappe->promote();
    }
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

     try 
    {
        Mbappe->promote();
    }
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

     try 
    {
        Mbappe->promote();
    }
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

     try 
    {
        Mbappe->promote();
    }
	catch (const std::exception& e) {
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
        John->demote();
    }
    catch(const std::exception& e)
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
        John->demote();
    }
    catch(const std::exception& e)
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

    delete Mbappe;
    delete John;
}