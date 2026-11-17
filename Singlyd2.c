
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head,*temp,*ptr,*preptr,*newnode;

void create()
{
    int i,n;
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    head=NULL;

    for(i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertbegin()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d",&newnode->data);

    newnode->next=head;
    head=newnode;
}

void insertend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;

    if(head==NULL)
    {
        head=newnode;
        return;
    }

    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newnode;
}

void insertbefore()
{
    int key;
    printf("Enter the key element: ");
    scanf("%d",&key);

    temp=head;

    if(temp==NULL)
        return;

    if(temp->data==key)
    {
        insertbegin();
        return;
    }

    while(temp->next!=NULL && temp->next->data!=key)
        temp=temp->next;

    if(temp->next==NULL)
    {
        printf("Key not found");
        return;
    }

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d",&newnode->data);

    newnode->next=temp->next;
    temp->next=newnode;
}

void insertafter()
{
    int key;
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

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to insert: ");
    scanf("%d",&newnode->data);

    newnode->next=temp->next;
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
    free(temp);
}

void deleteend()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }

    ptr=head;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }

    free(ptr);
    preptr->next=NULL;
}

void deletebefore()
{
    int key;
    printf("Enter key element: ");
    scanf("%d",&key);

    if(head==NULL || head->data==key)
    {
        printf("Deletion not possible");
        return;
    }

    if(head->next->data==key)
    {
        deletebegin();
        return;
    }

    preptr=head;
    ptr=head->next;

    while(ptr->next!=NULL && ptr->next->data!=key)
    {
        preptr=ptr;
        ptr=ptr->next;
    }

    if(ptr->next==NULL)
    {
        printf("Key not found");
        return;
    }

    preptr->next=ptr->next;
    free(ptr);
}

void deleteafter()
{
    int key;
    printf("Enter key element: ");
    scanf("%d",&key);

    temp=head;
    while(temp!=NULL && temp->data!=key)
        temp=temp->next;

    if(temp==NULL || temp->next==NULL)
    {
        printf("Deletion not possible");
        return;
    }

    ptr=temp->next;
    temp->next=ptr->next;
    free(ptr);
}

void search()
{
    int key,flag=0;
    printf("Enter element to search: ");
    scanf("%d",&key);

    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }

    if(flag==1)
        printf("Element found");
    else
        printf("Element not found");
}

void main()
{
    int choice;
    clrscr();

    do
    {
        printf("\n\n1. Create");
        printf("\n2. Insert Beginning");
        printf("\n3. Insert End");
        printf("\n4. Insert Before");
        printf("\n5. Insert After");
        printf("\n6. Delete Beginning");
        printf("\n7. Delete End");
        printf("\n8. Delete Before");
        printf("\n9. Delete After");
        printf("\n10. Display");
        printf("\n11. Search");
        printf("\n12. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                insertbegin();
                break;

            case 3:
                insertend();
                break;

            case 4:
                insertbefore();
                break;

            case 5:
                insertafter();
                break;

            case 6:
                deletebegin();
                break;

            case 7:
                deleteend();
                break;

            case 8:
                deletebefore();
                break;

            case 9:
                deleteafter();
                break;

            case 10:
                display();
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

    }while(choice!=12);

    getch();
}
