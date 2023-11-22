//print elements in sorted order using row coloum wise sorted matrix
#include <stdio.h>

void printSortedMatrix(int matrix[][3], int rows, int cols) {
    int temp[rows * cols];
    int k = 0;

    // Copy elements of the matrix to a temporary array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[k++] = matrix[i][j];
        }
    }

    // Sort the temporary array
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                // Swap elements if they are in the wrong order
                int tempValue = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempValue;
            }
        }
    }

    // Print the sorted elements
    printf("Sorted elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", temp[i]);
    }
}

int main() {
    int matrix[3][3] = {
        {1, 3, 5},
        {2, 6, 9},
        {4, 8, 10}
    };

    int rows = 3;
    int cols = 3;

    printSortedMatrix(matrix, rows, cols);

    return 0;
}