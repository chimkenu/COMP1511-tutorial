---
title: COMP1511 Tutorial - Week 05
---

Announcements
---

Revision sessions (Week 6):
- Week 6 Tuesday 20/10/2026 2pm-4pm in Bongo Lab K17 G07A
- Week 6 Friday 23/10/2026 12pm-2pm in Bongo Lab K17 G07A

<!-- end_slide -->

Last week, we learned how to use arrays to store a collection of values.

What if we wanted to store more complex data, like a game of sudoku, chess, or minesweeper?

<!-- pause -->

Using a single array, you might be interested in storing a 3x3 'sudoku' game like so:

```c
int array[9] = {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
};

array[0]; // this is 1
array[7]; // this is 8

int row = 1;
int col = 1;
int index = (3 * row) + (col); // this is 3 + 1 = 4
array[index]; // this is 5
```

<!-- end_slide -->

2D Arrays
---

- An array variable where each element is another array
- Can be thought of as a grid, where the first index corresponds to the row

```c
// Array of 3 integer arrays (each containing 4 integers), explicitly initialized
int array[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

printf("%d", array[0][0]); // Prints 1
printf("%d", array[2][1]); // Prints 10
```

<!-- end_slide -->

Strings
---

- A string is just an **array of characters**
- Must always end with a null terminator (`\0`)

```c
char char_array[5] = {'h', 'e', 'l', 'l', 'o'}; // this is NOT a string!
char string[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
char string_notation[6] = "hello";
```

How to scan a string?

<!-- pause -->
```c
char input_string[1024];
scanf("%s", input_string); // DO NOT DO THIS!!!!
fgets(input_string, 1024, stdin); // do this instead!
```

<!-- end_slide -->

Strings, cont'd.
---

> char string[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

<!-- column_layout: [1, 1] -->

<!-- column: 0 -->

How to print a string?

<!-- pause -->
```c
// Printing method 1 (conditional loop)
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

<!-- column: 1 -->

Can't we treat strings like normal arrays?

<!-- pause -->

```c
// Why not a counting loop?
int i = 0;
while (i < 6) {
    printf("%c", string[i]);
    i++;
}
```

What are the limitations of the above implementation?

<!-- end_slide -->

String Operations
---

> Your turn! Try to implement these string functions:

```c
// returns the number of lowercase characters in a string
int count_lowercase(char string[MAX_CHARS]);

// converts all vowels in a string to uppercase
void make_vowels_uppercase(char string[MAX_CHARS]);

// isolates the first 'word' in a sentence
// "This is a string" -> "This"
void delete_following_words(char string[MAX_CHARS]);
```

