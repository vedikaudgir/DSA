// Programm to sort a given array using bubble sort.
// Author - Vedika Udgir.

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

void main()
{
    int swap, a[10], i, j, n;
    bool flag;

    printf("Enter the number of elements in the array.");
    scanf("%d", &n);

    for (i = 0; i <= n - 1; i++)
    {
        printf("Enter element no. %d - ", i + 1);
        scanf("%d", &a[i]);
        printf("\n");
    }

    printf("Array is -\n");

    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nSorted array is -\n");

    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
                flag = 1;
            }
        }
        if (flag = 0)
        {
            break;
        }
    }

    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", a[i]);
    }
}