// Programm to sort an array through insertion sort.
// Author - Vedika Udgir.

#include <stdio.h>

void main()
{
    int n,i,j,temp;

    printf("Enter the number of elements in the array.");
    scanf("%d",&n);

    int a[n-1];

    for(i = 0; i <= n-1; i++)
    {
        printf("\n Enter the element no. %d - ",i+1);
        scanf("%d",&a[i]);
    }

    printf("\n\nThe array is - ");

    for(i = 0; i <= n-1; i++)
    {
        printf("%d ",a[i]);
    }
    
    for (i = 1; i <= n-1; i++)
    {
        temp = a[i];

        for (j = i-1; (j >= 0 && a[j] > temp); j--)
        {
            a[j+1] = a[j];
        }
        
        a[j+1] = temp;
    }

    printf("\n\nThe sorted array is - ");

    for(i = 0; i <= n-1; i++)
    {
        printf("%d ",a[i]);
    }   
    
}