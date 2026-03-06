#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>

std::vector<std::string> read_input_file() {
    std::ifstream in("/Users/ngoquyduong/CLionProjects/assessment_real/input.txt");

    if (!in.is_open()) {
        throw std::runtime_error("Could not open input.txt");
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


int main() {


    std::vector<std::string> moves = read_input_file();
    int start_position = 50;
    int password = 0;

    std::cout << moves[0] << " " << moves[1] << " " << moves[2] << std::endl;


    for (int i = 0; i < moves.size(); i++) {
        int number = convert_number(moves[i]);
        start_position = start_position + number;
        start_position = parse_valid_range(start_position);
        if (start_position == 0) {
            password++;
        }
    }

    std::cout << password << std::endl;
    return 0;
}
