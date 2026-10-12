// 2D LOOPS DEMO
//
// This program was written by Marcus Alejo (z5559853)
// on 09-28-26
//
// Slightly different from ./part2_2d_while_loops.c

#include <stdio.h>

#define MAX_ROW 2
#define MAX_COL 4

int main(void) {
    int row = 0;
    while (row < MAX_ROW) {

        // inner loop starts here
        int col = 0;
        while (col < MAX_COL) {
            printf("(%d, %d) ", row, col);
            col++;
        }
        // end of inner loop

        printf("\n");
        row++;
    }
}
