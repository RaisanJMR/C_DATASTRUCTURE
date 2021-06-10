// INSERTION SORT
// PROGRAM 6
#include <stdio.h>

int main()
{
    int arr[50], i, j, key, n;
    printf("enter the number of elements:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter element %d\n", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("unsorted list is:\n");
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
    // insertion sort
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("Pass%d,Element inserted in proper place:%d\n", i, key);
        for (j = 0; j < n; j++)
            printf("%d", arr[j]);
        printf("\n");
    }
    printf("sorted list is:\n");
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
    return 0;
}
// End of main()