/*
** my_sokoban.h for my_sokoban in /home/killin_m/Code/Project/Prog-Sys-Unix/PSU_2015_my_sokoban
**
** Made by Maxime Killinger
** Login   <killin_m@killin_m-arch>
**
** Started on  Wed Jan  6 13:46:25 2016 Maxime Killinger
** Last update Sun Jan 17 17:42:09 2016 Maxime Killinger
*/

#ifndef MY_SOKOBAN_H_
# define MY_SOKOBAN_H_

# define UP 65
# define DOWN 66
# define LEFT 68
# define RIGHT 67
# define SPACE 32

typedef struct s_map {
    char **map;
    char *path;
    int lines;
    int columns;
} t_map;

void take_map(t_map *save);

char *read_map(char *path);

void print_map(t_map *save);

void print_loop(t_map *save);

void key(t_map *save, int k);

void key_up(t_map *save, int i, int j);

void key_up_two(t_map *save, int i, int j);

void key_up_three(t_map *save, int i, int j);

void key_down(t_map *save, int i, int j);

void key_down_two(t_map *save, int i, int j);

void key_down_three(t_map *save, int i, int j);

void key_right(t_map *save, int i, int j);

void key_right_two(t_map *save, int i, int j);

void key_right_three(t_map *save, int i, int j);

void key_left(t_map *save, int i, int j);

void key_left_two(t_map *save, int i, int j);

void key_left_three(t_map *save, int i, int j);

void key_space(t_map *save);

int end_of_game(t_map *save);

void check_size(t_map *map);

char **my_str_to_wordtab(char *, char);

void color_list(void);

void print_in_color(t_map *save, int i, int j);

void print_name_color();

#endif /* !MY_SOKOBAN_H_ */
