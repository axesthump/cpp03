//
// Created by Cave Submarine on 11/27/20.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): 	_name(""), _armorDmgReduction(3),
						 _energyPoints(50), _maxEnergyPoints(50),
						 _hp(100), _lvl(1), _maxHp(100), _meleeAttackDmg(20),
						 _rangedAttackDmg(15) {
	std::srand(time(NULL));
	this->_diedMsg = "This SC4V-TP " + this->_name + " dead...";
	std::cout << "Default constructor SC4V-TP\n";
}

ScavTrap::ScavTrap(std::string name): _name(name), _armorDmgReduction(3),
									  _energyPoints(50), _maxEnergyPoints(50),
									  _hp(100), _lvl(1), _maxHp(100), _meleeAttackDmg(20),
									  _rangedAttackDmg(15) {
	std::srand(time(NULL));
	this->_diedMsg = "This SC4V-TP " + this->_name + " dead...\n";
}


ScavTrap::ScavTrap(const ScavTrap &src) {
	std::srand(time(NULL));
	*this = src;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &rhs) {
	if (this != &rhs) {
		this->_rangedAttackDmg = rhs.getRangedAttackDmg();
		this->_meleeAttackDmg = rhs.getMeleeAttackDmg();
		this->_name = rhs.getName();
		this->_armorDmgReduction = rhs.getArmorDmgReduction();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
		this->_hp = rhs.getHp();
		this->_maxHp = rhs.getMaxHp();
		this->_lvl = rhs.getLvl();
	}
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor SC4V-TP\n";
}

int ScavTrap::getLvl() const { return this->_lvl; }
int ScavTrap::getMaxHp() const { return this->_maxHp; }
int ScavTrap::getHp() const { return this->_hp; }
int ScavTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
int ScavTrap::getMeleeAttackDmg() const { return this->_meleeAttackDmg; }
int ScavTrap::getArmorDmgReduction() const { return this->_armorDmgReduction; }
int ScavTrap::getRangedAttackDmg() const { return this->_rangedAttackDmg; }
int ScavTrap::getEnergyPoints() const { return this->_energyPoints; }
std::string ScavTrap::getName() const { return this->_name; }

int ScavTrap::rangedAttack(const std::string &target) const {
	if (this->_hp > 0) {
		std::cout << "SC4V-TP " << this->_name << " attacks "
				  << target << " at range, causing " << this->_rangedAttackDmg <<" points of damage!\n";
		return this->_rangedAttackDmg;
	}
	else {
		std::cout << this->_diedMsg;
		return 0;
	}
}

int ScavTrap::meleeAttack(const std::string &target) const {
	if (this->_hp > 0) {
		std::cout << "SC4V-TP " << this->_name << " attacks "
				  << target << " at melee, causing " << this->_meleeAttackDmg <<" points of damage!\n";
		return this->_meleeAttackDmg;
	}
	else {
		std::cout << this->_diedMsg;
		return 0;
	}
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		amount = amount <= 0 ? 3 : amount;
		if ((this->_hp -= (amount - this->_armorDmgReduction)) <= 0) {
			this->_hp = 0;
			std::cout << "This SC4V-TP " << this->_name << " now DEAD!\n";
		} else {
			std::cout << "This SC4V-TP " << this->_name << " take DMG and now have " << this->_hp << " HP" << std::endl;
		}
	} else {
		std::cout << this->_diedMsg;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp += amount;
		this->_energyPoints += amount;
		if (this->_hp > this->_maxHp)
			this->_hp = this->_maxHp;
		if (this->_energyPoints > this->_maxEnergyPoints)
			this->_energyPoints = this->_maxEnergyPoints;
		std::cout << "SC4V-TP " << this->_name << " repair... and now have....HP - " << this->_hp <<
				  " and Energy -  " << this->_energyPoints << std::endl;
	} else {
		std::cout << this->_diedMsg;
	}
}

void ScavTrap::challengeNewcomer() const {
	if (this->_hp) {
		std::string challenges[5] = {
				this->_name + ": Now you need eat some filthy.....\n",
				this->_name + ": Now you need do five somersaults ... that's the way\n",
				this->_name + ": Now you need reach the elbow with your tongue\n",
				this->_name + ": Now you need to shave the gorilla\n",
				this->_name + ": Now you need to sleep ... in lava\n"
		};
		std::cout << challenges[rand() % 5];
	} else {
		std::cout << this->_diedMsg;
	}
}