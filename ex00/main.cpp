/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:01:51 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/21 20:35:38 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a("A");

    std::cout << "----- TEST 1: basic actions -----" << std::endl;
    a.attack("Target1");
    a.takeDamage(3);
    a.beRepaired(5);

    std::cout << "\n----- TEST 2: energy runs out -----" << std::endl;
    a.attack("Target2");
    a.attack("Target3");
    a.attack("Target4");
    a.attack("Target5");
    a.attack("Target6");
    a.attack("Target7");
    a.attack("Target8");
    a.attack("Target9");
    a.attack("Target10");
    a.attack("Target11");
    a.beRepaired(1); 

    std::cout << "\n----- TEST 3: dead claptrap -----" << std::endl;
    a.takeDamage(999);
    a.attack("Target12");
    a.beRepaired(1);
    std::cout << "\n----- TEST 4: copy / assign -----" << std::endl;

    ClapTrap b(a); 
    b.attack("CopyTarget");

    ClapTrap c("C");
    c = a; 
    c.attack("AssignTarget");

    return 0;
}
