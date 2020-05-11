#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "objects.h"
#include "compile.h"

void execute(struct ByCodeObject *co, struct ByArena *arena)
{
    int param1, param2;
    while (co)
    {
        // printf("sdfvdf");
        switch (co->opcode)
        {
        case Assign:
            printf("Instruction: ");
            strcpy(arena->name, co->next->data.char_value);
            // ByObject *obj = (ByObject *)malloc(sizeof(ByObject));
            // obj->type = Integer;
            // obj->value.int_value = co->next->next->data.int_value;
            // arena->object = obj;
            // arena->next = NULL;
            printf("Assign %d to %s\n", co->next->next->data.int_value,
                   co->next->data.char_value);
            ByObject *obj = ByObject_Create(Integer, co->next->next->data);
            printf("Integer object created at <%p>\n", obj);
            co = co->next->next->next;
            break;
        case Assign_List:
        {
            printf("Instruction: ");
            strcpy(arena->name, co->next->data.char_value);
            // ByObject *obj = (ByObject *)malloc(sizeof(ByObject));
            // obj->type = Integer;
            // obj->value.int_value = co->next->next->data.int_value;
            // arena->object = obj;
            // arena->next = NULL;
            printf("Assign %d to %s\n", co->next->next->data.int_value,
                   co->next->data.char_value);
            struct ByObject_List *obj2 = ByObject_List_Create(
                Integer,
                co->next->next->data,
                co->next->next->next->data,
                co->next->next->next->next->data);
            printf("Integer object created at <%p>\n", obj2);
            co = co->next->next->next;
            break;
        }
        case Load:
            printf("");
            ByObject *obj3 = get_object(arena, co->next->data.char_value);
            printf("Instruction: Load %s\n", co->next->data.char_value);
            printf("%d\n", obj3->value.int_value);
            co = co->next->next;
            break;

        default:
            printf("");
            break;
        }
    }
}
