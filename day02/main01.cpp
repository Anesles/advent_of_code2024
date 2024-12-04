#include <string>
#include <fstream>
#include <iostream>

int main(void) {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        return 1;
    }

    std::string s;
    while (getline(f, s)) {
    }
}