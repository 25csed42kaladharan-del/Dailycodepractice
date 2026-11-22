#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *temp,*top=NULL,*newnode;

void push()
{
    printf("Enter the element to insert:");
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);

    newnode->next=top;
    top=newnode;
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp=top;
        printf("Deleted element is %d",top->data);
        top=top->next;
        free(temp);
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("The element at top is %d",top->data);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        temp=top;
        printf("Stack elements are:");

        while(temp!=NULL)
        {
            printf(" %d",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
    int n;

    do
    {
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");

        printf("\nEnter your choice:");
        scanf("%d",&n);

        switch(n)
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
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    }while(n!=5);

    getch();
}
