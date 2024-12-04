#include <string>
#include <fstream>
#include <iostream>

int getMinIndex(int list[]) {
    int min = 0;
    int index = 0;

    for (size_t i = 0; i < 1000; i++){    
        if(i == 0) {
            min = list[i];
        } else if (list[i] != 2147483647 && list[i] < min){
            min = list[i];
            index = i;
        }
    }
    list[index] = 2147483647; 
    return min;
}

int main(void) {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        return 1;
    }

    std::string s;
    int firstList[1000];
    int lastList[1000];

    int i = 0;
    while (getline(f, s)) {
        int indexSpace = s.find(" ");

        std::string firstNumber = s.substr(0, indexSpace);
        firstList[i] = stoi(firstNumber);
        
        std::string lastNumber = s.substr(indexSpace, s.length());
        lastList[i] = stoi(lastNumber);

        i++;
    }
    
    int solution = 0;
    for (size_t i = 0; i < 1000; i++)
    {
        int minFirst = getMinIndex(firstList);
        int minSecond = getMinIndex(lastList);

        std::cout << "Primeiro: " << minFirst << "; Segundo: " << minSecond << std::endl;

        if (minFirst > minSecond)
            solution += minFirst - minSecond;
        else
            solution += minSecond - minFirst;
    }
    
    std::cout << "Solution: " << solution << std::endl;

    f.close();
}