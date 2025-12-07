#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void populate_grid(vector<vector<int>>& grid, string line) {
    vector<int> row;
    string num = "";

    for (auto c: line) {
        if (c == ' ') {
            row.push_back(stoi(num));
            num = "";
        } else {
            num += c;
        }
    }

    row.push_back(stoi(num));

    grid.push_back(row);
}

long long sum_column(vector<vector<int>>& grid, int column) {
    long long sum = 0;
    for (int i = 0; i < grid.size(); i++) {
        sum += grid[i][column];
    }
    return sum;
}

long long mul_column(vector<vector<int>>& grid, int column) {
    long long mul = 1;
    for (int i = 0; i < grid.size(); i++) {
        mul *= grid[i][column];
    }
    return mul;
}

void solve_grid(vector<vector<int>>& grid, string line, long long& res) {
    int pos = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '+') {
            long col_sum = sum_column(grid, pos);
            res += col_sum;
            pos++;
        } else if (line[i] == '*') {
            long col_mul = mul_column(grid, pos);
            res += col_mul;
            pos++;
        }
    }
}

int main() {
    vector<vector<int>> grid;
    string line;
    long long res = 0;

    while (getline(cin, line)) {
        if (line[0] == '+' || line[0] == '*') {
            solve_grid(grid, line, res);
        } else {
            populate_grid(grid, line);
        }
    }

    cout << res << endl;

    return 0;
}
