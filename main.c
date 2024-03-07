#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    int swapCount = 0;

    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
                swapCount++;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }

    // Print swap counts for each element
    for (i = 0; i < n; i++) {
        printf("%d: Swapped: %d times\n", arr[i], i + 1);
    }

    printf("Total # of swaps: %d\n", swapCount);
}

// Selection Sort function
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    int swapCount = 0;

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
            swapCount++;
        }
    } 

    // Print swap counts for each element
    for (i = 0; i < n; i++) {
        printf("%d: Swapped: %d times\n", arr[i], i + 1);
    }

    printf("Total # of swaps: %d\n", swapCount);
} 

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("array1:\n");
    printArray(arr1, n1);

    printf("Bubble Sort:\n");
    bubbleSort(arr1, n1);

    printf("\narray2:\n");
    printArray(arr2, n2);

    printf("Selection Sort:\n");
    selectionSort(arr2, n2);

    return 0;
}
