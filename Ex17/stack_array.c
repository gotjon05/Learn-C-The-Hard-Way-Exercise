#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_DATA 100

struct Stack {
    int nodes[MAX_DATA];
    int size;
};

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    
    exit(1);
}

struct Stack *new()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    
    stack->size = 0;
    
    return stack;
}

void push(struct Stack *stack, int value)
{
    if (stack->size < MAX_DATA) {
        stack->nodes[stack->size++] = value;
    } else {
        die("Stack is full!");
    }
}

int pop(struct Stack *stack) 
{
    if (stack->size > 0) {
        return stack->nodes[--stack->size];
    } else {
        die("Stack is empty!");
    }
    
    return 0;
}

void free_stack(struct Stack *stack)
{
    if (stack) {
        free(stack);
    }
}

int main(int argc, char *argv[])
{
    struct Stack *stack = new();
    
    int i = 0;
    
    for (i = 0; i < 10; i++) {
        push(stack, i);
    }
    
    for (i = 0; i < 10; i++) {
        printf("%d\n", pop(stack));
    }
    
    free_stack(stack);
    
    return 0;
}