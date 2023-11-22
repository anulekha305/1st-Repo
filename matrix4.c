//common elements in all rows of a given matrix
#include <stdio.h>

void findCommonElements(int matrix[][5], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        int currentElement = matrix[0][i];
        int common = 1;  // Assume the element is common in all rows

        // Check the current element in all other rows
        for (int j = 1; j < rows; j++) {
            int found = 0;

            // Check if the element is present in the current row
            for (int k = 0; k < cols; k++) {
                if (matrix[j][k] == currentElement) {
                    found = 1;
                    break;
                }
            }

            // If the element is not present in the current row, it's not common
            if (!found) {
                common = 0;
                break;
            }
        }

        // If common is still 1, the element is present in all rows
        if (common) {
            printf("%d is a common element in all rows.\n", currentElement);
        }
    }
}

int main() {
    int matrix[3][5] = {{1, 2, 3, 4, 5},
                        {2, 4, 6, 8, 10},
                        {3, 6, 9, 12, 15}};

    int rows = 3;
    int cols = 5;

    findCommonElements(matrix, rows, cols);

    return 0;
}