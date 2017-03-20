//
// Created by Maxime Killinger on 20/03/2017.
//

#include <ncurses.h>
#include "my_sokoban.h"

void color_list(void) {
    start_color();
    curs_set(0);
    init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(7, COLOR_CYAN, COLOR_CYAN);
    init_pair(10, COLOR_CYAN, COLOR_WHITE);
    init_pair(11, COLOR_RED, COLOR_WHITE);
    init_pair(12, COLOR_BLUE, COLOR_WHITE);
    init_pair(13, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(14, COLOR_BLACK, COLOR_WHITE);
}

void print_in_color(t_map *save, int i, int j) {
    if (save->map[i][j] == 'x')
        attron(COLOR_PAIR(2)) ? printw("X ") : printw("X ");
    else if (save->map[i][j] == 'P')
        attron(COLOR_PAIR(3)) ? printw("P ") : printw("P ");
    else if (save->map[i][j] == '#')
        attron(COLOR_PAIR(4)) ? printw("# ") : printw("# ");
    else if (save->map[i][j] == 'O')
        attron(COLOR_PAIR(5)) ? printw("O ") : printw("O ");
    else if (save->map[i][j] == 'p')
        attron(COLOR_PAIR(6)) ? printw("P ") : printw("P ");
    else if (save->map[i][j] == 'X')
        attron(COLOR_PAIR(7)) ? printw("X ") : printw("X ");
    else
        attron(COLOR_PAIR(1)) ? printw("%c ", save->map[i][j]) :
        printw("%c ", save->map[i][j]);
}

void print_name_color() {
    attron(COLOR_PAIR(10));
    printw("S");
    attron(COLOR_PAIR(11));
    printw("O");
    attron(COLOR_PAIR(12));
    printw("K");
    attron(COLOR_PAIR(13));
    printw("O");
    attron(COLOR_PAIR(14));
    printw("B");
    attron(COLOR_PAIR(10));
    printw("A");
    attron(COLOR_PAIR(11));
    printw("N\n\n");
}
