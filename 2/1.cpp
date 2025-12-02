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

bool is_valid(long number) {
    string nums = to_string(number);

    if (nums.length() % 2 != 0) {
        return true;
    }

    string num1 = nums.substr(0, nums.length() / 2);
    string num2 = nums.substr(nums.length() / 2);

    return num1 != num2;
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
