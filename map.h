/*
** map.h for generic_map in /home/colin_g/github/generic_map
**
** Made by julien colin
** Login  <colin_g@epitech.eu>
**
** Started on  mer. juin 25 14:28:10 2014 julien colin
** Last update mer. juin 25 15:18:41 2014 julien colin
*/

#ifndef MAP_H_
# define MAP_H_

typedef int (*cmp_func)(void *, void *);

typedef struct s_node {
    void            *key;
    void            *value;
    struct s_node   *next;
} t_node;

typedef struct s_map {
    t_node      *node;
    cmp_func    func_cmp;
} t_map;

t_map   *map_new(cmp_func func);
void    *map_find(t_map *map, void *key);
void    map_add(t_map *map, void *key, void *value);
void    map_clear(t_map *map);
size_t  map_size(t_map *map);

#endif /* !MAP_H_ */
