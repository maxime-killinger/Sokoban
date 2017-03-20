//
// Created by Maxime Killinger on 20/03/2017.
//

#include <ncurses.h>
#include "my_sokoban.h"

void check_size(t_map *save) {
    if (save->lines > LINES || save->columns > COLS)
        while (save->lines > LINES || save->columns > COLS)
            printw("Size too short\n");
    return;
}
