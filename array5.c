//merge 2 sorted array without using extra space
#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2) {
    int i, j, k;

    // Iterate through all elements of arr2 starting from the last element
    for (i = size2 - 1; i >= 0; i--) {
        // Find the smallest element greater than arr2[i] in arr1
        int last = arr1[size1 - 1];
        for (j = size1 - 2; j >= 0 && arr1[j] > arr2[i]; j--) {
            arr1[j + 1] = arr1[j];
        }

        // If there was a smaller element in arr1, move it to arr2[i+1] and update last
        if (j != size1 - 2 || last > arr2[i]) {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

int main() {
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 3, 8, 13};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeArrays(arr1, size1, arr2, size2);

    // Print the merged array
    printf("Merged array: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    for (int i = 0; i < size2; i++) {
        printf("%d ", arr2[i]);
    }

    return 0;
}