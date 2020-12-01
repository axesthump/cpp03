//
// Created by casubmar on 29.11.2020.
//

#ifndef EX02_CLAPTRAP_HPP
#define EX02_CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

public:
	ClapTrap();
	ClapTrap(ClapTrap const& src);
	ClapTrap& operator=(ClapTrap const& rhs);
	~ClapTrap();
	int rangedAttack(std::string const& target) const;
	int meleeAttack(std::string const& target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int	getHp() const;
	int getMaxHp() const;
	int getEnergyPoints() const;
	int getMaxEnergyPoints() const;
	int getLvl() const;
	int getMeleeAttackDmg() const;
	int getRangedAttackDmg() const;
	int getArmorDmgReduction() const;

	std::string getDieMsg() const;
	std::string getName() const;
	std::string getType() const;

	void setHp(int n);
	void setMaxHp(int n);
	void setEnergyPoints(int n);
	void setMaxEnergyPoints(int n);
	void setLvl(int n);
	void setMeleeAttackDmg(int n);
	void setRangedAttackDmg(int n);
	void setArmorDmgReduction(int n);
	void setName(std::string s);
	void setDieMsg(std::string s);
	void setType(std::string s);

private:
	int			_hp;
	int 		_maxHp;
	int 		_energyPoints;
	int 		_maxEnergyPoints;
	int 		_lvl;
	int 		_meleeAttackDmg;
	int 		_rangedAttackDmg;
	int 		_armorDmgReduction;
	std::string _type;
	std::string _name;
	std::string _diedMsg;
};


#endif //EX02_CLAPTRAP_HPP
