
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop()
{
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;

    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];

        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = pop();

            pop();
        }
        else
        {
            while (top >= 0 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    while (top >= 0)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);

    getch();
    return 0;
}
