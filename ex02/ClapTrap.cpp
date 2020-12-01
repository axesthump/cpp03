//
// Created by casubmar on 29.11.2020.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():	_name(""), _diedMsg(""), _type("CL4P-TP"), _armorDmgReduction(0),
						 _energyPoints(0), _maxEnergyPoints(0),
						 _hp(0), _lvl(0), _maxHp(0), _meleeAttackDmg(0),
						 _rangedAttackDmg(0) {
	std::cout << "Default constructor CL4P-TP\n";
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &rhs) {
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
		this->_type = rhs.getType();
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor CL4P-TP\n";
}

int ClapTrap::getLvl() const { return this->_lvl; }
int ClapTrap::getMaxHp() const { return this->_maxHp; }
int ClapTrap::getHp() const { return this->_hp; }
int ClapTrap::getMaxEnergyPoints() const { return this->_maxEnergyPoints; }
int ClapTrap::getMeleeAttackDmg() const { return this->_meleeAttackDmg; }
int ClapTrap::getArmorDmgReduction() const { return this->_armorDmgReduction; }
int ClapTrap::getRangedAttackDmg() const { return this->_rangedAttackDmg; }
int ClapTrap::getEnergyPoints() const { return this->_energyPoints; }
std::string ClapTrap::getName() const { return this->_name; }
std::string ClapTrap::getDieMsg() const { return this->_diedMsg; }
std::string ClapTrap::getType() const { return this->_type; }

void ClapTrap::setLvl(int n) { this->_lvl = n; }
void ClapTrap::setMaxHp(int n) { this->_maxHp = n; }
void ClapTrap::setHp(int n) { this->_hp = n; }
void ClapTrap::setMaxEnergyPoints(int n) { this->_maxEnergyPoints = n; }
void ClapTrap::setMeleeAttackDmg(int n) { this->_meleeAttackDmg = n; }
void ClapTrap::setArmorDmgReduction(int n) { this->_armorDmgReduction = n; }
void ClapTrap::setRangedAttackDmg(int n) { this->_rangedAttackDmg = n; }
void ClapTrap::setEnergyPoints(int n) { this->_energyPoints = n > 0 ? n : 0; }
void ClapTrap::setName(std::string s) { this->_name = s; }
void ClapTrap::setDieMsg(std::string s) { this->_diedMsg = s; }
void ClapTrap::setType(std::string s) { this->_type = s; }

int ClapTrap::rangedAttack(const std::string &target) const {
	if (this->_hp > 0) {
		std::cout << this->_type << " " << this->_name << " attacks "
				  << target << " at range, causing " << this->_rangedAttackDmg <<" points of damage!\n";
		return this->_rangedAttackDmg;
	}
	else {
		std::cout << this->_diedMsg;
		return 0;
	}
}

int ClapTrap::meleeAttack(const std::string &target) const {
	if (this->_hp > 0) {
		std::cout << this->_type << " " << this->_name << " attacks "
				  << target << " at melee, causing " << this->_meleeAttackDmg <<" points of damage!\n";
		return this->_meleeAttackDmg;
	}
	else {
		std::cout << this->_diedMsg;
		return 0;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		amount = amount <= 0 ? this->_armorDmgReduction : amount;
		if ((this->_hp -= (amount - this->_armorDmgReduction)) <= 0) {
			this->_hp = 0;
			std::cout << "This " << this->_type << " " << this->_name << " now DEAD!\n";
		} else {
			std::cout << "This " << this->_type << " " << this->_name << " take DMG and now have " << this->_hp << " HP" << std::endl;
		}
	} else {
		std::cout << this->_diedMsg;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp += amount;
		this->_energyPoints += amount;
		if (this->_hp > this->_maxHp)
			this->_hp = this->_maxHp;
		if (this->_energyPoints > this->_maxEnergyPoints)
			this->_energyPoints = this->_maxEnergyPoints;
		std::cout << this->_type << " " << this->_name << " repair... and now have....HP - " << this->_hp <<
				  " and Energy -  " << this->_energyPoints << std::endl;
	} else {
		std::cout << this->_diedMsg;
	}
}