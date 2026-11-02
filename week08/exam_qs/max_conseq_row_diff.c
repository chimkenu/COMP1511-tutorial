#include <stdio.h>

#define NUM_COLS 5
#define MAX_ROWS 100

int max_consec_row_diff(int num_rows, int array[MAX_ROWS][NUM_COLS]);

int main(void) {
    int test_array[MAX_ROWS][NUM_COLS] = {
        {3, 5, 1, 2, 0}, // array[i]
        {6, 1, 5, 4, 3}, // array[i + 1]
        {1, 6, 2, 3, 7},
        {19, 0, 0, 0, 0},
        {0, 5, 1, 2, 3},
    }; // expected max 8

    int result = max_consec_row_diff(5, test_array);
    printf("%d\n", result);

    return 0;
}

int max_consec_row_diff(int num_rows, int array[MAX_ROWS][NUM_COLS]) {
    int max = -1;

    int i = 0;
    while (i < num_rows - 1) {
        int sum_a = 0;
        int sum_b = 0;

        int j = 0;
        while (j < NUM_COLS) {
            sum_a += array[i][j];
            sum_b += array[i + 1][j];
            j++;
        }

        int diff = sum_a - sum_b;
        if (diff < 0) {
            diff = -diff;
        }

        if (max == -1 || max < diff) {
            max = diff;
        }

        i++;
    }

    return max;
}












