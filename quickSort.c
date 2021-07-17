#include <stdio.h>
#include <conio.h>
void display(int, int);
void quicksort(int, int);
int partition(int, int);
int a[45];
int main()
{
    int n, i;
    // clrscr();
    printf("enter the limit:\n");
    scanf("%d", &n);
    printf("enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("unsorted list:\n");
    display(0, n - 1);
    quicksort(0, n - 1);
    printf("\n");
    printf("sorted list:\n");
    display(0, n - 1);
    getch();

    return 0;
}
void quicksort(int first, int last)
{
    int p;
    if (first < last)
    {
        p = partition(first, last);
        quicksort(first, p - 1);
        quicksort(p + 1, last);
    }
}
int partition(int first, int last)
{
    int loc, left, right, temp;
    left = first;
    right = last;
    loc = left;
    while (left < right)
    {
        while ((a[loc] <= a[right]) && (loc > left))
        {
            right = right - 1;
        }
        if (a[loc] > a[right])
        {
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
            left = left + 1;
        }
        while ((a[loc] >= a[left]) && (loc > left))
        {
            left = left + 1;
        }
        if (a[loc] < a[right])
        {
            temp = a[loc];
            a[loc] = a[right];
            a[left] = temp;
            right = right - 1;
        }
    }
    return loc;
}
void display(int low, int up)
{
    int i;
    for (i = low; i <= up; i++)
    {
        printf("%d", a[i]);
    }
}