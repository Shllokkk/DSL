#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Structure to represent a stack of integers
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // Return -1 if the stack is empty
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // Default case
}

// Function to evaluate an expression
int evaluateExpression(char* expression) {
    struct Stack* valueStack = createStack(strlen(expression));
    struct Stack* operatorStack = createStack(strlen(expression));
    int i;

    for (i = 0; expression[i]; i++) {
        // Handle digits
        if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            push(valueStack, num);
            i--; // Move back one character to account for the loop increment
        } 
        // Handle operators and parentheses
        else if (expression[i] == '(') {
            push(operatorStack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(operatorStack) && operatorStack->array[operatorStack->top] != '(') {
                int operand2 = pop(valueStack);
                int operand1 = pop(valueStack);
                char op = pop(operatorStack);
                switch (op) {
                    case '+':
                        push(valueStack, operand1 + operand2);
                        break;
                    case '-':
                        push(valueStack, operand1 - operand2);
                        break;
                    case '*':
                        push(valueStack, operand1 * operand2);
                        break;
                    case '/':
                        push(valueStack, operand1 / operand2);
                        break;
                }
            }
            // Pop the opening parenthesis '('
            pop(operatorStack);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!isEmpty(operatorStack) && precedence(expression[i]) <= precedence(operatorStack->array[operatorStack->top])) {
                int operand2 = pop(valueStack);
                int operand1 = pop(valueStack);
                char op = pop(operatorStack);
                switch (op) {
                    case '+':
                        push(valueStack, operand1 + operand2);
                        break;
                    case '-':
                        push(valueStack, operand1 - operand2);
                        break;
                    case '*':
                        push(valueStack, operand1 * operand2);
                        break;
                    case '/':
                        push(valueStack, operand1 / operand2);
                        break;
                }
            }
            push(operatorStack, expression[i]);
        }
    }

    // Evaluate any remaining operators in the stack
    while (!isEmpty(operatorStack)) {
        int operand2 = pop(valueStack);
        int operand1 = pop(valueStack);
        char op = pop(operatorStack);
        switch (op) {
            case '+':
                push(valueStack, operand1 + operand2);
                break;
            case '-':
                push(valueStack, operand1 - operand2);
                break;
            case '*':
                push(valueStack, operand1 * operand2);
                break;
            case '/':
                push(valueStack, operand1 / operand2);
                break;
        }
    }

    // The final result will be on the top of the value stack
    int result = valueStack->array[valueStack->top];

    // Free allocated memory
    free(valueStack->array);
    free(valueStack);
    free(operatorStack->array);
    free(operatorStack);

    return result;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
