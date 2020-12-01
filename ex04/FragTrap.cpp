//
// Created by casubmar on 25.11.2020.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(): 	ClapTrap(), _vertuhaDmg(45), _runAwayAttackDmg(0),
						 _absoluteBlowDmg(69), _kissDmg(5), _superMegaPunchDmg(100) {
	std::srand(time(NULL));
	setType("FR4G-TP");
	setDieMsg("This " + getType() + " " + this->getName() + " dead...\n");
	setArmorDmgReduction(5);
	setEnergyPoints(100);
	setMaxEnergyPoints(100);
	setHp(100);
	setLvl(1);
	setMaxHp(100);
	setMeleeAttackDmg(30);
	setRangedAttackDmg(20);
	std::cout << "Default constructor FR4G-TP\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(), _vertuhaDmg(45), _runAwayAttackDmg(0),
									  _absoluteBlowDmg(69), _kissDmg(5), _superMegaPunchDmg(100) {
	std::srand(time(NULL));
	setName(name);
	setType("FR4G-TP");
	setDieMsg("This " + getType() + " " + this->getName() + " dead...\n");
	setArmorDmgReduction(5);
	setEnergyPoints(100);
	setMaxEnergyPoints(100);
	setHp(100);
	setLvl(1);
	setMaxHp(100);
	setMeleeAttackDmg(30);
	setRangedAttackDmg(20);
	std::cout << "Default constructor FR4G-TP\n";
}


FragTrap::FragTrap(const FragTrap &src) {
	std::srand(time(NULL));
	*this = src;
}

FragTrap & FragTrap::operator=(const FragTrap &rhs) {
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

int FragTrap::getVertuhaDmg() const { return this->_vertuhaDmg; }
int FragTrap::getSuperMegaPunchDmg() const { return this->_superMegaPunchDmg; }
int FragTrap::getKissDmg() const { return this->_kissDmg; }
int FragTrap::getRunAwayAttackDmg() const { return this->_runAwayAttackDmg; }
int FragTrap::getAbsoluteBlowDmg() const { return this->_absoluteBlowDmg; }


int FragTrap::vertuha(const std::string &target) {
	std::cout << getType() << " " << getName() << " attacks "
			  << target << " at vertuha, causing " << this->_vertuhaDmg <<" points of damage!\n";
	return this->_vertuhaDmg;
}

int FragTrap::superMegaPunch(const std::string &target) {
	std::cout << getType() << " " << getName() << " attacks "
			  << target << " at super mega punch, causing " << this->_superMegaPunchDmg <<" points of damage!\n";
	return this->_superMegaPunchDmg;
}

int FragTrap::absoluteBlow(const std::string &target) {
	std::cout << getType() << " " << getName() << " attacks "
			  << target << " at absolute blow, causing " << this->_absoluteBlowDmg<<" points of damage!\n";
	return this->_absoluteBlowDmg;
}

int FragTrap::kiss(const std::string &target) {
	std::cout << getType() << " " << getName() << " attacks "
			  << target << " at kiss, causing " << this->_kissDmg <<" points of damage!\n";
	return this->_kissDmg;
}

int FragTrap::runAwayAttack(const std::string &target) {
	std::cout << getType() << " " << getName() << " attacks "
			  << target << " at runAwayAttack, causing " << this->_runAwayAttackDmg <<" points of damage!\n";
	return this->_runAwayAttackDmg;
}

int FragTrap::vaulthunter_dot_exe(const std::string &target) {
	if (getEnergyPoints() && getHp()) {
		typedef int (FragTrap::*Attacks)(const std::string &target);
		Attacks superAttacks[5] = {&FragTrap::vertuha, &FragTrap::superMegaPunch,
								   &FragTrap::absoluteBlow, &FragTrap::kiss, &FragTrap::runAwayAttack};
		setEnergyPoints(getEnergyPoints() - 25);
		std::cout << getType() << " " << getName() << " prepares to attack and spends 25 energy, now he has "
				  << getEnergyPoints() << std::endl;
		return ((this->*superAttacks[rand() % 5])(target));
	} else {
		if (!getEnergyPoints())
			std::cout << getType() << " " << getName() << " have not energy!\n";
		else
			std::cout << getDieMsg() << std::endl;
		return 0;
	}
}//
// Created by casubmar on 30.11.2020.
//

#include "FragTrap.hpp"
