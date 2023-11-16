#pragma once
#include <iostream>
#include "CStation.h"
#include <string>
#include <vector>
#include "utils.h"

int CStation::MaxId = 0;

CStation::CStation() {
    id = MaxId++;
}

void CStation::edit_station() {
    int command;
    std::cout << "Enter number of working workshops" << std::endl;
    number_of_working_workshops = get_correct_number(0, number_of_workshops);
    std::cout << "Station name: " << name << "  Number of working workshops: " << number_of_working_workshops << std::endl;
}

std::ostream& operator<<(std::ostream& out, const CStation& s) {
    out << "Id: " << s.id
        << "\tName: " << s.name
        << "\tNumber of workshops: " << s.number_of_workshops
        << "\tNumber of working workshops: " << s.number_of_working_workshops
        << "\tEffectiveness: " << s.effectiveness << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, CStation& s) {
    std::cout << "Oil station" << std::endl;
    std::cout << "Name: ";
    std::cin.ignore(1000, '\n');
    getline(std::cin, s.name);
    std::cout << "Number of workshops" << std::endl;
    s.number_of_workshops = get_correct_number(1, 1000);
    std::cout << "Number of working workshops" << std::endl;
    s.number_of_working_workshops = get_correct_number(0, s.number_of_workshops);
    std::cout << "Effectiveness" << std::endl;
    s.effectiveness = get_correct_number(0, 100);
    return in;
}

CStation& select_station(std::unordered_map<int, CStation>& stations) {
    std::cout << "Enter id" << std::endl;
    int id = get_correct_number(0, CStation::MaxId - 1);
    for (auto& i : stations) if (i.first == id) return i.second;
}

