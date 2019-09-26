#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int top;
    size_t size;
    int *a;
};

typedef struct Stack Stack;

void initialize_stack(Stack *stack, size_t size);
bool isEmpty(Stack* stack);
bool isFull(Stack* stack);
int push(Stack* stack, int n);
int pop(Stack* stack);

int main()
{

    Stack s1;
    initialize_stack(&s1, 3);

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    pop(&s1);
    pop(&s1);
    pop(&s1);

    return 0;
}

void initialize_stack(Stack* stack, size_t size)
{
    stack->size = size;
    stack->a = malloc(size * sizeof(int));
    stack->top = -1;

    printf("\nStack Initialized with top=%d and size=%d", stack->top, (int)stack->size);
}

bool isEmpty(Stack* stack)
{
    return (stack->top == -1);
}

bool isFull(Stack* stack)
{
    return (stack->top == stack->size -1);
}

int push(Stack* stack, int n)
{
    if (isFull(stack))
    {
        printf("\n\nFAILED!! STACK OVERFLOW ERROR");
        exit(-1);
    }

    ++(stack->top);
    stack->a[stack->top] = n;

    printf("\nPushed: %d, Top=%d", n, stack->top);
    return 1;
}

int pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("\n\nFAILED!! STACK UNDERFLOW ERROR");
        exit(-1);
    }

    printf("\nPopped %d,", stack->a[stack->top]);

    *((stack->a) + stack->top) = 0;
    --(stack->top);

    printf(" Top=%d", stack->top);
    return 1;
}

