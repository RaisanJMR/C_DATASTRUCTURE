// STACK USING LINKED LIST
// PROGRAM 2
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
} *top = NULL;
void push();
void pop();
void display();
// main()
int main()
{
    int choice;
    while (choice != 4)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting....");
            break;
        default:
            printf("wrong choice\n");
        } //end of switch
    }     //end of while

    return 0;
} //end of main()

void push()
{
    struct node *tmp;
    int pushed_item;
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Input the new value to be pushed to stack:\n");
    scanf("%d", &pushed_item);
    tmp->info = pushed_item;
    tmp->link = top;
    top = tmp;

} //end of push()

void pop()
{
    struct node *tmp;
    if (top == NULL)
        printf("stack is empty\n");
    else
    {
        tmp = top;
        printf("popped item is %d\n", tmp->info);
        top = top->link;
        free(tmp);
    }

} //end of pop()

void display()
{
    struct node *ptr;
    ptr = top;
    if (top == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->info);
            ptr = ptr->link;
        }
    }

} //end of display