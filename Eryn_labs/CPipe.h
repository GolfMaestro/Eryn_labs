#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

class CPipe
{
public:
    int id;
    static int MaxId;
    std::string name;
    double length;
    int diameter;
    bool reparied;

    CPipe();

    friend  std::ostream& operator << (std::ostream& out, const CPipe& p);
    friend std::istream& operator >> (std::istream& in, CPipe& p);
    void edit_pipe();
    CPipe& select_pipe(std::vector<CPipe>& pipes);

};
