#include <stdlib.h>
#include <string.h>
#include "ast.h"

#ifndef COMPILE_H
#define COMPILE_H

struct ByCodeObject
{
    union {
        Operation opcode;
        Data data;
    };
    struct ByCodeObject *next;
};

struct ByCodeObject *create_code_object(void)
{
    struct ByCodeObject *obj = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
    return obj;
}

struct ByCodeObject *compile(struct ByAst_Node *ast)
{
    struct ByCodeObject *co = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
    co->opcode = ast->operation;

    switch (ast->operation)
    {
    case Assign:
        co->next = create_code_object();
        strcpy(co->next->data.char_value, ast->param1->name.char_value);
        co->next->next = create_code_object();
        co->next->next->data.int_value = ast->param2->value.int_value;
        break;
    case Assign_List:
        co->next = create_code_object();
        strcpy(co->next->data.char_value, ast->param1->name.char_value);
        co = co->next;
        co->next = create_code_object();
        co->next->data.int_value = ast->param2->value.int_value;
        co = co->next;
        co->next = create_code_object();
        co->next->data.int_value = ast->param3->value.int_value;
        break;
    case Load:
        co->next = create_code_object();
        strcpy(co->next->data.char_value, ast->param1->name.char_value);
        break;
    case BinOp:
        // co->next = create_code_object();
        // strcpy(co->next->data.char_value, ast->param1->name.char_value);
        // co->next->next = create_code_object();
        // co->next->next->data.int_value = ast->param2->value.int_value;
        break;
    default:
        break;
    }
    return co;
}

// struct ByCodeObject *fake_compile(void)
// {
//     struct ByCodeObject *code;

//     struct ByCodeObject *head = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     head->opcode = 1;
//     code = head;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->data = 4;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->data = 3;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->opcode = 2;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->data = 1;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->data = 8;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->opcode = 3;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->data = 0;

//     code->next = (struct ByCodeObject *)malloc(sizeof(struct ByCodeObject));
//     code = code->next;
//     code->data = 1;

//     code->next = NULL;

//     return head;
// }

#endif /* COMPILE_H */
