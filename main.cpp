#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
//////////////////////////////
///
///DAY 1
///
//////////////////////////////
std::vector<std::string> read_input_file() {
    std::ifstream in("/Users/ngoquyduong/CLionProjects/assessment_real/input1.txt");

    if (!in.is_open()) {
        throw std::runtime_error("Could not open input1.txt");
    }

    std::vector<std::string> moves;
    std::string line;

    while (std::getline(in, line)) {
        if (!line.empty()) {
            moves.push_back(line);
        }
    }

    return moves;
}

int parse_valid_range(int number) {
    return ((number % 100) + 100) % 100;
}
int convert_number(std::string char_and_num) {
    if (char_and_num.empty()) {
        throw std::invalid_argument("number is empty");
    }

    char direction = char_and_num[0];
    int number = std::stoi(char_and_num.substr(1));

    if (direction == 'L') {
        number = number * -1;
    }
    return number;
}

void dayOnePartOne() { // DAY 1 PART 1
    std::vector<std::string> moves = read_input_file();
    int start_position = 50;
    int password = 0;

    for (int i = 0; i < moves.size(); i++) {
        int number = convert_number(moves[i]);
        start_position = start_position + number;
        start_position = parse_valid_range(start_position);
        if (start_position == 0) {
            password++;
        }
    }

    std::cout << password << std::endl;
}


void dayOnePartTwo() { // DAY 1 PART 2
    std::vector<std::string> moves = read_input_file();
    int start_position = 50;
    int password = 0;

    for (int i = 0; i < static_cast<int>(moves.size()); i++) {
        char direction = moves[i][0];
        int steps = std::stoi(moves[i].substr(1));

        int step = (direction == 'L') ? -1 : 1;

        for (int j = 0; j < steps; j++) {
            start_position += step;
            start_position = parse_valid_range(start_position);

            if (start_position == 0) {
                password++;
            }
        }
    }

    std::cout << password << std::endl;
}



///////////
///
/// DAY 2
///
/// ///////

std::vector<std::pair<long, long>> getInput2() {
    std::ifstream in("/Users/ngoquyduong/CLionProjects/assessment_real/input2.txt");
    if (!in.is_open()) {
        std::cerr << "Cannot open file\n";
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    getline(in, line);   // reads: 1-3,11-19,21-25

    std::stringstream ss(line);
    std::string token;
    std::vector<std::pair<long, long>> ranges;

    while (getline(ss, token, ',')) {
        size_t dashPos = token.find('-');

        long long left = stoll(token.substr(0, dashPos));
        long long right = stoll(token.substr(dashPos + 1));

        ranges.push_back({left, right});
    }

    return ranges;
}

long long dayTwoPartOne() {
    std::vector<std::pair<long, long>> ranges = getInput2();
    long long invalid_id_sum;
    for (int i = 0; i < ranges.size(); i++) {
        long long left = ranges[i].first;
        long long right = ranges[i].second;

        for (long long j = left; j <= right; j++) {
            std::string id = std::to_string(j);
            int length = id.length();
            if (length% 2== 1) {
                continue;
            }
            int mid = length / 2;
            std::string left_id = id.substr(0, mid);
            std::string right_id = id.substr(mid);

            if (left_id == right_id) {
                invalid_id_sum = invalid_id_sum + j;
            }
        }
    }
    return invalid_id_sum;


}

int main() {


    std::cout << dayTwoPartOne();
    return 0;
}
