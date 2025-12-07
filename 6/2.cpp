#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int wstoi(string word) {
    string num = "";
    for (auto c: word) {
        if (c >= '0' && c <= '9') {
           num += c;
        }
    }

    if (num == "") {
        return 0;
    }

    return stoi(num);
}

void populate_grid(vector<vector<string>>& grid, string line, vector<int> num_sizes) {
    vector<string> row;
    int pos = 0;

    for (auto num_size: num_sizes) {
        row.push_back(line.substr(pos, num_size));
        pos += num_size + 1;
    }

    grid.push_back(row);
}

long sum_column(vector<vector<string>>& grid, int column) {
    long sum = 0;
    for (int i = 0; i < grid.size(); i++) {
        sum += wstoi(grid[i][column]);
    }
    return sum;
}

long mul_column(vector<vector<string>>& grid, int column) {
    long mul = 1;
    for (int i = 0; i < grid.size(); i++) {
        int val = wstoi(grid[i][column]);

        if (val != 0) {
            mul *= val;
        }
    }
    return mul;
}

void solve_grid(vector<vector<string>>& grid, string line, long& res) {
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

void rotate_grid(vector<vector<string>>& grid) {
    for (int i = 0; i < grid[0].size(); i++) {
        vector<string> new_col;

        // Collect the letters
        for (int j = 0; j < grid[0][0].size(); j++) {
            string col_val = "";

            for (int k = 0; k < grid.size(); k++) {
                col_val += grid[k][i][j];
            }

            if (col_val == "") {
                col_val = "0";
            }

            new_col.push_back(col_val);
        }

        // Replace the column
        for (int j = 0; j < grid.size(); j++) {
            grid[j][i] = new_col[j];
        }
    }
}

vector<int> get_num_sizes(vector<string> lines) {
    vector<int> num_sizes;

    for (auto line: lines) {
        string num = "";
        int pos = 0;

        for (int i = 0; i < line.length() + 1; i++) {
            if (line[i] == ' ' || i == line.length()) {
                if (num != "") {
                    if (num_sizes.size() <= pos) {
                        num_sizes.push_back(0);
                    }
                    num_sizes[pos] = max(num_sizes[pos], (int) num.length());
                    pos++;
                    num = "";
                }
            } else {
                num += line[i];
            }
        }
    }

    return num_sizes;
}

int main() {
    vector<vector<string>> grid;
    string line;
    long res = 0;

    // Read the lines
    vector<string> lines;
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    // Find num size
    vector<int> num_sizes = get_num_sizes(lines);

    for (auto line: lines) {
        if (line[0] == '+' || line[0] == '*') {
            rotate_grid(grid);
            solve_grid(grid, line, res);
        } else {
            populate_grid(grid, line, num_sizes);
        }
    }

    cout << res << endl;

    return 0;
}
