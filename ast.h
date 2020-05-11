#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"

#ifndef AST_H
#define AST_H

typedef enum
{
    Assign,
    Assign_List,
    BinOp,
    Load,
    Nil
} Operation;

struct ByAst_Node
{
    Operation operation;
    struct ByAst_Node *param1;
    struct ByAst_Node *param2;
    struct ByAst_Node *param3;
    int test;
    Data name, value;
};

// struct ByAst_Node *traverse(struct ByAst_Node *node)
// {
//     switch (node->operation)
//     {
//     case Assign:
//         return assign();
//     default:
//         return node->value;
//     }
// }

#endif /* AST_H */

// int main()
// {
//     struct ByAst_Node *head = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
//     head->operation = Assign;

//     head->param1 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
//     head->param1->operation = Nil;
//     head->param1->param1 = NULL;
//     head->param1->param2 = NULL;
//     strcpy(head->param1->name.char_value, "x");

//     head->param2 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
//     head->param2->operation = Nil;
//     head->param2->param1 = NULL;
//     head->param2->param2 = NULL;
//     head->param2->value.int_value = 5;

//     traverse(head);
// }