/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:02:05 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/22 11:08:08 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Creating ScavTrap -----" << std::endl;
    ScavTrap s1("Scavy");

    std::cout << "\n----- Attack test -----" << std::endl;
    s1.attack("Target");

    std::cout << "\n----- Special ability -----" << std::endl;
    s1.guardGate();

    std::cout << "\n----- Copy test -----" << std::endl;
    ScavTrap s2(s1);
    s2.attack("Another target");

    std::cout << "\n----- Assignment test -----" << std::endl;
    ScavTrap s3("Temp");
    s3 = s1;
    s3.attack("Assigned target");

    std::cout << "\n----- End of main -----" << std::endl;
    return 0;
}
