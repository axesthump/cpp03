//
// Created by casubmar on 29.11.2020.
//

#ifndef EX03_NINJATRAP_HPP
#define EX03_NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap {

public:
	NinjaTrap();
	NinjaTrap(std::string name);
	~NinjaTrap();
	NinjaTrap(NinjaTrap const& src);
	NinjaTrap& operator=(NinjaTrap const& rhs);

	void ninjaShoebox(ClapTrap& target);
	void ninjaShoebox(FragTrap& target);
	void ninjaShoebox(ScavTrap& target);
	void ninjaShoebox(NinjaTrap& target);
};



#endif //EX03_NINJATRAP_HPP
