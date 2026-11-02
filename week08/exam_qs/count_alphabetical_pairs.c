#include <stdio.h>

#define MAX_SIZE 100

int count_alphabetical_pairs(int size, char array[MAX_SIZE]);

// "abcdef"
// 'alphabetical_pairs' => 'a' -> 'b', 'a' -> 'B' X
// "aBC" 1

int main(void) {
    char test_array[MAX_SIZE] = {'l', 'm', 'n', 'o'};
    int size = 4;
    int result = count_alphabetical_pairs(size, test_array);
    printf("%d\n", result);
    return 0;
}


int count_alphabetical_pairs(int size, char array[MAX_SIZE]) {
    int count = 0;
    int i = 0;
    while (i < size - 1) {
        if (array[i + 1] == array[i] + 1) {
            count++;
        }
        i++;
    }
    return count;
}

















/*

int count_alphabetical_pairs(int size, char array[MAX_SIZE]) {
    if (size < 2) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] + 1 == array[i + 1]) {
            count++;
        }
    }
    return count;
}

*/
