#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void build_joltages(string bank, vector<long> *joltages, int pos = -1, string joltage = "") {
    if (pos == -1) {
        pos = bank.length() - 1;
    }

    joltage = bank[pos] + joltage;

    if (joltage.length() == 12) {
        joltages->push_back(stol(joltage));
        return;
    }

    for (int i = pos - 1; i >= max(0, pos - 12); i--) {
        build_joltages(bank, joltages, i, joltage);
    }
}

long get_bank_joltage(string bank) {
    vector<long> joltages;
    build_joltages(bank, &joltages);

    long joltage = 0;
    for (auto j: joltages) {
        joltage = max(joltage, j);
    }

    return joltage;
}

vector<long> get_joltages(vector<string> banks) {
    vector<long> joltages;

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

    long long res = 0;
    for (auto joltage: get_joltages(banks)) {
        cout << joltage << endl;
        res += joltage;
    }
    cout << res << endl;

    return 0;
}
