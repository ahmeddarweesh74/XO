#include <iostream>
#include <string>

using namespace std;

class user {
public:
    string name;
    int score;
    user() {
        name = "";
        score = 0;
    }
    user(string n, int s) {
        name = n;
        score = s;
    }
};

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void printmatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int checkwin() {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
            if (matrix[i][0] == 'x')
                cout << "Player 1 wins!" << endl;
            else if (matrix[i][0] == 'o')
                cout << "Player 2 wins!" << endl;
            return 1;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            if (matrix[0][i] == 'x')
                cout << "Player 1 wins!" << endl;
            else if (matrix[0][i] == 'o')
                cout << "Player 2 wins!" << endl;
            return 1;
        }
    }

    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        if (matrix[0][0] == 'x')
            cout << "Player 1 wins!" << endl;
        else if (matrix[0][0] == 'o')
            cout << "Player 2 wins!" << endl;
        return 1;
    }

    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
        if (matrix[0][2] == 'x')
            cout << "Player 1 wins!" << endl;
        else if (matrix[0][2] == 'o')
            cout << "Player 2 wins!" << endl;
        return 1;
    }

    return 0;
}

void playerr1(user& player1) {
    int pos;
    cout << "Player 1, enter number from 1 to 9: ";
    cin >> pos;
    if (pos < 1 || pos > 9) {
        cout << "Invalid number" << endl;
        return;
    }
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (matrix[row][col] != 'x' && matrix[row][col] != 'o') {
        matrix[row][col] = 'x';
    } else {
        cout << "That position is already taken!" << endl;
    }
}

void playerr2(user& player2) {
    int pos;
    cout << "Player 2, enter number from 1 to 9: ";
    cin >> pos;
    if (pos < 1 || pos > 9) {
        cout << "Invalid number" << endl;
        return;
    }
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (matrix[row][col] != 'x' && matrix[row][col] != 'o') {
        matrix[row][col] = 'o';
    } else {
        cout << "That position is already taken!" << endl;
    }
}

int main() {
    user player1;
    user player2;
    string name1, name2;
    cout << "Enter name of player1: ";
    cin >> name1;
    cout << "Enter name of player2: ";
    cin >> name2;
    player1.name = name1;
    player2.name = name2;
    printmatrix();

    bool playagain=true;
    while(playagain){


    int turns = 0;
    while (true) {
        playerr1(player1);
        printmatrix();
        if (checkwin()) {
            player1.score++;
            cout<<player1.name<<" wins The score is  "<<player1.name<<" : "<<player1.score<<" (vs) "<<player2.name<<" : "<<player2.score<<endl;
            break;
        }
        turns++;
        if (turns == 9) {
            cout << "It's a tie!" << endl;
            break;
        }
        playerr2(player2);
        printmatrix();
        if (checkwin()) {
            player2.score++;
            cout<<player2.name<<" wins The score is  "<<player1.name<<" : "<<player1.score<<" (vs) "<<player2.name<<" : "<<player2.score<<endl;
            break;
        }
        turns++;
    }
    int choice;
    cout<<"do you want to play again"<<endl;
    cout<<"1- yes"<<endl;
    cout<<"2- no"<<endl<<"choice : ";
    cin>>choice;
    if (choice==2)
    {
        playagain=false;
    }
    else
    {
        printmatrix();
    }
    }
    return 0;
}
