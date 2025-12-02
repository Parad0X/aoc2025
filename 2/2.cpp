#include <iostream>
#include <string>

using namespace std;

vector<pair<long, long>> get_ranges(string input) {
    vector<pair<long, long>> ranges;

    string num = "";
    long n1;
    long n2;

    for (auto c: input) {
        if (c == '-') {
            n1 = stol(num);
            num = "";
        } else if (c == ',') {
            n2 = stol(num);
            ranges.push_back({n1, n2});
            num = "";
        } else {
            num += c;
        }
    }

    n2 = stol(num);
    ranges.push_back({n1, n2});

    return ranges;
}

vector<string> get_chunks(string nums, int chunk_size) {
    vector<string> chunks;
    for (int i = 0; i < nums.length(); i += chunk_size) {
        chunks.push_back(nums.substr(i, chunk_size));
    }
    return chunks;
}

bool is_valid(long number) {
    string nums = to_string(number);

    for (int i = 1; i <= nums.length() / 2; i++) {
        auto chunks = get_chunks(nums, i);

        bool all_chunks_same = true;
        for (int j = 0; j < chunks.size() - 1; j++) {
            if (chunks[j] != chunks[j + 1]) {
                all_chunks_same = false;
                break;
            }
        }
        if (all_chunks_same) {
            // cout << number << endl;
            return false;
        }
    }

    return true;
}

vector<long> get_invalid_numbers(vector<pair<long, long>> ranges) {
    vector<long> invalid_numbers;

    for (auto range: ranges) {
        for (long i = range.first; i <= range.second; i++) {
            if (!is_valid(i)) {
                invalid_numbers.push_back(i);
            }
        }
    }

    return invalid_numbers;
}

int main() {
    string input;
    long long sum = 0;

    cin >> input;

    vector<pair<long, long>> ranges = get_ranges(input);
    for (auto number: get_invalid_numbers(ranges)) {
        sum += number;
    }
    cout << sum << endl;

    return 0;
}
