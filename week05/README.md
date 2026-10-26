# COMP1511 Tutorial - Week 05

## 2D Arrays

- An array variable where each element is another array
- Can be thought of as a grid, where the first index corresponds to the row

### Integer example

```c
// Array of 3 integer arrays (each containing 4 integers), explicitly initialized
int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
// Represented as a grid like so:
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12

printf("%d", array[0][0]); // Prints 1
printf("%d", array[2][1]); // Prints 10
```

### Example for 2D array of structs

```c
enum entity {
    STAR,
    PLANET,
    NEBULA,
    SPACESHIP,
    EMPTY
};

struct celestial_body {
    enum entity entity;
    int points;
};

int main(void) {
    // This creates a 5x5 array of celestial bodies
    // Each element in the galaxy has an entity
    struct celestial_body galaxy[5][5];

    // Example setting the point (0, 0) to a spaceship
    galaxy[0][0].entity = SPACESHIP;
    galaxy[0][0].points = 100;

    return 0;
}
```

## Strings

- A string is just an **array of characters**
- Must always end with a null terminator (`\0`)

```c
char char_array[5] = {'h', 'e', 'l', 'l', 'o'}; // this is NOT a string!
char string[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
char string_notation[6] = "hello";
```

### Printing and Scanning Strings

How to scan a string?

```c
char input_string[1024];
scanf("%s", input_string); // DO NOT DO THIS!!!!
fgets(input_string, 1024, stdin); // do this instead!
```

How to print a string?

```c
// Printing method 1
int i = 0;
while (string[i] != '\0') {
    printf("%c", string[i]);
    i++;
}

// Printing method 2
printf("%s", string);

// Printing method 3
fputs(string, stdout);
```

How to shorten (cut) a string?

```c
char string[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
// lets say i want to cut the string at index 2
// i.e. i am only interested in the first 2 characters

// Cut the string at index 2
string[2] = '\0';
printf("%s", string); // prints "he"
// the whole array: {'h', 'e', '\0', 'l', 'o', '\0'}
```

> [!caution] Note that the array is still of size 6.
> We can cut strings arbitrarily, all we do is put a '\0' at the end of the shortened string.
> How can we do the opposite? How can you add to a string? See [concatenation](https://www.geeksforgeeks.org/computer-science-fundamentals/concatenation-of-two-strings/)

### String Functions



