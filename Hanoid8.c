
#include <stdio.h>
#define MAX 20

struct Stack
{
    int data[MAX];
    int top;
};

void push(struct Stack *s, int value)
{
    s->data[++s->top] = value;
}

int pop(struct Stack *s)
{
    return s->data[s->top--];
}

void moveDisk(struct Stack *from, struct Stack *to, char a, char b)
{
    int disk = pop(from);
    push(to, disk);
    printf("Move disk %d from %c to %c\n", disk, a, b);
}

void hanoi(int n, struct Stack *from, struct Stack *aux,
           struct Stack *to, char a, char b, char c)
{
    if (n == 1)
    {
        moveDisk(from, to, a, c);
        return;
    }

    hanoi(n - 1, from, to, aux, a, c, b);

    moveDisk(from, to, a, c);

    hanoi(n - 1, aux, from, to, b, a, c);
}

void towerOfHanoi(int n)
{
    struct Stack source, auxiliary, destination;
    int i;

    source.top = -1;
    auxiliary.top = -1;
    destination.top = -1;

    for (i = n; i >= 1; i--)
        push(&source, i);

    hanoi(n, &source, &auxiliary, &destination,
          'A', 'B', 'C');
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of disks");
        return 0;
    }

    towerOfHanoi(n);

    return 0;
}
