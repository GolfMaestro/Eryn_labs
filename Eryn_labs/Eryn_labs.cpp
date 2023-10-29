#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

void print_menu(); // declare the function

template <typename T>
void logging(T input) {

    ofstream fout;
    fout.open("log.txt", ios::app);
    if (fout.is_open())
    {
        fout << input << endl;
    }
    fout.close();

}

void inputint(int& x) {

    cin >> x;
    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
    logging(x);
}

void inputdouble(double& x) {

    cin >> x;

    while (cin.fail() || x < 0 || cin.peek() != '\n') {

        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error. Try again!" << endl;
        cin >> x;

    }
    logging(x);
}

void inputbool(bool& a)
{
    cin >> a;
    while (!cin || !(a == 0 || a == 1) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please, try again: ";
        cin >> a;
    }
    logging(a);
};

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

    void save_pipe() {

        if (name.empty())
        {
            cout << "You don't have the pipe to save\n";
        }
        else
        {
            ofstream fout;
            fout.open("date.txt", ios::app);
            if (fout.is_open())
            {
                fout << "Pipe:" << endl;
                fout << name << endl << length << endl << diameter << endl << under_repair << endl;
            }
            fout.close();
            cout << "Pipe successfully saved!" << " " << "Please, check your file." << endl;
        }
    }

    void load_pipe() 
    {
        bool replace_data;
        replace_data = 1;
        if (!name.empty())
        {
            cout << "You already have data about your pipe!" << endl;
            cout << "If you are sure you want to replace them with data from the file, then press 1, otherwise 0: ";
            inputbool(replace_data);
        }
        if (replace_data == 1)
        {
            ifstream fin;
            string line;
            fin.open("date.txt", ios::in);
            if (fin.is_open())
            {
                while (getline(fin, line))
                {
                    if (line == "Pipe:")
                    {
                        getline(fin, name);
                        fin >> length >> diameter >> under_repair;
                    }
                }
                fin.close();
                if (name.empty())
                {
                    cout << "You don't have data about the pipe to download\n";
                }
                else
                {
                    cout << "Your pipe data has been successfully download!" << " " << " Press 3 to check your objects. " << endl;
                }
            }
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

    void save_station() {
    
        if (name.empty())
        {
            cout << "You don't have the compressor station to save.\n";
        }
        else
        {
            ofstream fout;
            fout.open("date.txt", ios::app);
            if (fout.is_open())
            {
                fout << "Compressor station:" << endl;
                fout << name << endl << amount_workshops << endl << amount_working_workshops << endl << efficiency << endl;
            }
            fout.close();
            cout << "Compressor station successfully saved!" << " " << "Please, check your file." << endl;
        }
    
    }

    void load_station ()
    {
        bool replace_data;
        replace_data = 1;
        if (!name.empty())
        {
            cout << "You already have data about your compressor station!" << endl;
            cout << "If you are sure you want to replace them with data from the file, then press 1, otherwise 0: ";
            inputbool(replace_data);
        }
        if (replace_data == 1)
        {
            ifstream fin;
            string line;
            fin.open("date.txt", ios::in);
            if (fin.is_open())
            {
                string line;
                while (getline(fin, line))
                {
                    if (line == "Compressor station:")
                    {
                        getline(fin, name);
                        fin >> amount_workshops >> amount_working_workshops >> efficiency;
                    }
                }
                fin.close();
                if (name.empty())
                {
                    cout << "You don't have data about the compressor station to download.\n";
                }
                else
                {
                    cout << "Your compressor station data has been successfully download!" << " " << " Press 3 to check your objects. " << endl;
                }
            }
        }
    }

};

int main() {
    
    remove("log.txt");  //recreate log file

    //logging("-----------------");  //expand current log file

    int count_pipe = 0;
    int count_cs = 0;
    int choose;
    print_menu();
    Pipe new_pipe;
    Compressor_station new_station;
    fstream date_file("date.txt");
    string linein;

    for (;;) {  // eternal loop

        cout << "================================\n";
        inputint(choose);
        logging(choose);

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
            new_pipe.save_pipe();
            new_station.save_station();
            cout << "0. Return to menu\n";
            break;

        case 7:
            cout << "Load\n";
            if (date_file.peek() == EOF)
            {
                cout << "File is empty!" << " " << "Please, check your data about your objects!!!" << endl;
                date_file.close();
            }
            else
            {
                new_pipe.load_pipe();
                new_station.load_station();
            }
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