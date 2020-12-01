#include <iostream>

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

int main() {
	FragTrap frag("C3PO");
	ScavTrap scav("R2D2");
	ClapTrap clap;
	NinjaTrap n1("Sam");
	NinjaTrap n2("BADSam");

	clap.setName("CLAP");
	clap.setHp(5);
	while (scav.getHp() && frag.getHp() && clap.getHp() && n2.getHp()) {
		n1.ninjaShoebox(scav);
		n1.ninjaShoebox(frag);
		n1.ninjaShoebox(n2);
		n1.ninjaShoebox(clap);
	}
	return 0;
}