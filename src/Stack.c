//
// Created by felipe on 16/06/2026.
//

#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack *StackCreate() {
    Stack *stack = malloc(sizeof(Stack));
    if (!stack) {
        return nullptr;
    }
    stack->size = 0;
    stack->top = -1;
    stack->items = (StackItem*) malloc(sizeof(StackItem) * 4);
    if (!stack->items) {
        free(stack);
        return nullptr;
    }
    return stack;
}

bool StackPush(Stack *stack, const StackItem item) {

    constexpr size_t stackSize = sizeof(*stack->items);
    const size_t stackNewSize = (stack->size + 1) * sizeof(StackItem);

    if (stackNewSize >= stackSize ) {
        StackItem *items = realloc(stack->items, stackNewSize * 4);
        if (!items) {
            return false;
        }
        stack->items = items;
    }

    stack->size++;
    stack->top++;
    stack->items[stack->top] = item;
    return true;
}

void *StackPop(Stack *stack) {
    if (stack->top == -1 || stack->size == 0) {
        return nullptr;
    }

    void *item = malloc(sizeof(StackItem));

    if (!item) {
        return nullptr;
    }

    memcpy(item, &stack->items[stack->top], sizeof(StackItem));

    stack->top--;
    stack->size--;

    if (stack->size == 0 || stack->top == -1) {
        free(stack->items);
        stack->items = nullptr;
    } else {
        StackItem *tempItems = realloc(stack->items, stack->size * sizeof(StackItem));

        if (!tempItems) {
            stack->top++;
            stack->size++;
            return nullptr;
        }

        stack->items = tempItems;
    }

    return item;
}

void* StackPeek(const Stack *stack) {
    if (stack->top == -1 || stack->size == 0) {
        return nullptr;
    }

    return &stack->items[stack->top];
}

bool StackIsEmpty(const Stack *stack) {
    return stack->size == 0;
}

void StackDestroy(Stack *stack) {
    if (stack) {
        if (stack->items) {

            for (size_t i = 0; i < stack->size; i++) {
                if (stack->items[i].itemType == IS_STRING) {
                    free(stack->items[i].stringValue);
                }

                if (stack->items[i].itemType == IS_POINTER) {
                    free(stack->items[i].pointerValue);
                }
            }

            free(stack->items);
            stack->items = nullptr;
        }
        free(stack);
    }
}
