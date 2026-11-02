// Sum Between Negatives
//
// Given an array of integers, find the sum of the elements 
// between the first and last instance of a negative number.
// Example: {1, -4, 3, -7, 8, -2, 5}
// 1. at index 1, we have -4, which is the first negative number
// 2. at index 5, we have -2, which is the last negative number
// 3. in between, we have 3, -7, 8, which sum to 4
// answer: 3 + (-7) + 8 = 4
//
// Example: {-1, -2, 3, 4}
// 1. -1 is the first negative number
// 2. -2 is the last negative number
// 3. there are no integers between these numbers, so the sum should be 0
//
// Solution below:

#include <stdio.h>

#define MAX_SIZE 100

int sum_between_negatives(int size, int array[MAX_SIZE]);

int main(void) {
    int test_array[MAX_SIZE] = {1, -4, 3, -7, 8, -2, 5};
    int size = 7;
    int answer = sum_between_negatives(7, test_array);
    printf("sum_between_negatives returned: %d\n", answer);
}

int sum_between_negatives(int size, int array[MAX_SIZE]) {
    int first_idx = -1;
    int last_idx = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            if (first_idx == -1) {
                first_idx = i;
            }
            last_idx = i;
        }
    }

    int sum = 0;
    for (int i = first_idx + 1; i < last_idx; i++) {
        sum += array[i];
    }

    return sum;
}

