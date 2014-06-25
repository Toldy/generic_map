#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "cmp_func.h"

int main(int ac, char **av)
{
    t_map   *map_str_str;
    t_map   *map_int_str;
    int     i;

    map_str_str = map_new(&cmp_string);
    map_int_str = map_new(&cmp_int);
    printf("Map size : %zu\n", map_size(map_str_str));
    i = -1;
    while (++i < ac) {
        map_add(map_int_str, (void*)i, av[i]);
        map_add(map_str_str, av[i], av[i]);
    }

    printf("Map size : %zu\n", map_size(map_str_str));
    printf("[Salut] => %s\n", (char *)map_find(map_str_str, (void*)"Salut"));
    printf("[amis] => %s\n", (char *)map_find(map_str_str, (void*)"amis"));
    printf("[les] => %s\n", (char *)map_find(map_str_str, (void*)"les"));
    printf("[yo] => %s\n", (char *)map_find(map_str_str, (void*)"yo"));

    printf("[0] => %s\n", (char *)map_find(map_int_str, (void*)0));
    printf("[1] => %s\n", (char *)map_find(map_int_str, (void*)1));
    printf("[2] => %s\n", (char *)map_find(map_int_str, (void*)2));
    printf("[3] => %s\n", (char *)map_find(map_int_str, (void*)3));
    map_clear(map_str_str);
    map_clear(map_int_str);

    return (0);
}
