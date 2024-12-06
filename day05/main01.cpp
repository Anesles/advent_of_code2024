#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <array>

int countLines(std::ifstream f) {
    std::string s;
    int count = 0;
    
    while (getline(f, s)) {
        if(s[0] == '\n')
            break;
        count++;
    }
    return count;
}

void printVector(std::vector<int> v) {
    for (size_t i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}


int main(void) {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        return 1;
    }

    std::vector<std::array<int, 2>> groups;
    std::string s;
    while (1)
    {
        getline(f, s);
        if (!isdigit(s[0]))
            break;
        
        int firstNumber = stoi(s.substr(0, 2));
        int secondNumber = stoi(s.substr(3));
        std::array<int, 2> group = {firstNumber, secondNumber};

        groups.push_back(group);
    }

    while (getline(f, s)){
        std::vector<int> order;
        int startingpos = 0;
        int number;
        while(startingpos != std::string::npos) {
            if (startingpos != 0)
                startingpos++;
            number = stoi(s.substr(startingpos, 2));
            order.push_back(number);
            startingpos = s.find(",", startingpos);
        }
        printVector(order);
    }
    
}