#include <stdio.h>

// you can change this if you want
#define MAX 100

int count_crit_points(double array[MAX][MAX], int n_rows, int n_cols);

// i made these helper functions:
int is_crit_point(
    double array[MAX][MAX],
    int n_rows, int n_cols, int row, int col
);
int in_bounds(int row, int col, int n_rows, int n_cols);

int main(void) {
    double array[MAX][MAX];
    printf("Enter number of rows and columns: ");
    int n_rows, n_cols;
    scanf("%d %d", &n_rows, &n_cols);
    for (int row = 0; row < n_rows; row++) {
        printf("Enter row %d: ", row);
        for (int col = 0; col < n_cols; col++) {
            scanf("%lf", &array[row][col]);
        }
    }
    int count = count_crit_points(array, n_rows, n_cols);
    printf("Found %d critical point(s)\n", count);
}

int count_crit_points(double array[MAX][MAX], int n_rows, int n_cols) {
    int count = 0;
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            if (is_crit_point(array, n_rows, n_cols, row, col)) {
                count++;
            }
        }
    }
    return count;
}

// determines whether the point at the given row and col
// is a critical point: returns 1 if point is critical and
// 0 otherwise
int is_crit_point(
    double array[MAX][MAX],
    int n_rows, int n_cols, int row, int col
) {
    for (int d_row = -1; d_row <= 1; d_row++) {
        for (int d_col = -1; d_col <= 1; d_col++) {
            int new_row = row + d_row;
            int new_col = col + d_col;
            if (in_bounds(new_row, new_col, n_rows, n_cols) &&
                (new_row != row || new_col != col) &&
                array[new_row][new_col] >= array[row][col]) {
                return 0; // false
            }
        }
    }
    return 1; // true
}

// determines if the given row and col coordinates are
// within the bounds of the array: returns 1 if in bounds
// and 0 otherwise
int in_bounds(int row, int col, int n_rows, int n_cols) {
    return 0 <= row && row < n_rows && 0 <= col && col < n_cols;
}

