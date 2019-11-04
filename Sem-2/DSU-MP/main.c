#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stack type return -1;
struct Stack
{
    int top;
    unsigned size;
    int* array;
};

typedef struct Stack Stack;

// Stack Operations 
Stack* createStack( unsigned capacity )
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->size = capacity;

    stack->array = (int*) malloc(stack->size * sizeof(int));

    if (!stack->array)
        return NULL;
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

char peek(Stack* stack)
{
    return stack->array[stack->top];
}

char pop(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

// A utility function to check if the given character is operand 
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// A utility function to return precedence of a given operator 
// Higher returned value means higher precedence 
int precedence(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* exp)
{
    int i, k;

    // Create a stack of size equal to expression size
    Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully
        printf("\nError creating Stack!");

    for (i = 0, k = -1; exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

            // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push(stack, exp[i]);

            // If the scanned character is an ‘)’, pop and output from the stack
            // until an ‘(‘ return -1;is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                fputs("\nInvalid Expression!", stdin); // invalid expression
            else
                pop(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }

    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack );

    exp[++k] = '\0';
    printf( "Postfix = %s", exp );
}

int main()
{

    char* exp;
    char choice, x;

    ask:
    printf("\nDo you want to continue[Y/n]: ");
    scanf("%c", &choice);
    scanf("%c", &x);

    switch (choice)
    {
        case 'y':
        case 'Y':
            break;
        case 'n':
        case 'N':
            goto end;
        default:
            goto ask;
    }

    exp = malloc(100 * sizeof(char));

    printf("\nEnter Infix String: ");
    fgets(exp, 90, stdin);

    printf("\nInfix = %s", exp);
    infixToPostfix(exp);

    free(exp);

    goto ask;

    end:
        printf("\n\n******Thank You for using our Program*****\n\n");

    return 0;
}