//
// Created by Cave Submarine on 11/27/20.
//

#ifndef EX01_SCAVTRAP_HPP
#define EX01_SCAVTRAP_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class ScavTrap {

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const& src);
	ScavTrap& operator=(ScavTrap const& rhs);
	~ScavTrap();

	int rangedAttack(std::string const& target) const;
	int meleeAttack(std::string const& target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer();


	int	getHp() const;
	int getMaxHp() const;
	int getEnergyPoints() const;
	int getMaxEnergyPoints() const;
	int getLvl() const;
	int getMeleeAttackDmg() const;
	int getRangedAttackDmg() const;
	int getArmorDmgReduction() const;

	std::string getName() const;


private:
	int			_hp;
	int 		_maxHp;
	int 		_energyPoints;
	int 		_maxEnergyPoints;
	int 		_lvl;
	int 		_meleeAttackDmg;
	int 		_rangedAttackDmg;
	int 		_armorDmgReduction;
	std::string _name;
	std::string _diedMsg;

};


#endif //EX01_SCAVTRAP_HPP
