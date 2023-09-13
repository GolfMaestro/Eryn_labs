#include <iostream>

using namespace std;

void menu(int choose);  // declare the functions
void print_menu();

struct Pipe {

    string name;
    double length;
    double diameter;
    bool under_repair;

};

struct Compressor_station {

    string name;
    int amount_workshops;
    int amount_working_workshops;
    double efficiency;

};

Pipe add_pipe() {  // "add pipe" function for struct Pipe

    Pipe p;

    cout << "Type name:\n";
    cin >> p.name;

    cout << "Type length:\n";
    cin >> p.length;

    cout << "Type diametr:\n";
    cin >> p.diameter;

    p.under_repair = false;

    return p;
    
}

int main() {

    int action;
    print_menu();

    for (;;) {  // eternal loop

        cout << "----------------------------------\n";
        cin >> action;
        menu(action);
        cin.clear();
        cin.ignore();

    }
}

void menu(int choose) {

    switch (choose) {
    case 1:
        cout << "Add pipe\n";
        cout << "0. Return to menu\n";
        add_pipe();
        break;

    case 2:
        cout << "Add compressor station\n"  ;
        cout << "0. Return to menu\n";
        break;

    case 3:
        cout << "View all objects\n";
        cout << "0. Return to menu\n";
        break;

    case 4:
        cout << "Edit pipe\n";
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