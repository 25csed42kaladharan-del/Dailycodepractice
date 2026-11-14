
#include<stdio.h>
#include<conio.h>

int a[100],n=0,i,pos,item;

void create();
void insert_beginning();
void insert_end();
void insert_middle();
void delete_beginning();
void delete_end();
void delete_middle();
void search();
void display();

void main()
{
    int choice;
    clrscr();

    do
    {
        printf("\n\nLIST ADT USING ARRAY");
        printf("\n1.Create");
        printf("\n2.Insert at Beginning");
        printf("\n3.Insert at End");
        printf("\n4.Insert at Middle");
        printf("\n5.Delete at Beginning");
        printf("\n6.Delete at End");
        printf("\n7.Delete at Middle");
        printf("\n8.Search");
        printf("\n9.Display");
        printf("\n10.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insert_beginning();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                insert_middle();
                break;

            case 5:
                delete_beginning();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                delete_middle();
                break;

            case 8:
                search();
                break;

            case 9:
                display();
                break;

            case 10:
                printf("Exit");
                break;

            default:
                printf("Invalid Choice");
        }

    }while(choice!=10);

    getch();
}

void create()
{
    printf("\nEnter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void insert_beginning()
{
    printf("\nEnter element: ");
    scanf("%d",&item);

    for(i=n;i>0;i--)
        a[i]=a[i-1];

    a[0]=item;
    n++;
    printf("Element inserted successfully");
}

void insert_end()
{
    printf("\nEnter element: ");
    scanf("%d",&item);

    a[n]=item;
    n++;
    printf("Element inserted successfully");
}

void insert_middle()
{
    printf("\nEnter position: ");
    scanf("%d",&pos);

    if(pos<1 || pos>n+1)
    {
        printf("Invalid Position");
        return;
    }

    printf("Enter element: ");
    scanf("%d",&item);

    for(i=n;i>=pos;i--)
        a[i]=a[i-1];

    a[pos-1]=item;
    n++;
    printf("Element inserted successfully");
}

void delete_beginning()
{
    if(n==0)
    {
        printf("Array is Empty");
        return;
    }

    for(i=0;i<n-1;i++)
        a[i]=a[i+1];

    n--;
    printf("Element deleted successfully");
}

void delete_end()
{
    if(n==0)
    {
        printf("Array is Empty");
        return;
    }

    n--;
    printf("Element deleted successfully");
}

void delete_middle()
{
    if(n==0)
    {
        printf("Array is Empty");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d",&pos);

    if(pos<1 || pos>n)
    {
        printf("Invalid Position");
        return;
    }

    for(i=pos-1;i<n-1;i++)
        a[i]=a[i+1];

    n--;
    printf("Element deleted successfully");
}

void search()
{
    int flag=0;

    printf("\nEnter element to search: ");
    scanf("%d",&item);

    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            printf("Element found at position %d",i+1);
            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("Element not found");
}

void display()
{
    if(n==0)
    {
        printf("Array is Empty");
        return;
    }

    printf("\nArray Elements:\n");

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
