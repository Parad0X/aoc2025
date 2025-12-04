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

int main() {
    int res = 0;
    string line;

    while (getline(cin, line)) {
        res += get_bank_joltage(line);
    }

    cout << res << endl;

    return 0;
}
