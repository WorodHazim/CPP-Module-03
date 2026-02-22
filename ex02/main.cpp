/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:02:44 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/18 16:02:45 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "----- Create FragTrap -----" << std::endl;
    FragTrap f("Fraggy");

    std::cout << "\n----- Attack test -----" << std::endl;
    f.attack("Target");

    std::cout << "\n----- High five -----" << std::endl;
    f.highFivesGuys();

    std::cout << "\n----- Copy test -----" << std::endl;
    FragTrap f2(f);
    f2.attack("Another target");

    std::cout << "\n----- End of main -----" << std::endl;
    return 0;
}
