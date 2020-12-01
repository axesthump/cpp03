//
// Created by casubmar on 25.11.2020.
//

#ifndef EX00_FRAGTRAP_HPP
#define EX00_FRAGTRAP_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const& src);
	FragTrap& operator=(FragTrap const& rhs);
	~FragTrap();

	int vaulthunter_dot_exe(std::string const& target);
	int getVertuhaDmg() const;
	int getSuperMegaPunchDmg() const;
	int getKissDmg() const;
	int getRunAwayAttackDmg() const;
	int getAbsoluteBlowDmg() const;


private:
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
