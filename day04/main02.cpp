#include <string>
#include <fstream>
#include <iostream>

bool findXmas(std::string* map, int x, int y) {
    if (x > 0 && x < 139 && y > 0 && y < 139){
        if (map[y - 1][x - 1] == 'M' || map[y - 1][x - 1] == 'S'){
            char firstChar = map[y - 1][x - 1];
            char secondChar;
            if (firstChar == 'M')
                secondChar = 'S';
            else 
                secondChar = 'M';
            
            if (map[y + 1][x - 1] == firstChar) {
                if (map[y + 1][x + 1] == secondChar && map[y - 1][x + 1] == secondChar)
                    return true;
            } else if (map[y - 1][x + 1] == firstChar){
                if (map[y + 1][x + 1] == secondChar && map[y + 1][x - 1] == secondChar)
                    return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

int main(void) {
    std::ifstream f("input.txt");

    if (!f.is_open()) {
        return 1;
    }

    std::string map[140];
    std::string s;
    int i = 0;
    while (getline(f, s)) {
        map[i] = s;
        i++;
    }

    int solution = 0;
    for (size_t y = 0; y < 140; y++) {
        for (size_t x = 0; x < 140; x++){
            if(map[y][x] == 'A' && findXmas(map, x, y) == true)
                solution ++;
        }
    }
    std::cout << "Solution: " << solution << std::endl;
    
}