#include <iostream>
#include "FragTrap.hpp"

int main() {
	FragTrap first("CL4P-TP");
	FragTrap* second = new FragTrap("Beer");

	while (second->getHp() > 0) {
		second->takeDamage(first.meleeAttack(second->getName()));
		if (!second->getHp()) {
			delete second;
			break;
		}
		second->takeDamage(first.rangedAttack(second->getName()));
		if (!second->getHp()) {
			delete second;
			break;
		}
		second->takeDamage(first.vaulthunter_dot_exe(second->getName()));
		if (!second->getHp()) {
			delete second;
			break;
		}
		second->takeDamage(first.vaulthunter_dot_exe(second->getName()));
		if (!second->getHp()) {
			delete second;
			break;
		}
		second->takeDamage(first.vaulthunter_dot_exe(second->getName()));
		if (!second->getHp()) {
			delete second;
			break;
		}
	}
	first.vaulthunter_dot_exe("NOTHING");
	first.vaulthunter_dot_exe("NOTHING");
	first.vaulthunter_dot_exe("NOTHING");
	first.vaulthunter_dot_exe("NOTHING");
	first.vaulthunter_dot_exe("NOTHING");
	first.beRepaired(110);
	first.vaulthunter_dot_exe("NOTHING");
	return 0;
}
