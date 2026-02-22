/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:02:19 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/18 16:02:20 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
class ScavTrap : public ClapTrap
{
public:
ScavTrap(const std::string& name);
ScavTrap(const ScavTrap& other);
ScavTrap& operator=(const ScavTrap& other);
~ScavTrap();
void attack(const std::string& target);
void guardGate();

};
#endif
