# Q4 - Critical Points

> **Q4.** Given a 2D array of doubles, find the number of *critical points*.

A critical point is defined to be an element whose *neighbours*
are strictly less than itself.

We define the neighbours of a particular element in a 2D array
to be all adjacent elements. On a 2D grid, these would be cells
with Chebyshev distance of 1. For example,

```
in a 3x3 array:            in a 2x2 array:
1.0  3.0  2.0              9.4  5.1
2.5  6.7  0.2              8.7  6.2
4.2  2.1  1.1
```

For the 3x3, the element with value `6.7` (at `row 1, col 1`)
would be a critical point, since all 8 surrounding points are
strictly less than `6.7`.

In the 2x2, the element with value `9.4` (at `row 0, col 0`)
would also be a critical point as it is greater than every surrounding element.
In this case we only have to consider the 3 points since
`9.4` is at the boundary of the array, and thus adjacent to only those 3 elements.

You are to implement the function:

```c
int count_crit_points(double array[MAX][MAX], int n_rows, int n_cols);
```

Note that the array has a maximum number of rows and cols,
but can vary in size. Refer to the given integers `n_rows`
and `n_cols` to determine the actual size of the array.

## Example Usage

Assuming you name the file `q4.c`, you should expect to see:

```
$ dcc q4.c -o q4
$ ./q4
Enter number of rows and columns 3 3
Enter row 0: 1.0 3.0 2.0
Enter row 1: 2.5 6.7 0.2
Enter row 2: 4.2 2.1 1.1
Found 1 critical point(s)
$ ./q4
Enter number of rows and columns: 5 5
Enter row 0: 5.0 5.1 2.3 1.6 3.7
Enter row 1: 7.6 9.2 1.2 4.4 8.8
Enter row 2: 1.1 4.3 0.2 1.9 9.2
Enter row 3: 3.2 1.1 5.5 1.2 2.2
Enter row 4: 8.1 8.1 2.3 2.2 1.2
Found 2 critical point(s)
$ ./q4
Enter number of rows and columns: 4 4
Enter row 0: 0 1 0 1
Enter row 1: 1 0 1 0
Enter row 2: 0 1 0 1
Enter row 3: 1 0 1 0
Found 0 critical point(s)
```

The first example is the same as the 3x3 example described earlier.

The second example I just put some 'random' numbers.
Only the values with 9.2 are critical points here.

The final example is a checkerboard pattern of 0s and 1s, which
has no critical points (as you always have an equal valued neighbour)

## Starter Code

```c
#include <stdio.h>

// you can change this if you want
#define MAX 100

int count_crit_points(double array[MAX][MAX], int n_rows, int n_cols);

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
    // TODO: Write your solution here!
    return -1;
}
```

## Variations

1. What if we only needed to check cardinally adjacent cells ([von Neumann neighbourhood](https://en.wikipedia.org/wiki/Von_Neumann_neighborhood))?
2. What if we needed to check around some radius (using euclidean distance)?

## Solution

[*click me for the full solution*](../sols/q4-crit.c)

For each point: check all surrounding points are less than current point.

> Work in progress.......

