
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int deque_arr[50];
int left = -1;
int right = -1;
void input_que();
void output_que();
void insert_right(int n);
void insert_left(int n);
void delete_left(int n);
void delete_right(int n);
void display_queue(int n);
void main()
{
    int choice, n;
    printf("enter size of queue");
    scanf("%d", &n);
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
    printf("Enter your choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        input_que(n);
        break;
    case 2:
        output_que(n);
        break;
    default:
        printf("Wrong choice\n");
    }
    getch();
}

void input_que(int n)

{
    int choice;
    while (1)
    {
        printf("1.Insert at right\n");
        printf("2.Delete from left\n");
        printf("3.Delete from right\n");
        printf("4.Display\n");
        printf("5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right(n);
            break;

        case 2:
            delete_left(n);
            break;
        case 3:
            delete_right(n);
            break;

        case 4:
            display_queue(n);
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong choice\n");
        }
    }
}

void output_que(int n)
{
    int choice;
    while (1)
    {
        printf("1.Insert at right\n");
        printf("2. Insert at left\n");
        printf("3.Delete from left\n");
        printf("4 Display\n");
        printf("5.Quit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right(n);
            break;
        case 2:
            insert_left(n);
            break;
        case 3:
            delete_left(n);
            break;
        case 4:
            display_queue(n);
            break;
        case 5:
            exit(0);

        default:

            printf("Wrong choice\n");
        }
    }
}

void insert_right(int n)
{

    int added_item;
    if ((left == 0 && right == n - 1) || (left == right + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }

    else if (right == n - 1)

        right = 0;

    else
        right = right + 1;
    printf("Input the element for adding in queue :");
    scanf("%d", &added_item);
    deque_arr[right] = added_item;
}

void insert_left(int n)
{

    int added_item;

    if ((left == 0 && right == n - 1) || (left == right + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (left == -1)
    {

        left = 0;
        right = 0;
    }
    else

        if (left == 0)

        left = n - 1;

    else
        left = left - 1;
    printf("Input the element for adding in queue: ");
    scanf("%d", &added_item);
    deque_arr[left] = added_item;
}

void delete_left(int n)
{

    if (left == -1)
    {
        printf("QueueUnderflow\n");
        return;
    }

    printf("Element deleted from queue is: %d\n", deque_arr[left]);
    if (left == right)

    {
        left = -1;
        right = -1;
    }
    else

        if (left == n - 1)
        left = 0;
    else
        left = left + 1;
}

void delete_right(int n)
{

    if (left == -1)
    {
        printf("Queue Underflown");
        return;
    }

    printf("Element deleted from queue is ;%d\n", deque_arr[right]);
    if (left == right)
    {

        left = -1;
        right = -1;
    }
    else

        if (right == 0)

        right = n - 1;
    else

        right = right - 1;
}

void display_queue(int n)
{
    int i;
    if (left <= right)
    {
        for (i = left; i <= right; i++)
        {
            printf("%d\t", deque_arr[i]);
        }
    }
    if (left > right)
    {
        for (i = left; i <= n - 1; i++)
        {
            printf("%d\t", deque_arr[i]);
        }
        for (i = 0; i <= right; i++)
        {
            printf("%d\t", deque_arr[i]);
        }
    }
}
