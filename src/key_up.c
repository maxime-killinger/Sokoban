//
// Created by Maxime Killinger on 20/03/2017.
//

#include "my_sokoban.h"

void key_up(t_map *save, int i, int j) {
    if (save->map[i - 1][j] == 'O') {
        save->map[i - 1][j] = 'p';
        save->map[i][j] = (save->map[i][j] == 'p') ? 'O' : ' ';
    } else if (save->map[i - 1][j] == 'x' && (save->map[i - 2][j] == '#' ||
                                              save->map[i - 2][j] == 'X' ||
                                              save->map[i - 2][j] == 'x'));
    else if (save->map[i][j] == 'p' && save->map[i - 1][j] == '#');
    else if (save->map[i - 1][j] == 'X' && save->map[i][j] == 'p') {
        if (save->map[i - 2][j] == '#');
        else if (save->map[i - 2][j] == 'O') {
            save->map[i - 2][j] = 'x';
            save->map[i][j] = (save->map[i - 1][j] = 'P') ? 'O' : 'O';
        } else if (save->map[i - 2][j] == ' ') {
            save->map[i - 2][j] = 'X';
            save->map[i][j] = (save->map[i - 1][j] = 'P') ? 'O' : 'O';
        }
    } else
        key_up_two(save, i, j);
}

void key_up_two(t_map *save, int i, int j) {
    if (save->map[i - 1][j] == 'x') {
        save->map[i - 2][j] = (save->map[i - 2][j] == 'O') ? 'x' : 'X';
        save->map[i - 1][j] = 'p';
        save->map[i][j] = (save->map[i][j] == 'p') ? 'O' : ' ';
    } else if (save->map[i - 1][j] == 'X' && save->map[i - 2][j] == 'O') {
        save->map[i - 2][j] = 'x';
        save->map[i - 1][j] = save->map[i][j];
        save->map[i][j] = ' ';
    } else if (save->map[i - 1][j] == 'X' && save->map[i - 2][j] != '#'
               && save->map[i - 2][j] != 'X' && save->map[i - 2][j] != 'x') {
        save->map[i - 2][j] = save->map[i - 1][j];
        save->map[i - 1][j] = save->map[i][j];
        save->map[i][j] = ' ';
    } else
        key_up_three(save, i, j);
}

void key_up_three(t_map *save, int i, int j) {
    if (save->map[i - 1][j] == 'X' && (save->map[i - 2][j] == '#' ||
                                       save->map[i - 2][j] == 'X' ||
                                       save->map[i - 2][j] == 'x'));
    else if (save->map[i][j] == 'p') {
        save->map[i - 1][j] = (save->map[i - 1][j] == 'O') ? 'p' : 'P';
        save->map[i][j] = 'O';
    } else if (save->map[i - 1][j] != '#') {
        save->map[i - 1][j] = 'P';
        save->map[i][j] = ' ';
    }
}
