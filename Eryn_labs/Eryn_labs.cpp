#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include "CPipe.h"
#include "CStation.h"
#include "utils.h"
using namespace std;

template<typename T>
void add_object(unordered_map<int, T>& objects) {
    T obj;
    cin >> obj;
    objects.insert({ obj.id, obj });
}

void show_objects(unordered_map<int, CPipe>& pipes, unordered_map<int, CStation>& stations) {

    if (pipes.size() > 0) {
        cout << "Pipes: " << endl;
        for (auto& i : pipes) cout << i.second << endl;
    }
    else cout << "Pipes doesn't exist\n";

    if (stations.size() > 0) {
        cout << "Stations: " << endl;
        for (auto& i : stations) cout << i.second << endl;
    }
    else cout << "Stations doesn't exist\n";

}

void edit_pipes(unordered_map<int, CPipe>& pipes) {

    set<int> pipes_to_edit;

    if (pipes.size() > 0) {
        cout << "Edit all pipes - 0, choose pipes to edit - 1" << endl;
        if (get_correct_number(0, 1)) {
            while (true) {
                cout << "0 - stop, 1 - continue" << endl;
                if (get_correct_number(0, 1)) {
                    cout << "Enter id: " << endl;
                    pipes_to_edit.insert(get_correct_number(0, CPipe::MaxId));
                }
                else break;
            }
            for (auto i : pipes_to_edit) for (auto& j : pipes) if (j.second.id == i) j.second.edit_pipe();
        }
        else for (auto& i : pipes) i.second.edit_pipe();
    }
    else cout << "Pipes doesn't exist\n";

}

void edit_stations(unordered_map<int, CStation>& stations) {

    if (stations.size() > 0) (select_station(stations)).edit_station();
    else cout << "Station doesn't exist\n";

}

void delete_object(unordered_map<int, CPipe>& pipes, unordered_map<int, CStation>& stations) {

    show_objects(pipes, stations);
    int id;
    cout << "Delete pipe - 0, delete station - 1" << endl;
    int command = get_correct_number(0, 1);

    if (command && stations.size() > 0) {
        cout << "Enter id" << endl;
        id = get_correct_number(0, CStation::MaxId - 1);
        erase(stations, id);
    }
    else if (command && stations.size() == 0) cout << "Stations doesn't exist\n";
    if (!command && pipes.size() > 0) {
        cout << "Enter id" << endl;
        id = get_correct_number(0, CPipe::MaxId - 1);
        erase(pipes, id);
    }
    else if (!command && pipes.size() == 0) cout << "Pipes doesn't exist\n";

}

template<typename T>
using PFilter = bool(*)(const CPipe& s, T param);

template<typename T>
using SFilter = bool(*)(const CStation& s, T param);

template <typename T>
unordered_map<int, CPipe> find_pipe_by_filter(const unordered_map<int, CPipe>& objects, PFilter<T> f, T param) {
    unordered_map<int, CPipe> res;
    for (auto s : objects) if (f(s.second, param)) res.insert({ s.first, s.second });
    if (res.size() == 0) cout << "Pipes with such parameters doesn't exist\n";
    return res;
}

template <typename T>
unordered_map<int, CStation> find_station_by_filter(const unordered_map<int, CStation>& objects, SFilter<T> f, T param) {
    unordered_map<int, CStation> res;
    for (auto& s : objects) if (f(s.second, param)) res.insert(s);
    if (res.size() == 0) cout << "Stations with such parameters doesn't exist\n";
    return res;
}

template<typename T>
bool check_by_name(const T& s, string param)
{
    bool found = s.name.find(param) != string::npos;
    return found;
}

bool check_by_repaired(const CPipe& s, bool param)
{
    return s.repaired == param;
}

bool check_by_working_workshops(const CStation& s, double target)
{
    double wg = s.number_of_working_workshops;
    double g = s.number_of_workshops;
    return ((g - wg) / g) * 100 == target;
}

void find_pipe(const unordered_map<int, CPipe>& pipes) {

    if (pipes.size() == 0) {
        cout << "Pipes doesn't exist\n";
    }

    string name;
    int command;
    bool status;
    cout << "Find pipe by name - 0, find pipe by reparied status - 1 :" << endl;
    command = get_correct_number(0, 1);

    if (command) {
        cout << "Enter reparied status (0 - no, 1 - yes): " << endl;
        cin >> status;
        for (auto i : find_pipe_by_filter(pipes, check_by_repaired, status))
            cout << i.second;
    }
    else {
        cout << "Enter name: " << endl;
        cin.ignore(1000, '\n');
        getline(cin, name);
        for (auto i : find_pipe_by_filter(pipes, check_by_name, name))
            cout << i.second;
    }

}

void find_station(const unordered_map<int, CStation>& stations) {

    if (stations.size() == 0) {
        cout << "Stations doesn't exist\n";
        return;
    }

    string name;
    int command;
    cout << "Find station by name - 0, find station by percentage of not working workshops - 1 :" << endl;
    command = get_correct_number(0, 1);

    if (command) {
        cout << "Enter percentage of not working workshops" << endl;
        double target = get_correct_number(0.0, 100.0);
        for (auto i : find_station_by_filter(stations, check_by_working_workshops, target))
            cout << i.second;
    }
    else {
        cout << "Enter name: " << endl;
        cin.ignore(1000, '\n');
        getline(cin, name);
        for (auto i : find_station_by_filter(stations, check_by_name, name))
            cout << i.second;
    }

}

void menu() {

    cout << "1.  Add pipe\n";
    cout << "2.  Add compressor station\n";
    cout << "3.  View all objects\n";
    cout << "4.  Edit pipe\n";
    cout << "5.  Edit compressor station\n";
    cout << "6.  Save\n";
    cout << "7.  Load\n";
    cout << "8.  Find pipe by filter\n";
    cout << "9.  Find station by filter\n";
    cout << "10. Delete object by id\n";
    cout << "0.  Exit\n";

}

int main() {

    unordered_map<int, CPipe> pipes;
    unordered_map<int, CStation> stations;

    for (;;) {
        menu();
        cout << "================================\n";
        int command = get_correct_number(0, 10);
        switch (command) {
        case 1:
            add_object(pipes);
            break;
        case 2:
            add_object(stations);
            break;
        case 3:
            show_objects(pipes, stations);
            break;
        case 4:
            edit_pipes(pipes);
            break;
        case 5:
            edit_stations(stations);
            break;
        case 6:
            save_to_file(pipes, stations);
            break;
        case 7:
            load_from_file(pipes, stations);
            break;
        case 8:
            find_pipe(pipes);
            break;
        case 9:
            find_station(stations);
            break;
        case 10:
            delete_object(pipes, stations);
            break;
        case 0: return 0;
        }
    }

    return 0;

}
