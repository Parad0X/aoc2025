#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void populate_inventory(vector<pair<long, long>>& inventory, string input) {
    int pos = input.find('-');
    long start = stol(input.substr(0, pos));
    long end = stol(input.substr(pos + 1));

    inventory.push_back({start, end});
}

bool check_inventory(vector<pair<long, long>>& inventory, long input) {
    for (auto range: inventory) {
        if (input >= range.first && input <= range.second) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<pair<long, long>> inventory;
    string line;
    int res = 0;

    bool a = true;
    while (getline(cin, line)) {
        if (line == "") {
            a = false;
        } else if (a) {
            populate_inventory(inventory, line);
        } else {
            long linel = stol(line);

            if (check_inventory(inventory, linel)) {
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
