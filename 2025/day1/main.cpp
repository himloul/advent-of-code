#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> readLines(string filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

int dial(int point, string rotation) {
    string direction = rotation.substr(0, 1);
    int norm = stoi(rotation.substr(1));
    int sign = (direction == "R") ? 1 : -1;
    
    int temp = point + (sign * norm);
    int result = ((temp % 100) + 100) % 100;
    return result;
}

int part1(vector<string> data) {
    int count = 0, pos = 50;

    for (size_t i = 0; i < data.size(); i++)
    {
        pos = dial(pos, data[i]);
        if (pos == 0) count++;
    }
    return count;
}

int main() {
    vector<string> data = readLines("input.txt");
    cout << "Part 1: " << part1(data) << endl;
}