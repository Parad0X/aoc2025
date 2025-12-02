#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void apply(string line, int& sol, int& res) {
    int steps = stoi(line.substr(1));

    steps = steps % 100;

    if (line[0] == 'R') {
        sol += steps;
        sol = sol % 100;
    } else if (line[0] == 'L') {
        sol -= steps;

        if (sol < 0) {
            sol += 100;
        }
    }

    if (sol == 0) {
        res++;
    }

    // cout << line << " -> " << sol << " (" << res << ")" << endl;
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
