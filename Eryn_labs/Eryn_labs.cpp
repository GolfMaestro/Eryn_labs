#include <iostream>
#include <vector>

using namespace std;

void menu(int choose);  // declare the functions
void print_menu();

struct Pipe {

    string name;
    double length = 0;
    double diameter = 0;
    bool under_repair = false;

};

struct Compressor_station {

    string name;
    int amount_workshops = 0;
    int amount_working_workshops = 0;
    double efficiency = 0;

};

vector <Pipe> pipes;
vector <Compressor_station> stations;

Pipe add_pipe() {  // "add pipe" function for struct Pipe

    Pipe p;

    cout << "Type name:\n";
    cin >> p.name;

    while (p.length == 0) {
        cout << "Type length:\n";
        cin >> p.length;
        cin.clear();
        cin.ignore();
    }

    while (p.diameter == 0) {
        cout << "Type diametr:\n";
        cin >> p.diameter;
        cin.clear();
        cin.ignore();
    }

    p.under_repair = false;

    pipes.push_back(p);
    return p;
    
}

void print_pipe(Pipe p) {

    cout << "Name: " << p.name << endl;
    cout << "Length: " << p.length << endl;
    cout << "Diameter: " << p.diameter << endl;
    cout << "Under repair: " << p.under_repair << endl;

}

Compressor_station add_station() {  // "add station" function for struct Compressor_station

    Compressor_station s;

    cout << "Type name:\n";
    cin >> s.name;

    while (s.amount_workshops == 0) {
        cout << "Type amount workshops:\n";
        cin >> s.amount_workshops;
        cin.clear();
        cin.ignore();
    }

    while (s.amount_working_workshops == 0) {
        cout << "Type amount working workshops:\n";
        cin >> s.amount_working_workshops;
        cin.clear();
        cin.ignore();
    }

    while (s.efficiency == 0) {
        cout << "Type efficiency:\n";
        cin >> s.efficiency;
        cin.clear();
        cin.ignore();
    }

    stations.push_back(s);
    return s;

}

void print_station(Compressor_station s) {

    cout << "Name: " << s.name << endl;
    cout << "Amount workshops: " << s.amount_workshops << endl;
    cout << "Amount working workshops: " << s.amount_working_workshops << endl;
    cout << "Efficiency: " << s.efficiency << endl;

}

int main() {

    int action;
    print_menu();

    for (;;) {  // eternal loop

        cout << "================================\n";
        cin >> action;
        cin.clear();
        cin.ignore();
        menu(action);

    }
}

void menu(int choose) {

    switch (choose) {
    case 1:
        cout << "Add pipe\n";
        add_pipe();
        cout << "0. Return to menu\n";
        break;

    case 2:
        cout << "Add compressor station\n";
        add_station();
        cout << "0. Return to menu\n";
        break;

    case 3:
        cout << "View all objects\n" << "Pipes:\n";
        //print_pipe(pipes[0]);
        for (int i = 0; i < pipes.size(); ++i) {
            print_pipe(pipes[i]);
            cout << "------------------------------\n";
        }

        cout << "Compressor stations:\n";
        for (int i = 0; i < stations.size(); ++i) {
            print_station(stations[i]);
            cout << "------------------------------\n";
        }
        cout << "0. Return to menu\n";
        break;

    case 4:
        cout << "Edit pipe\n";
        cout << "Choose pipe:\n";
        for (int i = 0; i < pipes.size(); ++i) {
            cout << i + 1 << ". ";
            //print_pipe(pipes[i].name);
            cout << pipes[i].name << endl;
        }

        int pipe_change;
        char repair;

        cin >> pipe_change;
        pipe_change -= 1;
        cout << pipes[pipe_change].name << endl << "Under repair(y/n)";

        cin >> repair;

        while ((repair != 'y') && (repair != 'n')) {
            cout << "Error! Try again\n" << "Under repair(y/n)\n";
            cin >> repair;
        }

        if (repair == 'y') {
            pipes[pipe_change].under_repair = true;
        }

        else if (repair == 'n') {
            pipes[pipe_change].under_repair = false;
        }

        cout << "0. Return to menu\n";
        break;

    case 5:
        cout << "Edit compressor station\n";
        cout << "0. Return to menu\n";
        break;

    case 6:
        cout << "Save\n";
        cout << "0. Return to menu\n";
        break;

    case 7:
        cout << "Load\n";
        cout << "0. Return to menu\n";
        break;

    case 0:
        print_menu();
        break;

    default:
        cout << "Error. Command doesn't exist.\n";
    }
}

void print_menu() {

    cout << "1. Add pipe\n";
    cout << "2. Add compressor station\n";
    cout << "3. View all objects\n";
    cout << "4. Edit pipe\n";
    cout << "5. Edit compressor station\n";
    cout << "6. Save\n";
    cout << "7. Load\n";
    cout << "0. Return to menu\n";

}