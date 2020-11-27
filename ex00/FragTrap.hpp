//
// Created by casubmar on 25.11.2020.
//

#ifndef EX00_FRAGTRAP_HPP
#define EX00_FRAGTRAP_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class FragTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const& src);
	FragTrap& operator=(FragTrap const& rhs);
	~FragTrap();

	int rangedAttack(std::string const& target) const;
	int meleeAttack(std::string const& target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int vaulthunter_dot_exe(std::string const& target);

	int	getHp() const;
	int getMaxHp() const;
	int getEnergyPoints() const;
	int getMaxEnergyPoints() const;
	int getLvl() const;
	int getMeleeAttackDmg() const;
	int getRangedAttackDmg() const;
	int getArmorDmgReduction() const;
	int getVertuhaDmg() const;
	int getSuperMegaPunchDmg() const;
	int getKissDmg() const;
	int getRunAwayAttackDmg() const;
	int getAbsoluteBlowDmg() const;

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
	int			_vertuhaDmg;
	int			_superMegaPunchDmg;
	int			_kissDmg;
	int			_runAwayAttackDmg;
	int			_absoluteBlowDmg;

	int superMegaPunch(std::string const& target);
	int absoluteBlow(std::string const& target);
	int kiss(std::string const& target);
	int runAwayAttack(std::string const& target);
	int vertuha(std::string const& target);

};


#endif //EX00_FRAGTRAP_HPP
