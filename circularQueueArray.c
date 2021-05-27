// CIRCULAR QUEUE USING ARRAY
// PROGRAM 4
#include <stdio.h>
#include <conio.h>

int enqueue_arr[50];
int front = -1;
int rear = -1;

void insert(int n);
void del(int n);
void display(int n);

int main()
{
    int choice, n;
    // clrscr();
    printf("Enter the size of the queue\n");
    scanf("%d", &n);
    while (choice != 4)
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(n);
            break;

        case 2:
            del(n);
            break;

        case 3:
            display(n);
            break;

        case 4:
            printf("Exiting...");
            break;

        default:
            printf("Wrong choice \n");
        }
    }
    // getch();
    return 0;
}

void insert(int n)
{
    int added_item;
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }

    else

        if (rear == n - 1)
        rear = 0;
    else
        rear = rear + 1;

    printf("Input the elemnet for insertion in queue: ");
    scanf("%d", &added_item);
    enqueue_arr[rear] = added_item;
}

void del(int n)
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", enqueue_arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == n - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

void display(int n)
{
    int i;
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", enqueue_arr[i]);
        }
    }
    if (front > rear)
    {
        for (i = front; i <= n - 1; i++)
        {
            printf("%d\t", enqueue_arr[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d\t", enqueue_arr[i]);
        }
    }
}