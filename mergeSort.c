// MERGE SORT
// PROGRAM 7
#include <stdio.h>
int array[20];
void merge_sort(int, int);
void merge(int, int, int);
int main()
{
    int i, n;
    printf("Enter the number of elements :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Element at position %d :", i + 1);
        scanf("%d", &array[i]);
    }
    printf("-------------UNSORTED LIST-------------\n");
    for (i = 0; i < n; i++)
        printf("%d\t", array[i]);
    merge_sort(0, n - 1);
    printf("\n-------------SORTED LIST---------------\n");
    for (i = 0; i < n; i++)
        printf("%d\t", array[i]);
    printf("\n");
    return 0;
} /*end of main()*/
void merge_sort(int l, int r)
{
    int mid;
    if (l != r)
    {
        mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
} /*end of merge_sort*/
void merge(int l, int mid, int r)
{
    int temp[20];
    int i = l;
    int j = mid + 1;
    int k = l, m;
    while ((i <= mid) && (j <= r))
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i = i + 1;
            k = k + 1;
        }
        else
        {
            temp[k] = array[j];
            j = j + 1;
            k = k + 1;
        }
    } /*end of while*/
    if ((i > mid) && (j <= r))
    {
        for (m = j; m <= r; m++)
        {
            temp[k] = array[m];
            k++;
        }
    }
    if ((i <= mid) && (j > r))
    {
        for (m = i; m <= mid; m++)
        {
            temp[k] = array[m];
            k++;
        }
    }
    for (i = l; i <= r; i++)
        array[i] = temp[i];
} /*end of merge()*/