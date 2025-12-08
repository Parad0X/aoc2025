#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void simulate_beam(vector<string>& manifold, int i, int j, int& res) {
    if (manifold[i][j] == 'S') {
        simulate_beam(manifold, i+1, j, res);
    } else if (manifold[i][j] == '^') {
        simulate_beam(manifold, i, j-1, res);
        simulate_beam(manifold, i, j+1, res);
    } else if (i == manifold.size() - 1) {
        manifold[i][j] = '|';
        res++;
    } else if (manifold[i][j] == '.' || manifold[i][j] == '|') {
        manifold[i][j] = '|';
        simulate_beam(manifold, i+1, j, res);
    }
}

int main() {
    vector<string> manifold;
    string line;
    int res = 0;

    while (getline(cin, line)) {
        manifold.push_back(line);
    }

    for (int i = 0; i < manifold[0].length(); i++) {
        if (manifold[0][i] == 'S') {
            simulate_beam(manifold, 0, i, res);
        }
    }

    for (auto row: manifold) {
        cout << row << endl;
    }

    cout << res << endl;

    return 0;
}
