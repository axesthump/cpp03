//
// Created by casubmar on 30.11.2020.
//

#ifndef EX04_SUPERTRAP_HPP
#define EX04_SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap {

public:
	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap(SuperTrap const& src);
	SuperTrap& operator=(SuperTrap const& rhs);
	~SuperTrap();

};


#endif //EX04_SUPERTRAP_HPP
