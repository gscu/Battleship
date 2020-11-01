#include <iostream>
#include <ctime>

using namespace std;

/*
PRE-CONDITION: Input of coordinates must be of the example form: 0 0
Any addition of commas, brackets, or extra spaces could break the code for the Carrier system.
*/

const int rows = 10;
const int columns = 10;
int max_ships = 11;
int matrix[rows][columns];

void Clear() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++){
            matrix[i][j] = 0;
        }
    }
}

void Show() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int NumShips() {
    int c = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] == 1)
                c++;
        }
    }
    return c;
}

void MaxShips() {
    int s = 0;
    while (s < max_ships) {
        int x = rand() % rows;
        int y = rand() % columns;

        if (matrix[x][y] != 1) {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y) {
    if (matrix[x][y] == 1) {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int main() {
    cout << "Welcome to Battle Ship 4.2!!! " << endl;
    cout << "__   " << endl;
    cout << "Instructions: " << endl;
    cout << "Your goal is to transmit coordinates to Base Carrier to launch missle attacks on Japanese battle ships." << endl;
    cout << "The computer can transmit only numbers and sufficient spaces for location input, any commas or brackets of the sort will break the system..." << endl;
    cout << "Also, you may respond to messages from Base Carrier only by single letters due to computing problems." << endl;
    cout << "No pressure, good luck!" << endl;
    char respond;
    srand(time(NULL));
    Clear();
    MaxShips();
    int pos1,pos2;

    while (1) {
        cout << "Please enter location: ";
        cin >> pos1 >> pos2;

        if (Attack(pos1,pos2))
            cout << "Ship down! " << endl;
        else
            cout << "No ship in position... " << endl;
        cout << "Number of ships left: " << NumShips() << endl;
        cout << "Do you want to surrender? (y/n) "; cin >> respond;
        if (respond == 'y')
            break;
    }

    cout << "Game over!" << endl;
    Show();
    system("pause");
    return 0;
}
