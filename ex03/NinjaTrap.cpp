//
// Created by casubmar on 29.11.2020.
//

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(): ClapTrap() {
	std::srand(time(NULL));
	setDieMsg("This IN4C " + this->getName() + " dead...");
	setType("IN4C");
	setArmorDmgReduction(0);
	setEnergyPoints(120);
	setMaxEnergyPoints(120);
	setHp(60);
	setLvl(1);
	setMaxHp(60);
	setMeleeAttackDmg(60);
	setRangedAttackDmg(5);
	std::cout << "Default constructor IN4C\n";
}

NinjaTrap::NinjaTrap(std::string name): ClapTrap() {
	std::srand(time(NULL));
	setName(name);
	setDieMsg("This IN4C " + this->getName() + " dead...");
	setType("IN4C");
	setArmorDmgReduction(0);
	setEnergyPoints(120);
	setMaxEnergyPoints(120);
	setHp(60);
	setLvl(1);
	setMaxHp(60);
	setMeleeAttackDmg(60);
	setRangedAttackDmg(5);
	std::cout << "Default constructor IN4C\n";
}

NinjaTrap::~NinjaTrap() {
	std::cout << "Destructor IN4C\n";
}

NinjaTrap::NinjaTrap(const NinjaTrap &src) {
	*this = src;
}

NinjaTrap & NinjaTrap::operator=(const NinjaTrap &rhs) {
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

void NinjaTrap::ninjaShoebox(ClapTrap &target) {
	if (getHp() && getEnergyPoints()) {
		int 	dmgs[5] = {10, 20, 30, 40, 50};

		std::cout << "This IN4C " << getName() << " makes strange hand movements and attack "
				  << target.getName() << std::endl;
		target.takeDamage(dmgs[rand() % 5]);
	} else {
		if (!getHp()) {
			std::cout << getDieMsg();
		} else {
			std::cout << "IN4C " << getName() << " have not energy!\n";
		}
	}
}

void NinjaTrap::ninjaShoebox(ScavTrap& target) {
	if (getHp() && getEnergyPoints()) {
		int 	dmgs[5] = {10, 20, 30, 40, 50};

		std::cout << "This IN4C " << getName() << " makes strange hand movements and attack "
				  << target.getName() << std::endl;
		target.takeDamage(dmgs[rand() % 5]);
	} else {
		if (!getHp()) {
			std::cout << getDieMsg();
		} else {
			std::cout << "IN4C " << getName() << " have not energy!\n";
		}
	}
}

void NinjaTrap::ninjaShoebox(FragTrap& target) {
	if (getHp() && getEnergyPoints()) {
		int 	dmgs[5] = {10, 20, 30, 40, 50};

		std::cout << "This IN4C " << getName() << " makes strange hand movements and attack "
				  << target.getName() << std::endl;
		target.takeDamage(dmgs[rand() % 5]);
	} else {
		if (!getHp()) {
			std::cout << getDieMsg();
		} else {
			std::cout << "IN4C " << getName() << " have not energy!\n";
		}
	}
}

void NinjaTrap::ninjaShoebox(NinjaTrap& target) {
	if (getHp() && getEnergyPoints()) {
		int 	dmgs[5] = {10, 20, 30, 40, 50};

		std::cout << "This IN4C " << getName() << " makes strange hand movements and attack "
				  << target.getName() << std::endl;
		target.takeDamage(dmgs[rand() % 5]);
	} else {
		if (!getHp()) {
			std::cout << getDieMsg();
		} else {
			std::cout << "IN4C " << getName() << " have not energy!\n";
		}
	}
}