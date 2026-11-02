// First Balanced Row
//
// Given a 2D array of characters, return the index of the first 'balanced row'.
// A balanced row is a row where there are an equal number of consonants and vowels.
// See example in main below. If there are no balanced rows, return -1
//
// Solution below:

#include <stdio.h>

#define MAX_ROWS 100
#define NUM_COLS 6

int first_balanced_row(int num_rows, char array[MAX_ROWS][NUM_COLS]);

int main(void) {
    char test_array[MAX_ROWS][NUM_COLS] = {
        {'a', 'b', 'c', 'd', 'e', 'f'}, // row 0: a,e => 2 vowels, b,c,d,f => 4 consonants (not balanced)
        {'r', 't', 'h', 'o', 'i', 'u'}, // row 1: r,t,h => 3 consonants, o,i,u => 3 vowels (balanced)
        {'g', 'a', 'b', 'e', 'q', 'o'}, // row 2: g,b,q => 3 consonants, a,e,o => 3 vowels (balanced)
    }; // function should return 1 here, since row 1 is the first balanced row
    int num_rows = 3;
    int answer = first_balanced_row(num_rows, test_array);
    printf("first_balanced_row returned: %d\n", answer);
}

int is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int first_balanced_row(int num_rows, char array[MAX_ROWS][NUM_COLS]) {
    for (int row = 0; row < num_rows; row++) {
        int balance = 0;
        for (int col = 0; col < NUM_COLS; col++) {
            if (is_vowel(array[row][col])) {
                balance++;
            } else { // you might have to change this if non-alphabetic characters are allowed
                balance--;
            }
        }
        if (balance == 0) {
            return row;
        }
    }
    return -1; // there are no balanced rows
}

