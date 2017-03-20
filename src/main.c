//
// Created by Maxime Killinger on 20/03/2017.
//

#include <stdio.h>
#include "my_sokoban.h"

int main(int ac, char **av) {
    t_map save;

    if (ac != 2) {
        fprintf(stderr, "Use : %s map.txt.\n", av[0]);
        return (-1);
    } else {
        save.path = av[1];
        take_map(&save);
    }
    return (0);
}
