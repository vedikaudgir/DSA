// A program to sort array by selection sort.
// Author - Vedika Udgir

#include <stdio.h>

void main()
{
    int i, j, n, min, swap;

    printf("Enter number of elements in array.");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter element element no. %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap = a[i];
            a[i] = a[min];
            a[min] = swap;
        }
    }

    printf("\nSorted array is - \n");
    for (i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}