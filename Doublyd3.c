
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head=NULL,*temp,*newnode,*ptr,*ptr1;

void create()
{
    int n,i;
    printf("Enter no of nodes: ");
    scanf("%d",&n);

    printf("Enter the elements: ");

    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);

        newnode->prev=NULL;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
}

void display()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    temp=head;
    printf("Elements are: ");

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertbegin()
{
    newnode=(struct node *)malloc(sizeof(struct node));

    printf("Enter element to insert: ");
    scanf("%d",&newnode->data);

    newnode->prev=NULL;
    newnode->next=head;

    if(head!=NULL)
        head->prev=newnode;

    head=newnode;
}

void insertend()
{
    newnode=(struct node *)malloc(sizeof(struct node));

    printf("Enter element to insert: ");
    scanf("%d",&newnode->data);

    newnode->next=NULL;

    if(head==NULL)
    {
        newnode->prev=NULL;
        head=newnode;
        return;
    }

    temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
    newnode->prev=temp;
}

void insertbefore()
{
    int key;

    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Enter the key element: ");
    scanf("%d",&key);

    temp=head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Key not found");
        return;
    }

    newnode=(struct node *)malloc(sizeof(struct node));

    printf("Enter element to insert: ");
    scanf("%d",&newnode->data);

    if(temp==head)
    {
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
    else
    {
        ptr=temp->prev;
        newnode->next=temp;
        newnode->prev=ptr;
        ptr->next=newnode;
        temp->prev=newnode;
    }
}

void insertafter()
{
    int key;

    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Enter the key element: ");
    scanf("%d",&key);

    temp=head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Key not found");
        return;
    }

    newnode=(struct node *)malloc(sizeof(struct node));

    printf("Enter element to insert: ");
    scanf("%d",&newnode->data);

    newnode->prev=temp;
    newnode->next=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=newnode;

    temp->next=newnode;
}

void deletebegin()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    free(temp);
}

void deleteend()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    if(temp==head)
        head=NULL;
    else
    {
        ptr=temp->prev;
        ptr->next=NULL;
    }

    free(temp);
}

void deletebefore()
{
    int key;

    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Enter the key element: ");
    scanf("%d",&key);

    temp=head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Key not found");
        return;
    }

    if(temp==head)
    {
        printf("No element before the key");
        return;
    }

    ptr=temp->prev;

    if(ptr==head)
        head=temp;
    else
    {
        ptr1=ptr->prev;
        ptr1->next=temp;
        temp->prev=ptr1;
    }

    if(ptr==head)
        temp->prev=NULL;

    free(ptr);
}

void deleteafter()
{
    int key;

    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Enter the key element: ");
    scanf("%d",&key);

    temp=head;

    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        printf("Key not found");
        return;
    }

    if(temp->next==NULL)
    {
        printf("No element after the key");
        return;
    }

    ptr=temp->next;
    temp->next=ptr->next;

    if(ptr->next!=NULL)
        ptr->next->prev=temp;

    free(ptr);
}

void search()
{
    int num,count=0;

    printf("Enter the element to search: ");
    scanf("%d",&num);

    temp=head;

    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            count=1;
            break;
        }

        temp=temp->next;
    }

    if(count==1)
        printf("Element found");
    else
        printf("Element not found");
}

void main()
{
    int ch;

    clrscr();

    do
    {
        printf("\n\n1.Create");
        printf("\n2.Display");
        printf("\n3.Insert at beginning");
        printf("\n4.Insert at end");
        printf("\n5.Insert before the given element");
        printf("\n6.Insert after the given element");
        printf("\n7.Delete at beginning");
        printf("\n8.Delete at end");
        printf("\n9.Delete before the given element");
        printf("\n10.Delete after the given element");
        printf("\n11.Search");
        printf("\n12.Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insertbegin();
                break;

            case 4:
                insertend();
                break;

            case 5:
                insertbefore();
                break;

            case 6:
                insertafter();
                break;

            case 7:
                deletebegin();
                break;

            case 8:
                deleteend();
                break;

            case 9:
                deletebefore();
                break;

            case 10:
                deleteafter();
                break;

            case 11:
                search();
                break;

            case 12:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    }while(ch!=12);

    getch();
}
