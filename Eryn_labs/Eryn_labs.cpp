#include <iostream>
#include <fstream>

using namespace std;

void print_menu(); // declare the function

void inputint(int& x) {

    cin >> x;
    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
}

void inputdouble(double& x) {

    cin >> x;

    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
}


struct Pipe {

    string name;
    double length = 0;
    int diameter = 0;
    bool under_repair = false;

    void add_pipe() {  // "add pipe" function for struct Pipe

        cout << "Type name:\n";
        cin >> name;

        cout << "Type length:\n";
        inputdouble(length);

        cout << "Type diametr:\n";
        inputint(diameter);

    }

    void print_pipe() {

        if (diameter != 0) {
            cout << "Pipe:\n";
            cout << "Name: " << name << endl;
            cout << "Length: " << length << endl;
            cout << "Diameter: " << diameter << endl;
            cout << "Under repair: " << under_repair << endl;
        }

        else {
            cout << "Pipes doesn't exist\n";
        }
    }

    void edit_pipe() {

        char repair;

        cout << "Is pipe under repair(y/n)";

        cin >> repair;

        while ((repair != 'y') && (repair != 'n')) {
            cout << "Error! Try again\n" << "Under repair(y/n)\n";
            cin >> repair;
        }

        if (repair == 'y') {
            under_repair = true;
        }

        else if (repair == 'n') {
            under_repair = false;
        }

    }

};


struct Compressor_station {

    string name;
    int amount_workshops = 0;
    int amount_working_workshops = 0;
    double efficiency = 0;

    void add_station() { 

        cout << "Type name:\n";
        cin >> name;

        cout << "Type amount workshops:\n";
        inputint(amount_workshops);

        cout << "Type amount working workshops:\n";
        inputint(amount_working_workshops);

        while (amount_working_workshops > amount_workshops) {
            cout << "Error. There's no so many workshops. Try again\n";
            inputint(amount_working_workshops);
        }

        cout << "Type efficiency:\n";
        inputdouble(efficiency);

    }

    void print_station() {

        if (amount_workshops != 0) {
            cout << "Compressor station:\n";
            cout << "Name: " << name << endl;
            cout << "Amount workshops: " << amount_workshops << endl;
            cout << "Amount working workshops: " << amount_working_workshops << endl;
            cout << "Efficiency: " << efficiency << endl;
        }

        else {
            cout << "Compressor station doesn't exist\n";
        }
    }

    void working_workshops_change() {

        int aww; // short amount_working_workshops

        inputint(aww);

        while (aww > amount_workshops) {
            cout << "Error. There's no so many workshops. Try again\n";
            inputint(aww);
        }

        amount_working_workshops = aww;

    }

};

void save_file(ofstream& outfile, Pipe new_pipe, Compressor_station new_station, int count_pipe, int count_cs) {
    outfile.open("saves.txt");

    outfile << count_pipe << endl;
    outfile << new_pipe.name << endl << new_pipe.length << endl << new_pipe.diameter << endl << new_pipe.under_repair << endl;

    outfile << count_cs << endl;
    outfile << new_station.name << endl << new_station.amount_workshops << endl << new_station.amount_working_workshops << endl << new_station.efficiency << endl;
    outfile.close();
}

void load_file(ifstream& infile, Pipe& new_pipe, Compressor_station& new_station, int count_pipe, int count_cs) {
    infile.open("saves.txt");

    int cp;
    int ccs;

    infile >> cp;

    if (infile.is_open()) {

        for (int j = 0; j < cp; ++j) {
            infile >> new_pipe.name;
            infile >> new_pipe.length;
            infile >> new_pipe.diameter;
            infile >> new_pipe.under_repair;
        }

        infile >> ccs;

        for (int j = 0; j < ccs; ++j) {
            infile >> new_station.name;
            infile >> new_station.amount_workshops;
            infile >> new_station.amount_working_workshops;
            infile >> new_station.efficiency;
        }

        infile.close();
    }
}

int main() {

    int count_pipe = 0;
    int count_cs = 0;
    int choose;
    print_menu();
    Pipe new_pipe;
    Compressor_station new_station;
    ofstream outfile;
    ifstream infile;
    string linein;

    for (;;) {  // eternal loop

        cout << "================================\n";
        inputint(choose);

        switch (choose) {

        case 1:
            cout << "Add pipe\n";
            new_pipe.add_pipe();
            count_pipe += 1;
            cout << "0. Return to menu\n";
            break;

        case 2:
            cout << "Add compressor station\n";
            new_station.add_station();
            count_cs += 1;
            cout << "0. Return to menu\n";
            break;

        case 3:
            cout << "View all objects\n";
            new_pipe.print_pipe();

            cout << "--------------------------------\n";

            cout << "Compressor station:\n";
            new_station.print_station();

            cout << "0. Return to menu\n";
            break;

        case 4:
            cout << "Edit pipe\n";
            new_pipe.edit_pipe();
            cout << "0. Return to menu\n";
            break;

        case 5:
            cout << "Edit compressor station\n";
            cout << "Type amount of working workshops: ";
            new_station.working_workshops_change();
            cout << "0. Return to menu\n";
            break;

        case 6:
            cout << "Save\n";
            save_file(outfile, new_pipe, new_station, count_pipe, count_cs);
            cout << "0. Return to menu\n";
            break;

        case 7:
            cout << "Load\n";
            load_file(infile, new_pipe, new_station, count_pipe, count_cs);
            cout << "0. Return to menu\n";
            break;

        case 0:
            print_menu();
            break;

        default:
            cout << "Error. Command doesn't exist.\n";
            print_menu();
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