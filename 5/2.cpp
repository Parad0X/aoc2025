#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void populate_inventory(vector<pair<long, long>>& inventory) {
    string line;
    bool a = true;
    while (getline(cin, line)) {
        if (line == "") {
            a = false;
        } else if (a) {
            int pos = line.find('-');
            long start = stol(line.substr(0, pos));
            long end = stol(line.substr(pos + 1));

            inventory.push_back({start, end});
        }
    }
}

void sort_inventory(vector<pair<long, long>>& inventory) {
    sort(inventory.begin(), inventory.end(), [](auto a, auto b) { return a.first < b.first; });
}

void merge_inventory(vector<pair<long, long>>& inventory) {
    int s = 0;

    for (int i = 0; i < inventory.size() - 1; i++) {
        // No overlap
        if (inventory[i+1].first > inventory[s].second) {
            s = i + 1;
            continue;
        }

        // Overlap
        inventory[s].second = max(inventory[s].second, inventory[i+1].second);
        inventory[i+1].first = -1;
    }
}

int main() {
    vector<pair<long, long>> inventory;

    populate_inventory(inventory);
    sort_inventory(inventory);
    merge_inventory(inventory);

    long long res = 0;
    for (auto range: inventory) {
        if (range.first != -1) {
            res += range.second - range.first + 1;
        }
    }

    cout << res << endl;

    return 0;
}
