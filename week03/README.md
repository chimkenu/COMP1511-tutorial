# COMP1511 Tutorial - Week 03

## While Loops

- Condition is checked before and after each execution
  of the loop body
- Condition should contain at least 1 variable, which
  changes within the loop body

```c
while (/* some condition is true */) {
    // loop body
    // execute some code
}
```

### Examples

```c
// Count loop
int counter = 0;
while (counter < MAX) {
    // Do something here
    counter++; // increment counter

    // Other ways to increment counter
    // counter = counter + 1;
    // counter += 1;
}

// Conditional/Sentinal loop
char answer = 'n';
while (answer != 'y') {
    // Do something here
    scanf(" %c", &answer); // update value of answer
}
```

## 2D While Loop

- Just a while loop where its body contains another loop

```c
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

## `scanf` in a loop

- Return value of `scanf` tells how many variables were successfully scanned
- `Ctrl+D` means "end of input", so any remaining `scanf` in the code doesn't scan
- `scanf` will continue scanning from where it previously stopped
- This means you can give input to multiple `scanf` calls on the same line
- See below for an example program

```c
// THE CODE (Assume its in a file called `scanf.c`)
char letter1 = '\0';
int scanf_return = scanf(" %c %c", &letter);
printf("Scanned %d characters: %c\n", scanf_return, letter);
scanf_return = scanf(" %c", &letter);
printf("Scanned %d characters: %c\n", scanf_return, letter);

// EXAMPLE RUNTIME 1
> ./scanf
a
Scanned 1 characters a
b
Scanned 1 characters b

// EXAMPLE RUNTIME 2
> ./scanf
ab
Scanned 1 characters a
Scanned 1 characters b

// EXAMPLE RUNTIME 3
> ./scanf
a
Scanned 1 characters a
[CTRL+D]
Scanned 0 characters a
```

## For loop (Optional)

- You can do anything a for loop can do with a while loop.
  However, for loops can be useful in cases where you know
  the number of times a loop will be executed.
- For loops help avoid certain bugs by enforcing structure
  on initialization, condition, and increment operations.
  This makes it less likely to forget or misplace the `i++`
  or `i = 0` operations.

Example:
```c
// oh no! this will not work as intended.
#define SIZE 3

int main(void) {
    int array[SIZE][SIZE] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    }

    int i = 0;
    int j = 0;
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
#define SIZE 3

int main(void) {
    int array[SIZE][SIZE] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
```

