#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef OBJECTS_H
#define OBJECTS_H

typedef enum
{
    Integer,
    Float,
    Function
} Type;

typedef union {
    int int_value;
    float float_value;
    char char_value[16];
} Data;

typedef struct
{
    Type type;
    union {
        Data value;                // for numerics
        struct ByCodeObject *code; // for functions
    };
    int refcnt;
} ByObject;

struct ByObject_List
{
    Type type;
    Data value;
    struct ByObject_List *next;
    int refcnt;
};

ByObject *
ByObject_Create(Type type, Data value)
{
    ByObject *obj = (ByObject *)malloc(sizeof(ByObject));
    obj->type = type;
    obj->value.int_value = value.int_value;
    obj->refcnt = obj->refcnt + 1;
    return obj;
}

struct ByObject_List *
ByObject_List_Create(Type type, Data value, Data left, Data right)
{
    struct ByObject_List *head, *obj;
    head = (struct ByObject_List *)malloc(sizeof(struct ByObject_List));
    head->type = type;
    head->value.int_value = left.int_value;
    obj = head;

    for (int val = left.int_value+1; val <= right.int_value; val++)
    {
        obj->next = (struct ByObject_List *)malloc(sizeof(struct ByObject_List));
        obj = obj->next;
        obj->type = type;
        obj->value.int_value = val;
    }

    return head;
}

ByObject *
ByObject_Add(ByObject *obj1, ByObject *obj2)
{
    ByObject *ret = (ByObject *)malloc(sizeof(ByObject));
    if (ret == NULL)
        exit(1);

    if (obj1->type == Integer && obj2->type == Integer)
    {
        ret->type = Integer;
        ret->value.int_value = obj1->value.int_value + obj2->value.int_value;
        return ret;
    }
    else if (obj1->type == Float && obj2->type == Float)
    {
        ret->type = Float;
        ret->value.float_value = obj1->value.float_value + obj2->value.float_value;
        return ret;
    }
    else
    {
        printf("Not the same type...\n");
        exit(1);
    }
}

#endif /* OBJECTS_H */

// int main()
// {

//     ByName byname;
//     strcpy(byname.name, "x");
//     byname.object = (ByObject *)malloc(sizeof(ByObject));
//     if (byname.object == NULL)
//         exit(1);

//     byname.object->type = Float;
//     byname.object->value.float_value = 0;

//     printf("%d %f\n", byname.object->type, byname.object->value.float_value);
//     free(byname.object);

//     return 0;
// }
