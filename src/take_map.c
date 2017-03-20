//
// Created by Maxime Killinger on 20/03/2017.
//

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_sokoban.h"

void take_map(t_map *save) {
    int i;
    int j;
    char *buff;

    i = 0;
    j = 0;
    buff = read_map(save->path);
    if (buff)
        save->map = my_str_to_wordtab(buff, '\n');
    else
        return;
    save->columns = 0;
    while (save->map[i]) {
        while (save->map[i][j++]);
        if (save->columns < j)
            save->columns = j;
        i++;
    }
    save->lines = i;
    print_map(save);
}

char *read_map(char *path) {
    int fd;
    char *buff;

    if ((buff = malloc(sizeof(char) * 400)) == NULL)
        return (NULL);
    if ((fd = open(path, O_RDWR)) == -1) {
        fprintf(stderr, "The file \"%s\" does not exist\n", path);
        return (NULL);
    } else if (read(fd, buff, 395) == -1) {
        fprintf(stderr, "The file \"%s\" does not be read\n", path);
        return (NULL);
    }
    if (close(fd) == -1) {
        fprintf(stderr, "The file \"%s\" does not be close\n", path);
        return (NULL);
    }
    return (buff);
}

void print_map(t_map *save) {
    int k;
    int l;

    initscr();
    while (end_of_game(save) != 1) {
        clear();
        move((LINES / 2) - (save->lines / 2) - 2, (COLS / 2 - 3));
        print_name_color();
        print_loop(save);
        check_size(save);
        if ((l = getch()) == 27) {
            getch();
            (k = getch()) ? key(save, k) : 0;
        } else
            key(save, l);
    }
    endwin();
}

int end_of_game(t_map *save) {
    int i;
    int j;

    i = 0;
    while (save->map[i]) {
        j = 0;
        while (save->map[i][j]) {
            if (save->map[i][j] == 'O')
                return (0);
            if (save->map[i][j++] == 'p')
                return (0);
        }
        i = i + 1;
    }
    clear();
    move((LINES / 2) - (save->lines / 2) - 2, (COLS / 2 - 3));
    print_name_color();
    print_loop(save);
    attron(COLOR_PAIR(3));
    printw("YOU WIN !");
    getch();
    return (1);
}

void print_loop(t_map *save) {
    int i;
    int j;

    i = 0;
    color_list();
    while (save->map[i] != NULL) {
        j = 0;
        while (save->map[i][j] != '\0') {
            move((LINES / 2) - (save->lines / 2) + i,
                 (COLS / 2) - (save->columns / 2) + (j * 2));
            print_in_color(save, i, j);
            j = j + 1;
        }
        i = i + 1;
        printw("\n");
    }
}
