#include <stdio.h>
#define MAX 100

int main()
{
    int queue[MAX];
    int *ptr = queue;
    int front = 0, rear = -1;
    int size, choice, value, i;

    printf("Enter queue size: ");
    scanf("%d", &size);

    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Exit");

    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rear == size - 1)
                {
                    printf("Queue Overflow");
                }
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &value);

                    rear = rear + 1;
                    *(ptr + rear) = value;

                    printf("Element inserted");
                }
                break;

            case 2:
                if (front > rear)
                {
                    printf("Queue Underflow");
                }
                else
                {
                    printf("Deleted element: %d", *(ptr + front));
                    front = front + 1;
                }
                break;

            case 3:
                if (front > rear)
                {
                    printf("Queue is empty");
                }
                else
                {
                    printf("Queue elements: ");

                    for (i = front; i <= rear; i++)
                    {
                        printf("%d ", *(ptr + i));
                    }
                }
                break;

            case 4:
                printf("Exit");
                break;

            default:
                printf("Invalid choice");
        }

    } while (choice != 4);

    return 0;
}
