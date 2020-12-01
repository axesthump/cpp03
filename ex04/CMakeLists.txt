cmake_minimum_required(VERSION 3.17)
project(ex04)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex04 main.cpp ClapTrap.cpp ClapTrap.hpp FragTrap.cpp FragTrap.hpp ScavTrap.cpp ScavTrap.hpp NinjaTrap.cpp NinjaTrap.hpp SuperTrap.cpp SuperTrap.hpp)