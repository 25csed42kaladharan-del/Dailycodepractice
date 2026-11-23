
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int top = -1;
int s[MAXSIZE];

void push()
{
    int d;

    if (top == MAXSIZE - 1)
    {
        printf("\nStack is full\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &d);

        top++;
        s[top] = d;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nThe element to be deleted is %d\n", s[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nThe element at top is %d\n", s[top]);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nElements: ");

        for (i = top; i >= 0; i--)
        {
            printf("%d ", s[i]);
        }

        printf("\n");
    }
}

int main()
{
    int n;

    do
    {
        printf("\n\nSTACK OPERATIONS");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (n != 5);

    return 0;
}
