#include <fstream>
#include <iostream>
#include <string>

using namespace std;

long get_bank_joltage(string bank, int pos = 0, string joltage = "") {
    if (joltage.length() == 12) {
        return stol(joltage);
    }

    for (int i = 9; i >= 1; i--) {
        auto next_pos = bank.find(to_string(i), pos);

        if (next_pos == string::npos) {
            continue;
        }

        long result = get_bank_joltage(bank, next_pos + 1, joltage + to_string(i));

        if (result != 0) {
            return result;
        }
    }

    return 0;
}

int main() {
    long long res = 0;
    string line;

    while (getline(cin, line)) {
        res += get_bank_joltage(line);
    }

    cout << res << endl;

    return 0;
}
