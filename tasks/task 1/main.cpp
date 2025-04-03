#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

const string FILENAME = "data.txt";
const int SHIFT = 3;


void saveToFile() {
    ofstream file(FILENAME);
    if (!file) {
        cerr << "cant open file!" << endl;
        return;
    }

    string input;
    cout << "enter text to save: ";
    cin.ignore();
    getline(cin, input);

    file << input;
    file.close();
    cout << "data saved correctly!" << endl;
}

void displayFile() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "cant open the file!" << endl;
        return;
    }

    string content;
    cout << "file content:\n";
    while (getline(file, content)) {
        cout << content << endl;
    }

    file.close();
}

void encryptFile() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "cant open to encrype!" << endl;
        return;
    }

    string content, encryptedContent;
    while (getline(file, content)) {
        for (char &c : content) {
            c += SHIFT;
        }
        encryptedContent += content + "\n";
    }
    file.close();

    ofstream outFile(FILENAME);
    outFile << encryptedContent;
    outFile.close();

    cout << "file encrypt correctly!" << endl;
}


void decryptFile() {
    ifstream file(FILENAME);
    if (!file) {
        cerr << "cant open file to decrypt" << endl;
        return;
    }

    string content, decryptedContent;
    while (getline(file, content)) {
        for (char &c : content) {
            c -= SHIFT;
        }
        decryptedContent += content + "\n";
    }
    file.close();

    ofstream outFile(FILENAME);
    outFile << decryptedContent;
    outFile.close();

    cout << "file decrypt correctly!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n choose operation:\n";
        cout << "1 - add and save\n";
        cout << "2 - read content in file\n";
        cout << "3 - encryptFile\n";
        cout << "4 - decryptFile\n";
        cout << "5 - exit\n";
        cout << "choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                saveToFile();
                break;
            case 2:
                displayFile();
                break;
            case 3:
                encryptFile();
                break;
            case 4:
                decryptFile();
                break;
            case 5:
                cout << "exit...\n";
                break;
            default:
                cout << "wrong .. choose another.\n";
        }
    } while (choice != 5);
  _getch();
}
