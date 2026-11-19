
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node *temp,*newnode;

struct node *create(struct node *poly)
{
    int i,n;

    printf("Enter the no of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));

        printf("Enter the coefficient: ");
        scanf("%d",&newnode->coeff);

        printf("Enter the exponent: ");
        scanf("%d",&newnode->exp);

        newnode->next=NULL;

        if(poly==NULL)
        {
            poly=newnode;
            temp=poly;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return poly;
}

void display(struct node *poly)
{
    temp=poly;

    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->exp);

        if(temp->next!=NULL)
            printf(" + ");

        temp=temp->next;
    }
    printf("\n");
}

struct node *sub(struct node *poly1,struct node *poly2)
{
    struct node *p=poly1,*q=poly2;
    struct node *poly3=NULL,*last=NULL;

    while(p!=NULL && q!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;

        if(p->exp==q->exp)
        {
            newnode->coeff=p->coeff-q->coeff;
            newnode->exp=p->exp;
            p=p->next;
            q=q->next;
        }
        else if(p->exp>q->exp)
        {
            newnode->coeff=p->coeff;
            newnode->exp=p->exp;
            p=p->next;
        }
        else
        {
            newnode->coeff=-q->coeff;
            newnode->exp=q->exp;
            q=q->next;
        }

        if(poly3==NULL)
        {
            poly3=newnode;
            last=newnode;
        }
        else
        {
            last->next=newnode;
            last=newnode;
        }
    }

    while(p!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->coeff=p->coeff;
        newnode->exp=p->exp;
        newnode->next=NULL;

        if(poly3==NULL)
            poly3=newnode;
        else
            last->next=newnode;

        last=newnode;
        p=p->next;
    }

    while(q!=NULL)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->coeff=-q->coeff;
        newnode->exp=q->exp;
        newnode->next=NULL;

        if(poly3==NULL)
            poly3=newnode;
        else
            last->next=newnode;

        last=newnode;
        q=q->next;
    }

    return poly3;
}

int main()
{
    int n;
    struct node *poly1=NULL,*poly2=NULL,*poly3=NULL;

    clrscr();

    do
    {
        printf("\n1.Create");
        printf("\n2.Display");
        printf("\n3.Subtract");
        printf("\n4.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
                printf("\nPolynomial 1\n");
                poly1=create(poly1);

                printf("\nPolynomial 2\n");
                poly2=create(poly2);
                break;

            case 2:
                printf("\nPolynomial 1: ");
                display(poly1);

                printf("Polynomial 2: ");
                display(poly2);
                break;

            case 3:
                poly3=sub(poly1,poly2);

                printf("\nResultant Polynomial: ");
                display(poly3);
                break;

            case 4:
                printf("\nExit");
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(n!=4);

    getch();
    return 0;
}
