#include <iostream>

using namespace std;

void menu(int choose);  // declare the functions
void print_menu();

int main()
{
    int action;
    print_menu();

    for (;;) {  // eternal loop
        cin >> action;
        menu(action);

    }
}


void menu(int choose) {

    if (choose == 1) {
        cout << "Add pipe\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 2) {
        cout << "Add compressor station\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 3) {
        cout << "View all objects\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 4) {
        cout << "Edit pipe\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 5) {
        cout << "Edit compressor station\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 6) {
        cout << "Save\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 7) {
        cout << "Load\n";
        cout << "0. Return to menu\n";
    }

    if (choose == 0) {
        print_menu();
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
