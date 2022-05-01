#include <stdio.h>
#include <stdlib.h>

int control[100];
#define MAX_Value 2147483647

// function to swap elements
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int array[], int low, int high)
{

	// select the rightmost element as pivot
	int pivot = array[high];

	// pointer for greater element
	int i = (low - 1);

	// traverse each element of the array
	// compare them with the pivot
	for (int j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{

			// if element smaller than pivot is found
			// swap it with the greater element pointed by i
			i++;

			// swap element at i with element at j
			swap(&array[i], &array[j]);
		}
	}

	// swap the pivot element with the greater element at i
	swap(&array[i + 1], &array[high]);

	// return the partition point
	return (i + 1);
}

void quickSort(int array[], int low, int high)
{
	if (low < high)
	{

		// find the pivot element such that
		// elements smaller than pivot are on left of pivot
		// elements greater than pivot are on right of pivot
		int pi = partition(array, low, high);

		// recursive call on the left of pivot
		quickSort(array, low, pi - 1);

		// recursive call on the right of pivot
		quickSort(array, pi + 1, high);
	}
}

void InsertionSort(int arr[], int n)
{
	int temp, i, j;

	for (int i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && (arr[j] > temp))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
int minimum(int arr[], int start, int end)
{
	int min = arr[start], index = 0, count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
			count++;
		}
	}
	if (count != 0)
		return index;
	else
		return -1;
}

void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(&arr[i], &arr[min]);
		}
	}
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void print(int arr[], int n)
{
	printf("Sorted Array : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void reset(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = control[i];
	}
}
void main()
{
	int n;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the array : ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		// printf("%d\n",i);
		control[i] = arr[i];
	}
	int choice, response = 1;
	do
	{
		printf("\n\n\tM E N U\n\n");
		printf("1. Insertion Sort\n2. Selection Sort\n3. Heap Sort\n4. Merge Sort\n5. Quick Sort\n6. Exit\n\n");
	ch:
		printf("\t  -> ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			reset(arr, n);
			InsertionSort(arr, n);
			print(arr, n);
			break;

		case 2:
			reset(arr, n);
			SelectionSort(arr, n);
			print(arr, n);
			break;

		case 3:
			reset(arr, n);
			heapSort(arr, n);
			print(arr, n);
			break;

		case 4:
			reset(arr,n);
			mergeSort(arr,0,n-1);
			print(arr, n);
			break;

		case 5:
			reset(arr, n);
			quickSort(arr, 0, n - 1);
			print(arr, n);
			break;

		case 6:
			exit(0);
			break;

		default:
			printf("Enter a valid choice!!!\n\n");
			goto ch;
		}
	} while (response == 1);
}
