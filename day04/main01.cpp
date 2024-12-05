#include <string>
#include <fstream>
#include <iostream>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UPLEFT 4
#define UPRIGHT 5
#define DOWNLEFT 6
#define DOWNRIGHT 7

bool trySide(std::string* map, int x, int y, int dir)
{
    for (int i = 1; i <= 3; ++i) {
        switch (dir) {
        case UP:
            if (y - i < 0 || (i == 1 && (!map[y - i][x] || map[y - i][x] != 'M')) ||
                (i == 2 && (!map[y - i][x] || map[y - i][x] != 'A')) ||
                (i == 3 && (!map[y - i][x] || map[y - i][x] != 'S')))
                return false;
            break;
        case DOWN:
            if (y + i >= map->size() || (i == 1 && (!map[y + i][x] || map[y + i][x] != 'M')) ||
                (i == 2 && (!map[y + i][x] || map[y + i][x] != 'A')) ||
                (i == 3 && (!map[y + i][x] || map[y + i][x] != 'S')))
                return false;
            break;
        case LEFT:
            if (x - i < 0 || (i == 1 && (!map[y][x - i] || map[y][x - i] != 'M')) ||
                (i == 2 && (!map[y][x - i] || map[y][x - i] != 'A')) ||
                (i == 3 && (!map[y][x - i] || map[y][x - i] != 'S')))
                return false;
            break;
        case RIGHT:
            if (x + i >= map[y].size() || (i == 1 && (!map[y][x + i] || map[y][x + i] != 'M')) ||
                (i == 2 && (!map[y][x + i] || map[y][x + i] != 'A')) ||
                (i == 3 && (!map[y][x + i] || map[y][x + i] != 'S')))
                return false;
            break;
        case UPLEFT:
            if (y - i < 0 || x - i < 0 || (i == 1 && (!map[y - i][x - i] || map[y - i][x - i] != 'M')) ||
                (i == 2 && (!map[y - i][x - i] || map[y - i][x - i] != 'A')) ||
                (i == 3 && (!map[y - i][x - i] || map[y - i][x - i] != 'S')))
                return false;
            break;
        case UPRIGHT:
            if (y - i < 0 || x + i >= map[y].size() || (i == 1 && (!map[y - i][x + i] || map[y - i][x + i] != 'M')) ||
                (i == 2 && (!map[y - i][x + i] || map[y - i][x + i] != 'A')) ||
                (i == 3 && (!map[y - i][x + i] || map[y - i][x + i] != 'S')))
                return false;
            break;
        case DOWNLEFT:
            if (y + i >= map->size() || x - i < 0 || (i == 1 && (!map[y + i][x - i] || map[y + i][x - i] != 'M')) ||
                (i == 2 && (!map[y + i][x - i] || map[y + i][x - i] != 'A')) ||
                (i == 3 && (!map[y + i][x - i] || map[y + i][x - i] != 'S')))
                return false;
            break;
        case DOWNRIGHT:
            if (y + i >= map->size() || x + i >= map[y].size() || (i == 1 && (!map[y + i][x + i] || map[y + i][x + i] != 'M')) ||
                (i == 2 && (!map[y + i][x + i] || map[y + i][x + i] != 'A')) ||
                (i == 3 && (!map[y + i][x + i] || map[y + i][x + i] != 'S')))
                return false;
            break;
        default:
            break;
        }
    }
    return true;
}

int findXmas(std::string* map, int x, int y)
{
    int count = 0;

    if (y - 1 >= 0 && map[y - 1][x] && map[y - 1][x] == 'M') {
        if (trySide(map, x, y, UP) == true)
            count++;
    }
    if (y + 1 < map->size() && map[y + 1][x] && map[y + 1][x] == 'M') {
        if (trySide(map, x, y, DOWN) == true)
            count++;
    }
    if (x - 1 >= 0 && map[y][x - 1] && map[y][x - 1] == 'M') {
        if (trySide(map, x, y, LEFT) == true)
            count++;
    }
    if (x + 1 < map[y].size() && map[y][x + 1] && map[y][x + 1] == 'M') {
        if (trySide(map, x, y, RIGHT) == true)
            count++;
    }
    if (y - 1 >= 0 && x - 1 >= 0 && map[y - 1][x - 1] && map[y - 1][x - 1] == 'M') {
        if (trySide(map, x, y, UPLEFT) == true)
            count++;
    }
    if (y - 1 >= 0 && x + 1 < map[y].size() && map[y - 1][x + 1] && map[y - 1][x + 1] == 'M') {
        if (trySide(map, x, y, UPRIGHT) == true)
            count++;
    }
    if (y + 1 < map->size() && x - 1 >= 0 && map[y + 1][x - 1] && map[y + 1][x - 1] == 'M') {
        if (trySide(map, x, y, DOWNLEFT) == true)
            count++;
    }
    if (y + 1 < map->size() && x + 1 < map[y].size() && map[y + 1][x + 1] && map[y + 1][x + 1] == 'M') {
        if (trySide(map, x, y, DOWNRIGHT) == true)
            count++;
    }

    return count;
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
            if(map[y][x] == 'X')
                solution += findXmas(map, x, y);
        }
    }
    std::cout << "Solution: " << solution << std::endl;
    
}