#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void findAndReplace(const string& filename, const string& target, const string& replacement) {
    string fullPath = "D:\\" + filename;
    ifstream inputFile(fullPath);
    if (!inputFile) {
        cerr << "Error: Cannot open file: " << fullPath << endl;
        return;
    }

    string content, line;
    while (getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(target, pos)) != string::npos) {
            line.replace(pos, target.length(), replacement);
            pos += replacement.length();
        }
        content += line + "\n";
    }
    inputFile.close();

    string outputPath = "D:\\salah.txt";
    ofstream outputFile(outputPath);
    if (!outputFile) {
        cerr << "Error: Cannot create  file: " << outputPath << endl;
        return;
    }

    outputFile << content;
    outputFile.close();
    cout << "Replacement done! Check '" << outputPath << "'." << endl;
}

int main() {
    string filename, target, replacement;

    cout << "Enter file name (only name, it should be in D:\\): ";
    cin >> filename;
    cout << "Enter word to replace: ";
    cin >> target;
    cout << "Enter replacement word: ";
    cin >> replacement;

    findAndReplace(filename, target, replacement);

    return 0;
}