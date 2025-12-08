#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector<string> manifold;
    string line;
    int res = 0;

    while (getline(cin, line)) {
        manifold.push_back(line);
    }

    map<int, bool> prev_beams;
    map<int, bool> curr_beams;

    for (int i = 0; i < manifold.size(); i++) {
        prev_beams = curr_beams;
        curr_beams = map<int, bool>();

        for (int j = 0; j < manifold[i].size(); j++) {
            if (manifold[i][j] == 'S') {
                curr_beams[j] = true;
            } else if (manifold[i][j] == '^') {
                if (!prev_beams[j]) {
                    continue;
                }

                if (manifold[i][j-1] == '.') {
                    manifold[i][j-1] = '|';
                    curr_beams[j-1] = true;
                }
                if (manifold[i][j+1] == '.') {
                    manifold[i][j+1] = '|';
                    curr_beams[j+1] = true;
                    res++;
                }
            } else if (prev_beams[j]) {
                manifold[i][j] = '|';
                curr_beams[j] = true;
            }
        }
    }

    for (auto row: manifold) {
        cout << row << endl;
    }

    cout << res << endl;

    return 0;
}
