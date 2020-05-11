#include <stdio.h>
#include <string.h>
#include "objects.h"

#ifndef MEMORY_H
#define MEMORY_H

struct ByArena
{
    char name[256];
    ByObject *object;
    struct ByArena *next;
};

struct ByArena *append_to_arena(struct ByArena *head, struct ByArena *new)
{
    struct ByArena *node = head;
    while (node->next != NULL)
        node = node->next;
    node->next = new;
    return head;
}

ByObject *get_object(struct ByArena *arena, char *name)
{
    struct ByArena *node = arena;
    while (strcmp(node->name, name) != 0)
        node = node->next;

    if (node->object)
        return node->object;
    else {
        printf("NameError\n");
        exit(0);
    }
}

#endif /* MEMORY_H */
