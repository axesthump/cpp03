//
// Created by casubmar on 25.11.2020.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(): 	_name(""), _armorDmgReduction(5),
						_energyPoints(100), _maxEnergyPoints(100),
						_hp(100), _lvl(1), _maxHp(100), _meleeAttackDmg(30),
						_rangedAttackDmg(20), _vertuhaDmg(45), _runAwayAttackDmg(0),
						_absoluteBlowDmg(69), _kissDmg(5), _superMegaPunchDmg(100) {
	std::srand(time(NULL));
	this->_diedMsg = "This FR4G-TP " + this->_name + " dead...";
	std::cout << "Default constructor FR4G-TP\n";
}

FragTrap::FragTrap(std::string name): _name(name), _armorDmgReduction(5),
									  _energyPoints(100), _maxEnergyPoints(100),
									  _hp(100), _lvl(1), _maxHp(100), _meleeAttackDmg(30),
									  _rangedAttackDmg(20), _vertuhaDmg(45), _runAwayAttackDmg(0),
									  _absoluteBlowDmg(69), _kissDmg(5), _superMegaPunchDmg(100) {
	std::srand(time(NULL));
	this->_diedMsg = "This FR4G-TP " + this->_name + " dead...\n";
}


FragTrap::FragTrap(const FragTrap &src) {
	std::srand(time(NULL));
	*this = src;
}

FragTrap & FragTrap::operator=(const FragTrap &rhs) {
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
		this->_superMegaPunchDmg = rhs.getSuperMegaPunchDmg();
		this->_absoluteBlowDmg = rhs.getAbsoluteBlowDmg();
		this->_kissDmg = rhs.getKissDmg();
		this->_vertuhaDmg = rhs.getVertuhaDmg();
		this->_runAwayAttackDmg = rhs.getRunAwayAttackDmg();
	}
}

FragTrap::~FragTrap() {
	std::cout << "Destructor FR4G-TP\n";
}

int FragTrap::getLvl() const { return this->_lvl; }
int FragTrap::getMaxHp() const { return this->_maxHp; }
int FragTrap::getHp() const { return this->_hp; }
int FragTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
int FragTrap::getMeleeAttackDmg() const { return this->_meleeAttackDmg; }
int FragTrap::getArmorDmgReduction() const { return this->_armorDmgReduction; }
int FragTrap::getRangedAttackDmg() const { return this->_rangedAttackDmg; }
int FragTrap::getEnergyPoints() const { return this->_energyPoints; }
int FragTrap::getVertuhaDmg() const { return this->_vertuhaDmg; }
int FragTrap::getSuperMegaPunchDmg() const { return this->_superMegaPunchDmg; }
int FragTrap::getKissDmg() const { return this->_kissDmg; }
int FragTrap::getRunAwayAttackDmg() const { return this->_runAwayAttackDmg; }
int FragTrap::getAbsoluteBlowDmg() const { return this->_absoluteBlowDmg; }
std::string FragTrap::getName() const { return this->_name; }

int FragTrap::rangedAttack(const std::string &target) const {
	if (this->_hp > 0) {
		std::cout << "FR4G-TP " << this->_name << " attacks "
				  << target << " at range, causing " << this->_rangedAttackDmg <<" points of damage!\n";
		return this->_rangedAttackDmg;
	}
	else {
		std::cout << this->_diedMsg;
		return 0;
	}
}

int FragTrap::meleeAttack(const std::string &target) const {
	if (this->_hp > 0) {
		std::cout << "FR4G-TP " << this->_name << " attacks "
				  << target << " at melee, causing " << this->_meleeAttackDmg <<" points of damage!\n";
		return this->_meleeAttackDmg;
	}
	else {
		std::cout << this->_diedMsg;
		return 0;
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		amount = amount <= 0 ? 5 : amount;
		if ((this->_hp -= (amount - this->_armorDmgReduction)) <= 0) {
			this->_hp = 0;
			std::cout << "This FR4G-TP " << this->_name << " now DEAD!\n";
		} else {
			std::cout << "This FR4G-TP " << this->_name << " take DMG and now have " << this->_hp << " HP" << std::endl;
		}
	} else {
		std::cout << this->_diedMsg;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp += amount;
		this->_energyPoints += amount;
		if (this->_hp > this->_maxHp)
			this->_hp = this->_maxHp;
		if (this->_energyPoints > this->_maxEnergyPoints)
			this->_energyPoints = this->_maxEnergyPoints;
		std::cout << "FR4G-TP " << this->_name << " repair... and now have....HP - " << this->_hp <<
				" and Energy -  " << this->_energyPoints << std::endl;
	} else {
		std::cout << this->_diedMsg;
	}
}

int FragTrap::vertuha(const std::string &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks "
			  << target << " at vertuha, causing " << this->_vertuhaDmg <<" points of damage!\n";
	return this->_vertuhaDmg;
}

int FragTrap::superMegaPunch(const std::string &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks "
			  << target << " at super mega punch, causing " << this->_superMegaPunchDmg <<" points of damage!\n";
	return this->_superMegaPunchDmg;
}

int FragTrap::absoluteBlow(const std::string &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks "
			  << target << " at absolute blow, causing " << this->_absoluteBlowDmg<<" points of damage!\n";
	return this->_absoluteBlowDmg;
}

int FragTrap::kiss(const std::string &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks "
			  << target << " at kiss, causing " << this->_kissDmg <<" points of damage!\n";
	return this->_kissDmg;
}

int FragTrap::runAwayAttack(const std::string &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks "
			  << target << " at runAwayAttack, causing " << this->_runAwayAttackDmg <<" points of damage!\n";
	return this->_runAwayAttackDmg;
}

int FragTrap::vaulthunter_dot_exe(const std::string &target) {
	if (this->_energyPoints) {
		typedef int (FragTrap::*Attacks)(const std::string &target);
		Attacks superAttacks[5] = {&FragTrap::vertuha, &FragTrap::superMegaPunch,
								   &FragTrap::absoluteBlow, &FragTrap::kiss, &FragTrap::runAwayAttack};
		this->_energyPoints -= 25;
		std::cout << "FR4G-TP " << this->_name << " prepares to attack and spends 25 energy, now he has "
		<< this->_energyPoints << std::endl;
		return ((this->*superAttacks[rand() % 5])(target));
	} else {
		std::cout << "FR4G-TP " << this->_name << " have not energy!\n";
		return 0;
	}
}