#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool ff4(vector<string> grid, int i, int j) {
    int rolls = 0;

    int sk = max(i - 1, 0);
    int sl = max(j - 1, 0);
    int ek = min(i + 1, (int) grid.size() - 1);
    int el = min(j + 1, (int) grid[i].size() - 1);

    for (int k = sk; k <= ek; k++) {
        for (int l = sl; l <= el; l++) {
            if (k == i && l == j) {
                continue;
            }

            if (grid[k][l] == '@') {
                rolls++;
            }
        }
    }

    return rolls < 4;
}

int main() {
    vector<string> grid;
    string line;

    while (getline(cin, line)) {
        grid.push_back(line);
    }

    int res = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '@' && ff4(grid, i, j)) {
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
