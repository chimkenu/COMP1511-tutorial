// Count Alphabetical Pairs
//
// Given an array of characters, count the number of 'alphabetical pairs'.
// An alphabetical pair is a consecutive pair of alphabetic characters of
// the same case whose second element succeeds the first (in the alphabet).
//
// Example: in the string "abCDF", we have
// 1. "ab" is an alphabetical pair
// 2. "bC" is NOT an alphabetical pair, since they do not share the same case
// 3. "CD" is an alphabetical pair
// 4. "DF" is NOT an alphabetical pair, since 'F' is not the successor of 'D'
// in the example above, the number of alphabetical pairs is 2.
//
// Solution below:

#include <stdio.h>

#define MAX_SIZE 100

int count_alphabetical_pairs(int size, char array[MAX_SIZE]);

int main(void) {
    char test_array[MAX_SIZE] = {'a', 'b', 'C', 'D', 'F'};
    int size = 5;
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
