#include <stdlib.h>
#include <string.h>
#include "ast.h"

#ifndef TOK_H
#define TOK_H

struct ByAst_Node *fake_parse_statement(char *statement)
{
    if (strstr(statement, "=") != NULL)
    {
        printf("This is an assignment ");

        char lhs_name[256];
        char rhs[256];
        int rhs_int;

        sscanf(strtok(statement, "="), "%s", lhs_name);
        if (sscanf(strtok(NULL, "="), "%s", rhs))
        {
            printf("(list).\n"); 

            int leftbound, rightbound;
            sscanf(strtok(rhs, "..."), "%d", &leftbound);
            sscanf(strtok(NULL, "..."), "%d", &rightbound);
            if (leftbound > rightbound)
                exit(0);
            
            struct ByAst_Node *ast = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            ast->operation = Assign_List;
            ast->param1 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            ast->param2 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            ast->param3 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            strcpy(ast->param1->name.char_value, lhs_name);
            ast->param2->value.int_value = leftbound;
            ast->param3->value.int_value = rightbound;
            return ast;
        }
        else
        // if (sscanf(strtok(NULL, "="), "%d", &rhs_int))
        {
            printf("(numeric)\n");

            struct ByAst_Node *ast = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            ast->operation = Assign;
            ast->param1 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            ast->param2 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
            strcpy(ast->param1->name.char_value, lhs_name);
            ast->param2->value.int_value = rhs_int;
            return ast;
        }
    }
    else if (strcmp(statement, "exit") == 0)
    {
        printf("Bye!\n");
        exit(0);
    }
    else if (strstr(statement, "+") != NULL)
    {
        printf("This is an operation.\n");
        exit(0);

        // char lhs[256];
        // char rhs[256];
        // float ret;

        // sscanf(strtok(statement, "+"), "%s", lhs);
        // sscanf(strtok(NULL, "+"), "%s", rhs);

        // ret = eval(parse_statement(lhs), '+', parse_statement(rhs));
        // printf("%f\n", ret);
        // return ret;
    }
    else if (strstr(statement, "func") != NULL)
    {
        printf("This is a function definition\n");

        exit(0);
    }
    else
    {
        printf("This is loading.\n");

        struct ByAst_Node *ast = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
        ast->operation = Load;
        ast->param1 = (struct ByAst_Node *)malloc(sizeof(struct ByAst_Node));
        strcpy(ast->param1->name.char_value, statement);

        return ast;
    }
}

#endif /* TOK_H */

// struct ByAST_Node* parse_statement(char *statement)
// {
//     if (strstr(statement, "(") != NULL)
//     {

//         // printf("This is a callable\n");

//         char caller[256];
//         char rhs[256];
//         char params[256];

//         sscanf(strtok(statement, "("), "%s", caller);
//         sscanf(strtok(NULL, "("), "%s", rhs);
//         sscanf(strtok(rhs, ")"), "%s", params);

//         printf("caller: %s\n", caller);
//         printf("params: %s\n", rhs);
//         // printf("params: %s\n", params);
//     }
//     else if (strcmp(statement, "globals()") == 0)
//     {
//         for (int i = 0; i < num_objects; i++)
//             printf("%s: %f\n", names[i]->name, names[i]->value);
//     }
//     else
//     {
//         char name[256];
//         float number;
//         int is_number;

//         is_number = sscanf(strtok(statement, "="), "%f", &number);
//         if (is_number)
//             return number;
//         else
//         {
//             sscanf(strtok(statement, "="), "%s", name);
//             number = retrieve(name);
//             return number;
//         }
//     }

//     return -999999;
// }