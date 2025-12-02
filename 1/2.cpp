#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void apply(string line, int& sol, int& res) {
    int steps = stoi(line.substr(1));
    int solb = sol;

    if (line[0] == 'R') {
        sol += steps;
        res += sol / 100;
        sol = sol % 100;
    } else if (line[0] == 'L') {
        sol -= steps;

        if (sol == 0) {
            res++;
        } else if (sol < 0) {
            if (solb > 0) {
                res++;
            }
            res += sol / -100;

            sol %= -100;

            if (sol != 0) {
                sol += 100;
            }
        }
    } else {
        throw invalid_argument("Invalid direction");
    }

    // cout << line << " = " << solb << " -> " << sol << " (" << res << ")" << endl;
}

int main() {
    string line;
    int sol = 50;
    int res = 0;

    while (getline(cin, line)) {
        apply(line, sol, res);
    }

    cout << res << endl;

    return 0;
}
