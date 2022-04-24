#include <stdio.h>

void bubble_sort( int* ptr, int n)
{
    int i, j, t;
  
    for (i = 0; i < n; i++) {
  
        for (j = i + 1; j < n; j++) {
  
            if (*(ptr + j) < *(ptr + i)) {
  
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}

void main()
{
    int n, m;
    printf("Enter the numnber of elements in the first array : ");
    scanf("%d", &n);
    int array1[n];
    printf("Enter the elements of the first array (Max. 10 elements) : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array1[i]);
    }

    printf("\n");

    printf("Enter the numnber of elements in the second array : ");
    scanf("%d", &m);
    int array2[m];
    printf("Enter the elements of the second array (Max. 10 elements) : \n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &array2[i]);
    }

    int combined_array[n + m];

    bubble_sort(array1, n);
    bubble_sort(array2, m);

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            combined_array[i] = array1[i];
        }
        else
        {
            combined_array[i] = array2[i - n];
        }
    }

    bubble_sort(combined_array, n + m);

    printf("\n");
    printf("The required sorted array : \n");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", combined_array[i]);
    }
}