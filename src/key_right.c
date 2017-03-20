///
// Created by Maxime Killinger on 20/03/2017.
//

#include "my_sokoban.h"

void key_right(t_map *save, int i, int j) {
    if (save->map[i][j + 1] == 'O') {
        save->map[i][j + 1] = 'p';
        save->map[i][j] = (save->map[i][j] == 'p') ? 'O' : ' ';
    } else if (save->map[i][j - 1] == 'x' && (save->map[i][j + 2] == '#' ||
                                              save->map[i][j + 2] == 'X' ||
                                              save->map[i][j + 2] == 'x'));
    else if (save->map[i][j] == 'p' && save->map[i][j + 1] == '#');
    else if (save->map[i][j + 1] == 'X' && save->map[i][j] == 'p') {
        if (save->map[i][j + 2] == '#');
        else if (save->map[i][j + 2] == 'O') {
            save->map[i][j + 2] = 'x';
            save->map[i][j] = (save->map[i][j + 1] = 'P') ? 'O' : 'O';
        } else if (save->map[i][j + 2] == ' ') {
            save->map[i][j + 2] = 'X';
            save->map[i][j] = (save->map[i][j + 1] = 'P') ? 'O' : 'O';
        }
    } else
        key_right_two(save, i, j);
}

void key_right_two(t_map *save, int i, int j) {
    if (save->map[i][j + 1] == 'x') {
        save->map[i][j + 2] = (save->map[i][j + 2] == 'O') ? 'x' : 'X';
        save->map[i][j + 1] = 'p';
        save->map[i][j] = (save->map[i][j] == 'p') ? 'O' : ' ';
    } else if (save->map[i][j + 1] == 'X' && save->map[i][j + 2] == 'O') {
        save->map[i][j + 2] = 'x';
        save->map[i][j + 1] = save->map[i][j];
        save->map[i][j] = ' ';
    } else if (save->map[i][j + 1] == 'X' && save->map[i][j + 2] != '#'
               && save->map[i][j + 2] != 'X' && save->map[i][j + 2] != 'x') {
        save->map[i][j + 2] = save->map[i][j + 1];
        save->map[i][j + 1] = save->map[i][j];
        save->map[i][j] = ' ';
    } else
        key_right_three(save, i, j);
}

void key_right_three(t_map *save, int i, int j) {
    if (save->map[i][j + 1] == 'X' && (save->map[i][j + 2] == '#' ||
                                       save->map[i][j + 2] == 'X' ||
                                       save->map[i][j + 2] == 'x'));
    else if (save->map[i][j] == 'p') {
        save->map[i][j + 1] = (save->map[i][j + 1] == 'O') ? 'p' : 'P';
        save->map[i][j] = 'O';
    } else if (save->map[i][j + 1] != '#') {
        save->map[i][j + 1] = 'P';
        save->map[i][j] = ' ';
    }
}
