#include <stdlib.h>
#include <stdlib.h>

#include "memory.h"
#include "tok.h"
#include "ast.h"
#include "compile.h"
#include "execution.h"

int main()
{
    // Create memory
    printf("Creating a virtual memory space...\n");
    struct ByArena *arena = (struct ByArena *)malloc(sizeof(struct ByArena));

    // REPL session
    while (1)
    {
        printf(">>> ");

        // Read and preprocess
        char statement[256];
        fgets(statement, sizeof(statement), stdin);
        size_t len = strlen(statement) - 1;
        if (*statement && statement[len - 1] == ':')
            printf("WIP\n");
        else if (*statement && statement[len] == '\n')
            statement[len] = '\0';

        // Tokenise
        printf("Parsing and creating AST...\n");
        struct ByAst_Node *ast = fake_parse_statement(statement);

        // Compile
        printf("Compiling... ");
        struct ByCodeObject *bycode = compile(ast);

        // Execute
        printf("Executing...\n");
        execute(bycode, arena);
    }

    // Free memory
    // free(arena);

    return 0;
}
