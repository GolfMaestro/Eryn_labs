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

    void add_pipe() {  // "add pipe" function for struct Pipe

        cout << "Type name:\n";
        cin >> name;

        while (length == 0) {
            cout << "Type length:\n";
            cin >> length;
            cin.clear();
            cin.ignore();
        }

        while (diameter == 0) {
            cout << "Type diametr:\n";
            cin >> diameter;
            cin.clear();
            cin.ignore();
        }

    }

    void print_pipe() {

        cout << "Name: " << name << endl;
        cout << "Length: " << length << endl;
        cout << "Diameter: " << diameter << endl;
        cout << "Under repair: " << under_repair << endl;

    }

};

struct Compressor_station {

    string name;
    int amount_workshops = 0;
    int amount_working_workshops = 0;
    double efficiency = 0;

    void add_station() {  // "add station" function for struct Compressor_station

        cout << "Type name:\n";
        cin >> name;

        while (amount_workshops == 0) {
            cout << "Type amount workshops:\n";
            cin >> amount_workshops;
            cin.clear();
            cin.ignore();
        }

        while (amount_working_workshops == 0) {
            cout << "Type amount working workshops:\n";
            cin >> amount_working_workshops;
            cin.clear();
            cin.ignore();
        }

        while (efficiency == 0) {
            cout << "Type efficiency:\n";
            cin >> efficiency;
            cin.clear();
            cin.ignore();
        }
    }

    void print_station() {

        cout << "Name: " << name << endl;
        cout << "Amount workshops: " << amount_workshops << endl;
        cout << "Amount working workshops: " << amount_working_workshops << endl;
        cout << "Efficiency: " << efficiency << endl;

    }
};


int main() {

    int choose;
    print_menu();
    Pipe new_pipe;
    Compressor_station new_station;

    for (;;) {  // eternal loop

        cout << "================================\n";
        cin >> choose;
        cin.clear();
        cin.ignore();

        switch (choose) {
        case 1:
            cout << "Add pipe\n";
            new_pipe.add_pipe();
            cout << "0. Return to menu\n";
            break;

        case 2:
            cout << "Add compressor station\n";
            new_station.add_station();
            cout << "0. Return to menu\n";
            break;

        case 3:
            cout << "View all objects\n" << "Pipe:\n";
            new_pipe.print_pipe();

            cout << "Compressor station:\n";
            new_station.print_station();

            cout << "0. Return to menu\n";
            break;

        case 4:
            /*cout << "Edit pipe\n";
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

            cout << "0. Return to menu\n";*/
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