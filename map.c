/*
** map.c for generic_map in /home/colin_g/github/generic_map
**
** Made by julien colin
** Login  <colin_g@epitech.eu>
**
** Started on  mer. juin 25 14:19:32 2014 julien colin
** Last update mer. juin 25 15:18:40 2014 julien colin
*/

#include <stdlib.h>
#include "map.h"

t_map   *map_new(cmp_func func)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    map->node = 0;
    map->func_cmp = func;
    return (map);
}

void    *map_find(t_map *map, void *key)
{
    t_node  *tmp;

    tmp = map->node;
    while (tmp)
    {
        if (map->func_cmp(tmp->key, key) == 0)
            return (tmp->value);
        tmp = tmp->next;
    }
    return (0);
}

void    map_add(t_map *map, void *key, void *value)
{
    t_node  *tmp;
    t_node  *new;

    new = malloc(sizeof(t_node));
    new->key = key;
    new->value = value;
    new->next = 0;
    if (!map->node)
        map->node = new;
    else
    {
        tmp = map->node;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void    free_list(t_node *node)
{
    if (node && node->next)
        free_list(node->next);
    free(node);
}

void    map_clear(t_map *map)
{
    free_list(map->node);
    free(map);
    map = 0;
}

size_t  map_size(t_map *map)
{
    t_node  *tmp;
    size_t  s;

    s = 0;
    tmp = map->node;
    while (tmp)
    {
        ++s;
        tmp = tmp->next;
    }
    return (s);
}
