/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:50 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/22 14:08:43 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Create DiamondTrap -----" << std::endl;
    DiamondTrap d1("Diamond");

    std::cout << "\n----- whoAmI -----" << std::endl;
    d1.whoAmI();

    std::cout << "\n----- attack (should use ScavTrap) -----" << std::endl;
    d1.attack("Enemy");

    std::cout << "\n----- inherited abilities -----" << std::endl;
    d1.guardGate();      
    d1.highFivesGuys();  

    std::cout << "\n----- Copy test -----" << std::endl;
    DiamondTrap d2(d1);
    d2.whoAmI();
    d2.attack("Enemy2");

    std::cout << "\n----- Assignment test -----" << std::endl;
    DiamondTrap d3("Temp");
    d3 = d1;
    d3.whoAmI();

    std::cout << "\n----- End -----" << std::endl;
    return 0;
}