//
// Created by Maxime Killinger on 20/03/2017.
//

#include <string.h>
#include <stdlib.h>

int count_sep(char *str, char sep) {
    static int i = 0;

    while (str[i] != sep)
        i = i + 1;
    return (i);
}

char **my_str_to_wordtab(char *str, char sep) {
    char **tab;
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    if ((tab = malloc(sizeof(char *) * strlen(str))) == NULL)
        return (NULL);
    while (str[k]) {
        j = 0;
        if ((tab[i] = malloc(sizeof(char) * count_sep(str, sep))) == NULL)
            return (NULL);
        while (str[k] != sep && str[k] != '\0')
            tab[i][j++] = str[k++];
        (tab[i++][j] = '\0');
        k += (str[k] != '\0') ? 1 : 0;
    }
    tab[i] = NULL;
    return (tab);
}
