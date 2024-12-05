#include <string>
#include <fstream>
#include <iostream>

std::string getNumber(std::string s, int index, char delimiter) {
    char* numberStr = new char[3];
    
    int size = 0;
    for (size_t i = index; s[i] && s[i] != delimiter && isdigit(s[i]) && i < index + 3; i++){
        numberStr[size] = s[i];
        size++;
    }
    if(s[index + size] && s[index + size] == delimiter) {
        std::string str(numberStr);
        delete numberStr;
        return str;
    }
    delete numberStr;
    return "";
}

int main(void) {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        return 1;
    }

    std::string s;
    int solution = 0;
    int startingPostion;
    while (getline(f, s)) {
        startingPostion = 0;
        while(1) {
            int index = s.find("mul(", startingPostion);
            if (index != std::string::npos) {
                int i = index + 4;
                std::string firstNumberStr = getNumber(s, i, ',');
                i += firstNumberStr.length() + 1;

                if (firstNumberStr != "") {
                    std::string secondNumberStr = getNumber(s, i, ')');
                    if (secondNumberStr != "") {
                        solution += stoi(firstNumberStr) * stoi(secondNumberStr);
                        std::cout << firstNumberStr << " * " << secondNumberStr << " = " << stoi(firstNumberStr) * stoi(secondNumberStr) << "; Solution: " << solution << std::endl;
                    }
                }
            } else {
                break;
            }
            startingPostion = index + 1;
        }
    }
    std::cout << "Solution: " << solution << std::endl;
}