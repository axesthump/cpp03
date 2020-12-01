#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap frag("C3PO");
	ScavTrap scav("R2D2");
	while (scav.getHp() && frag.getHp()) {
		scav.takeDamage(frag.vaulthunter_dot_exe(scav.getName()));
		if (!scav.getHp())
			break;
		scav.challengeNewcomer();
		frag.takeDamage(scav.meleeAttack(frag.getName()));
		if (!frag.getHp())
			break;
		frag.takeDamage(scav.meleeAttack(frag.getName()));
		if (!frag.getHp())
			break;
	}
	return 0;
}
