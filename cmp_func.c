/*
** cmp_func.c for generic_map in /home/colin_g/github/generic_map
**
** Made by julien colin
** Login  <colin_g@epitech.eu>
**
** Started on  mer. juin 25 14:19:32 2014 julien colin
** Last update mer. juin 25 15:19:21 2014 julien colin
*/

#include <string.h>
#include "cmp_func.h"

int cmp_int(void *i1, void *i2)
{
    if ((int)i1 == (int)i2)
        return (0);
    return (-1);
}

int cmp_string(void *s1, void *s2)
{
    return (strcmp((char *)s1, (char *)s2));
}
