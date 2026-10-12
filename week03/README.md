# COMP1511 Tutorial - Week 03

Reminder to do style checks! (`1511 style <file>`)

[Also, help sessions are starting this week!](https://cgi.cse.unsw.edu.au/~cs1511/current/help-sessions)

## Loops

Loops allow us to repeat the execution of some code. C allows us to use the `while` keyword
to construct a while loop:

```c
while (/* some condition is true */) {
    // loop body
    // execute some code
}
```

- Condition is checked before each execution of the loop body
- Condition should contain at least 1 variable, which
  changes within the loop body

Depending on what you are trying to do, there are patterns or similarities in the structure
of a loop. 

### Counting Loop

Has a variable (counter) that starts at some initial value (usually 0)
and increments (usually by 1) until it reaches a particular bound.

```c
int counter = 0;
while (counter < MAX) {
    // Do something here
    counter++; // increment counter

    // Other ways to increment counter
    // counter = counter + 1;
    // counter += 1;
}
```

### Sentinel loop

The variable in the condition is either a true or false value (usually 0 or 1)
and the loop runs while the variable (called a flag) is one of these two possible values.

```c
char answer = 'n';
while (answer != 'y') {
    // Do something here
    scanf(" %c", &answer); // update value of answer (either y or n)
}
```

### Conditional loop

Umbrella term for literally any other loop that doesn't match the first two.

```c
int x;
printf("Give me an even number: ");
while (scanf("%d", &x) == 1 && x % 2 == 1) {
    printf("No, %d is not even. Try again: ");
}
printf("Thanks.");
```

## 2D While Loop

- Just a while loop where its body contains another loop
- These are usually nested counting loops (a counting loop inside another counting loop)

```c
// outer loop start
int row = 0;
while (row < MAX_ROW) {
    printf("Outer loop running, row = %d\n", row);

    // inner loop starts here
    int col = 0;
    while (col < MAX_COL) {
        print("Inner loop running, col = %d\n", col);
        col++;
    }
    // end of inner loop

    row++;
}
// outer loop end
```

## Structs

- `struct` is short for structure, which is a user-defined
  data type allowing variables of different data types to be
  grouped under a single name
- When initializing a `struct`, all its fields must also be
  initialized

```c
struct coffee {
    enum coffee_type type;
    double num_sugars;
    char size;
};

int main(void) {
    struct coffee my_coffee;
    my_coffee.type = LATTE;
    my_coffee.num_sugars = 2;
    my_coffee.size = 'L';
}
```

## Enums

- `enum` is short for enumeration, which is a user-defined
  data type allowing a set of named constants to be grouped
  together
- Default value starts at 0 and increases by 1
- Values can also be specified

```c
enum coffee_type {
    LATTE,          // value = 0
    CAPPUCCINO,     // value = 1
    ESPRESSO,       // value = 2
    AMERICANO,      // value = 3
    MATCHA = 5      // value = 5
};

int main(void) {
    printf("%d\n", LATTE); // will print 0
}
```

## Demystifying `scanf()`

- Return value of `scanf` corresponds to how many variables were successfully scanned
- Typing `ctrl+d` on the terminal means "end of input"; `scanf` can no longer read any input following this.
- `scanf` will continue scanning from where it previously stopped
- This means you can give input to multiple `scanf` calls on the same line

Try the program below. (please)

```c
#include <stdio.h>
int main(void) {
    int number;
    printf("enter a number: ");
    int return_value = scanf("%d", &number);
    printf("scanf returned %d\n", return_value);
}
```

This is for you to test inputs and see what return values you will get.
Here is an example below that you might see:

```
$ dcc test.c -o test
$ ./test
enter a number: 67
scanf returned 1
$ ./test
enter a number: apple
scanf returned 0
$ ./test
enter a number: [ctrl+d]
scanf returned -1
```

These are the three possible outputs for a single `scanf`.
I first entered a valid integer, and `scanf` returned 1, meaning it successfully scanned that one integer.
I then entered 'apple', which is certainly not an integer, and thus `scanf` returned 0, meaning it did not match the format string `%d`.
Finally, I entered `ctrl+d`, which is the end of input, and `scanf` wants to differentiate this outcome (nothing to scan)
from the above case (scanned something that is not an integer). In this case `scanf` returns -1.

Now the example below scans numbers until the user types `ctrl+d`.
Afterwards, it prints the sum.

```c
int sum = 0;
int item;
printf("Price: ");
while (scanf("%d", &item) == 1) {
    sum += item;
    printf("Price: ");
}
printf("Total: %d\n", sum);
```

```
$ dcc example2.c -o example2
$ ./example2
Price: 100
Price: 200
Price: 300
Price: [ctrl+d]
Total: 600
```

## For loop (Optional)

- You can do anything a `for` loop can do with a `while` loop.
  However, `for` loops can be useful in cases where you know
  the number of times a loop will be executed.
- `for` loops help avoid certain bugs by enforcing structure
  on initialization, condition, and increment operations.
  This makes it less likely to forget or misplace the `i++`
  or `i = 0` operations.

Example:
```c
// oh no! this will not work as intended.
#include <stdio.h>

#define SIZE 3

int main(void) {
    int array[SIZE][SIZE] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    int i = 0;
    int j = 0; // the problem is this line. can you see why?
    while (i < SIZE) {
        while (j < SIZE) {
            printf("%d ", array[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
```

```c
// this will work
#include <stdio.h>

#define SIZE 3

int main(void) {
    int array[SIZE][SIZE] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { // you are less likely to forget to reset j = 0 here.
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
```

