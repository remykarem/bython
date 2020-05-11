#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node_t {
    int op;
    struct Node_t* left;
    struct Node_t* right;
};

typedef struct
{
    char name[64];
    float value[];
} ByObject_List;

typedef struct
{

} CallStack;

int num_objects = 0;

float eval(float num1, char op, float num2)
{
    printf("EVALUATE %f and %f\n", num1, num2);
    if (op == '+')
        return num1 + num2;
    else if (op == '-')
        return num1 - num2;
    else if (op == '*')
        return num1 * num2;
    else
        return num1 / num2;
}

float retrieve(char *name, int* result)
{
    printf("LOAD %s\n", name);
    // Named
    for (int i = 0; i < num_objects; i++)
    {
        if (strcmp(names[i]->name, name) == 0)
        {
            // printf("%f\n", names[i]->value);
            return names[i]->value;
        }
    }

    
}

void assign(char *name, float value)
{
    printf("ASSIGN %s to %f\n", name, value);
    // Check if there's an existing assignment
    // if (retrieve(name)) {
    //     printf("Error: Attempting to reassign to an existing value\n");
    //     exit(1);
    // }

    ByObject *obj = (ByObject *)malloc(sizeof(ByObject));
    strcpy(obj->name, name);
    obj->value = value;

    names[num_objects] = obj;
    // printf("%s: %f\n", names[num_objects]->name, names[num_objects]->value);
    num_objects++;
}

// Tokenise
float parse_statement(char *statement)
{
    if (strstr(statement, "(") != NULL)
    {

        // printf("This is a callable\n");

        char caller[256];
        char rhs[256];
        char params[256];

        sscanf(strtok(statement, "("), "%s", caller);
        sscanf(strtok(NULL, "("), "%s", rhs);
        sscanf(strtok(rhs, ")"), "%s", params);

        printf("caller: %s\n", caller);
        printf("params: %s\n", rhs);
        // printf("params: %s\n", params);
    }
    else if (strcmp(statement, "globals()") == 0)
    {
        for (int i = 0; i < num_objects; i++)
            printf("%s: %f\n", names[i]->name, names[i]->value);
    }
    else if (strstr(statement, "=") != NULL)
    {
        // printf("This is an assignment (for now)\n");

        char name[256];
        char rhs[256];

        sscanf(strtok(statement, "="), "%s", name);
        sscanf(strtok(NULL, "="), "%s", rhs);
        // printf("rhs: %s\n", rhs);

        assign(name, parse_statement(rhs));
        return -1;
    }
    else if (strstr(statement, "->") != NULL)
    {
        // printf("This is an assignment (for now)\n");

        char name[256];
        char rhs[256];

        sscanf(strtok(statement, "->"), "%s", rhs);
        sscanf(strtok(NULL, "->"), "%s", name);
        // printf("rhs: %s\n", rhs);

        assign(name, parse_statement(rhs));
        return -1;
    }
    else if (strstr(statement, "+") != NULL)
    {
        // printf("This is an eval (for now)\n");

        char lhs[256];
        char rhs[256];
        float ret;

        sscanf(strtok(statement, "+"), "%s", lhs);
        sscanf(strtok(NULL, "+"), "%s", rhs);

        ret = eval(parse_statement(lhs), '+', parse_statement(rhs));
        printf("%f\n", ret);
        return ret;
    }
    else
    {
        // atoms

        // printf("This is a retrieval (for now)\n");

        char name[256];
        float number;
        int is_number;

        is_number = sscanf(strtok(statement, "="), "%f", &number);
        if (is_number)
            return number;
        else
        {
            sscanf(strtok(statement, "="), "%s", name);
            number = retrieve(name);
            return number;
        }
    }

    return -999999;
}

int main()
{
    // REPL session
    while (1)
    {
        printf(">>> ");

        // Read
        char statement[256];
        fgets(statement, sizeof(statement), stdin);
        size_t len = strlen(statement) - 1;
        if (*statement && statement[len-1] == ':')
            printf("WIP\n");
        else if (*statement && statement[len] == '\n')
            statement[len] = '\0';

        parse_statement(statement);
    }

    // Memory management
    for (int i = 0; i < num_objects; i++)
        free(names[i]);

    return 0;
}
