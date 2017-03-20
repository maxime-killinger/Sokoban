//
// Created by Maxime Killinger on 20/03/2017.
//

#include "my_sokoban.h"

void key(t_map *save, int k) {
    int i;
    int j;

    i = 0;
    while (save->map[i]) {
        j = 0;
        while (save->map[i][j]) {
            if (save->map[i][j] == 'P' || save->map[i][j] == 'p') {
                (k == UP) ? key_up(save, i, j) :
                (k == DOWN) ? key_down(save, i, j) :
                (k == RIGHT) ? key_right(save, i, j) :
                (k == LEFT) ? key_left(save, i, j) :
                (k == SPACE) ? key_space(save) : 0;
                return;
            }
            j = j + 1;
        }
        i = i + 1;
    }
}
