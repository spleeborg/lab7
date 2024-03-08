#include <stdbool.h>
#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int array[], int size) {
    int swapCount = 0;
    int swappedCountArray[size][2]; // Adjust the size dynamically based on the input array

    // Initialize the swappedCountArray
    for (int i = 0; i < size; i++) {
        swappedCountArray[i][0] = array[i];
        swappedCountArray[i][1] = 0;
    }

    // Sorting process for the main array and count swaps
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapCount++;

                // Update the swap count for involved elements
                for (int k = 0; k < size; k++) {
                    if (array[j] == swappedCountArray[k][0] || array[j + 1] == swappedCountArray[k][0]) {
                        swappedCountArray[k][1]++;
                    }
                }
            }
        }
    }

    // Sorting swappedCountArray based on the elements
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (swappedCountArray[j][0] > swappedCountArray[j + 1][0]) {
                swap(&swappedCountArray[j][0], &swappedCountArray[j + 1][0]);
                swap(&swappedCountArray[j][1], &swappedCountArray[j + 1][1]);
            }
        }
    }

    // Printing the result
    for (int i = 0; i < size; i++) {
        printf("%d Number of swaps: %d\n", swappedCountArray[i][0], swappedCountArray[i][1]);
    }
    printf("Total Swaps: %d\n", swapCount);
}

void selectionSort(int arr[], int n) {
    int swaps = 0;
    int swapCount[n]; // Array to count swaps for each element

    // Initialize swap count array
    for (int i = 0; i < n; i++) {
        swapCount[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            swap(&arr[minIdx], &arr[i]);
            swaps++;
            swapCount[minIdx]++; // Increment swap count for minIdx element
            swapCount[i]++; // Increment swap count for i element
        }
    }

    // Printing the array elements and their swap counts
    for (int i = 0; i < n; i++) {
        printf("%d Number of Swaps: %d\n", arr[i], swapCount[i]);
    }
    printf("Total Swaps: %d\n", swaps); // Total number of swaps
}

void resetArray(int arr[], int original[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }
}

int main() {
    int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int original_arr1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int original_arr2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };

    printf("array1 bubble sort:\n");
    bubbleSort(arr1, n1);
    printf("\n");

    printf("array2 bubble sort:\n");
    bubbleSort(arr2, n2);
    printf("\n");

    printf("array1 selection sort:\n");
    resetArray(arr1, original_arr1, n1);
    selectionSort(arr1, n1);
    printf("\n");

    printf("array2 selection sort:\n");
    resetArray(arr2, original_arr2, n2);
    selectionSort(arr2, n2);
    printf("\n");

    return 0;
}
