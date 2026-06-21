//
// Created by felipe on 16/06/2026.
//

#ifndef C_DATA_STRUCTURE_STACK_H
#define C_DATA_STRUCTURE_STACK_H
#include <stdint.h>

enum ItemType {
    IS_STRING,
    IS_INT,
    IS_DOUBLE,
    IS_FLOAT,
    IS_BOOL,
    IS_POINTER
} ;
typedef struct {
    union {
        int64_t  intValue;
        float    floatValue;
        double   doubleValue;
        bool     boolValue;
        void*    pointerValue;
        char*    stringValue;
    };
    enum ItemType itemType;
} StackItem;

typedef struct{
    int top;
    int size;
    StackItem* items;
} Stack;

Stack* StackCreate();

bool StackPush(Stack *stack, StackItem item);

void* StackPop(Stack *stack);

void* StackPeek(const Stack *stack);

bool StackIsEmpty(const Stack *stack);

void StackDestroy(Stack *stack);

#endif //C_DATA_STRUCTURE_STACK_H
