//
// Created by casubmar on 30.11.2020.
//

#include "SuperTrap.hpp"

SuperTrap::SuperTrap() {
	std::cout << "Default constructor SUPER-TR4P\n";
	setType("SUPER-TR4P");
	setDieMsg("This " + getType() + " " + this->getName() + " dead...\n");
	setHp(100);
	setMaxHp(100);
	setEnergyPoints(120);
	setMaxEnergyPoints(120);
	setMeleeAttackDmg(60);
	setRangedAttackDmg(20);
	setArmorDmgReduction(5);
}

SuperTrap::SuperTrap(std::string name) {
	setType("SUPER-TR4P");
	setName(name);
	setDieMsg("This " + getType() + " " + this->getName() + " dead...\n");
	setHp(100);
	setMaxHp(100);
	setEnergyPoints(120);
	setMaxEnergyPoints(120);
	setMeleeAttackDmg(60);
	setRangedAttackDmg(20);
	setArmorDmgReduction(5);
	std::cout << "Default constructor SUPER-TR4P\n";
}

SuperTrap::SuperTrap(const SuperTrap &src) {
	*this = src;
}

SuperTrap & SuperTrap::operator=(const SuperTrap &rhs) {
	if (this != &rhs) {
		setRangedAttackDmg(rhs.getRangedAttackDmg());
		setMeleeAttackDmg(rhs.getMeleeAttackDmg());
		setName(rhs.getName());
		setArmorDmgReduction(rhs.getArmorDmgReduction());
		setEnergyPoints(rhs.getEnergyPoints());
		setMaxEnergyPoints(rhs.getMaxEnergyPoints());
		setHp(rhs.getHp());
		setMaxHp(rhs.getMaxHp());
		setLvl(rhs.getLvl());
	}
}

SuperTrap::~SuperTrap() {
	std::cout << "Destructor SUPER-TR4P\n";
}