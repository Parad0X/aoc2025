#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int get_bank_joltage(string bank) {
    int joltage = 0;

    for (int i = 0; i < bank.length() - 1; i++) {
        for (int j = i + 1; j < bank.length(); j++) {
            string joltage_str = "";
            joltage_str += bank[i];
            joltage_str += bank[j];

            joltage = max(joltage, stoi(joltage_str));
        }
    }

    return joltage;
}

vector<int> get_joltages(vector<string> banks) {
    vector<int> joltages;

    for (auto bank: banks) {
        joltages.push_back(get_bank_joltage(bank));
    }

    return joltages;
}

int main() {
    vector<string> banks;

    string line;
    while (getline(cin, line)) {
        banks.push_back(line);
    }

    long res = 0;

    for (auto joltage: get_joltages(banks)) {
        cout << joltage << "\n";
        res += joltage;
    }

    cout << res << endl;

    return 0;
}
