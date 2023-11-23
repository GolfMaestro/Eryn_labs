#pragma once
#include <iostream>
#include <string>
#include "utils.h"
#include "CPipe.h"

using namespace std;

int CPipe::MaxId = 0;

CPipe::CPipe() {
    id = MaxId++;
}

void CPipe::edit_pipe() {
    repaired = !repaired;
    cout << "Pipe name: " << name << "  Pipe status: (1 - is repaired, 0 - is not repaired): " << repaired << endl;
}

CPipe& CPipe::select_pipe(std::vector<CPipe>& pipes) {
    cout << "Enter id: " << endl;
    int id = get_correct_number(0, CPipe::MaxId - 1);
    for (auto i : pipes) if (i.id == id) return i;
}

int get_correct_diameter() {
    int x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || (x != 500 && x != 700 && x != 1000 && x != 1400))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Type number 500, 700, 1000 or 1400:" << endl;
    }
    return x;
}

ostream& operator << (ostream& out, const CPipe& p) {
    out << "Id: " << p.id
        << "\tName: " << p.name
        << "\tLength: " << p.length
        << "\tDiameter: " << p.diameter
        << "\tRepaired: " << p.repaired << endl;
    return out;
}

istream& operator >> (istream& in, CPipe& p) {
    cout << "Oil pipe" << endl;
    cout << "Name: ";
    in.ignore(1000, '\n');
    getline(in, p.name);
    cout << "Length" << endl;
    p.length = get_correct_number(1.0, 1000.0);
    cout << "Diameter. Type number 500, 700, 1000 or 1400:" << endl;
    p.diameter = get_correct_diameter();
    cout << "Is repaired (1 - yes, 0 - no): " << endl;
    p.repaired = get_correct_number(0, 1);
    return in;
}

