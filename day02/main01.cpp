#include <string>
#include <fstream>
#include <iostream>

void printList(int* list) {
    for (size_t i = 0; (i < 8 && list[i] != -1); i++){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

int* parseString(std::string line) {
    int startingPosition = 0;
    int* list = new int[8];

    for (size_t index = 0; index < 8; index++){
        list[index] = -1;
    }

    int i = 0;
    while (line.find(" ", startingPosition) != std::string::npos)
    {
        int endPosition = line.find(" ", startingPosition);

        int number = stoi(line.substr(startingPosition, endPosition - startingPosition ));
        list[i] = number;
        startingPosition = endPosition + 1;
        i++; 
    }
    list[i] = stoi(line.substr(startingPosition));
    
    return list;
}

bool checkValid(int* list) {
    int number = 0;
    int mode = 0; //mode 0 - asc; 1 - desc

    for (size_t i = 0; (i < 8 && list[i] != -1); i++){
        if (i == 1) {
            if (number < list[i] && (list[i] - number) > 0 && (list[i] - number) < 4)
                mode = 0;
            else if (number > list[i] && (number - list[i]) > 0 && (number - list[i]) < 4)
                mode = 1;
            else
                return false;
        } else if (i != 0){
            if ((mode == 0 && (number > list[i] || (list[i] - number) < 1 || (list[i] - number) > 3)) ||
                (mode == 1 && (number < list[i] || (number - list[i]) < 1 || (number - list[i]) > 3))){
                return false;
            }
        }
        number = list[i];
    }

    return true;
}

int main(void) {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        return 1;
    }

    std::string s;
    int count = 0;
    while (getline(f, s)) {
        int* list = parseString(s);
        
        if (checkValid(list) == true)
            count++;
        delete list;
    }

    std::cout << "Number of safe reports: " << count << std::endl;
}