//
// Created by Cave Submarine on 11/27/20.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::srand(time(NULL));
	setDieMsg("This SC4V-TP " + this->getName() + " dead...\n");
	setType("SC4V-TP");
	setArmorDmgReduction(3);
	setEnergyPoints(50);
	setMaxEnergyPoints(50);
	setHp(100);
	setLvl(1);
	setMaxHp(100);
	setMeleeAttackDmg(20);
	setRangedAttackDmg(15);
	std::cout << "Default constructor SC4V-TP\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap() {
	std::srand(time(NULL));
	setName(name);
	setDieMsg("This SC4V-TP " + this->getName() + " dead...");
	setType("SC4V-TP");
	setArmorDmgReduction(3);
	setEnergyPoints(50);
	setMaxEnergyPoints(50);
	setHp(100);
	setLvl(1);
	setMaxHp(100);
	setMeleeAttackDmg(20);
	setRangedAttackDmg(15);
	std::cout << "Default constructor SC4V-TP\n";
}


ScavTrap::ScavTrap(const ScavTrap &src) {
	std::srand(time(NULL));
	*this = src;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &rhs) {
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

ScavTrap::~ScavTrap() {
	std::cout << "Destructor SC4V-TP\n";
}

void ScavTrap::challengeNewcomer() {
	if (getHp() && getEnergyPoints()) {
		std::string challenges[5] = {
				getName() + ": Now you need eat some filthy.....\n",
				getName() + ": Now you need do five somersaults ... that's the way\n",
				getName() + ": Now you need reach the elbow with your tongue\n",
				getName() + ": Now you need to shave the gorilla\n",
				getName() + ": Now you need to sleep ... in lava\n"
		};
		setEnergyPoints(getEnergyPoints() - 25);
		std::cout << "SC4V-TP " << getName() << " prepares to attack and spends 25 energy, now he has "
				  << getEnergyPoints() << std::endl;
		std::cout << challenges[rand() % 5];
	} else {
		if (!getHp())
			std::cout << getDieMsg();
		else
			std::cout << "SC4V-TP " << getName() << " have not energy!\n";
	}
}