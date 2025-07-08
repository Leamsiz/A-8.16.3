#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

string RemoveCommas(const string& str) {
    string result;
    for (char c : str) {
        if (c != ',') result += c;
    }
    return result;
}

int main() {
    string filename;
    cout << "Enter the baby name data filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    int rank;
    string boyName, boyCountStr, girlName, girlCountStr;

    cout << left << setw(6) << "Rank"
         << setw(15) << "Boy Name"
         << setw(12) << "Boy Count"
         << setw(15) << "Girl Name"
         << setw(12) << "Girl Count" << endl;

    cout << string(60, '-') << endl;

    while (file >> rank >> boyName >> boyCountStr >> girlName >> girlCountStr) {
        int boyCount = stoi(RemoveCommas(boyCountStr));
        int girlCount = stoi(RemoveCommas(girlCountStr));

        cout << left << setw(6) << rank
             << setw(15) << boyName
             << setw(12) << boyCount
             << setw(15) << girlName
             << setw(12) << girlCount
             << endl;
    }

    file.close();
    return 0;
}