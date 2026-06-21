//
// Created by felipe on 16/06/2026.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.h"

int StackCreateTestSuccessfully() {
  Stack *stack = StackCreate();
  StackDestroy(stack);
  return 0;
}

int stacKPushTestSuccessfully() {
  Stack *stack = StackCreate();

  StackItem item1;
  item1.intValue = 123;
  item1.itemType = IS_INT;

  assert(StackPush(stack, item1) == true);
  assert(stack->size == 1);
  assert(stack->top == 0);
  assert(stack->items[0].itemType == IS_INT);
  StackDestroy(stack);
  return 0;
}

int stacKPopTestSuccessfully() {
  Stack *stack = StackCreate();

  StackItem item1;
  item1.intValue = 123;
  item1.itemType = IS_INT;

  StackPush(stack, item1);

  const StackItem *poppedItem = StackPop(stack);

  assert(poppedItem->intValue == 123);
  assert(poppedItem->itemType == IS_INT);
  assert(stack->size == 0);
  assert(stack->top == -1);

  StackDestroy(stack);

  return 0;
}

int stackPeekTestSuccessfully() {
  Stack *stack = StackCreate();

  StackItem item1;
  item1.intValue = 123;
  item1.itemType = IS_INT;

  StackPush(stack, item1);

  const StackItem *peekedItem = StackPeek(stack);

  assert(peekedItem->intValue == 123);
  assert(peekedItem->itemType == IS_INT);
  assert(stack->size == 1);
  assert(stack->top == 0);

  StackDestroy(stack);
  return 0;
}

int StackIterationTestSuccessfully() {

  Stack *stack = StackCreate();

  StackItem item1;
  StackItem item2;
  StackItem item3;
  StackItem item4;

  item1.intValue = 123;
  item1.itemType = IS_INT;

  item2.itemType = IS_BOOL;
  item2.boolValue = false;

  item3.itemType = IS_STRING;
  item3.stringValue = strdup("testing my stack");

  item4.itemType = IS_FLOAT;
  item4.floatValue = 22.40;

  StackPush(stack, item1);
  StackPush(stack, item2);

  StackPush(stack, item3);
  StackPush(stack, item4);

  while (!StackIsEmpty(stack)) {
    const StackItem *item = StackPop(stack);
    if (item->itemType == IS_STRING) {
      printf("What I am doing? %s\n", item->stringValue);
    }
  }

  assert(stack->size == 0);

  StackDestroy(stack);

  return 0;
}

int main(int argc, char *argv[]) {

  printf("Initializing Stack Testing....\n");

  StackCreateTestSuccessfully();

  stacKPushTestSuccessfully();

  stacKPopTestSuccessfully();

  stackPeekTestSuccessfully();

  StackIterationTestSuccessfully();

  printf("Stack Testing finalized....\n");

  return 0;
}
