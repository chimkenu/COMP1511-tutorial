---
title: COMP1511 Tutorial - Week 03
---

Announcements
---

Lab check-ins start this week!

Make sure you are doing style checks! (`1511 style <file>`)

Help sessions are starting this week!

<!-- end_slide -->

Last week, we learned how to use variables and operators to calculate and control flow in a program.

<!-- pause -->

What if we wanted to do the same operation multiple times? (e.g. calculating the total expenses)

<!-- pause -->

```c
int sum = 0;
int item1;
printf("Price: ");
scanf("%d", *item1);
sum = sum + item1;

int item2;
printf("Price: ");
scanf("%d", *item2);
sum = sum + item2;

int item3;
printf("Price: ");
scanf("%d", *item3);
sum = sum + item3;

// ...and so on
```

Is this good code? What are the limitations?

<!-- end_slide -->

<!-- jump_to_middle -->

Loops
---

<!-- end_slide -->

While Loops
---

```c
while (/* some condition is true */) {
    // loop body
    // execute some code
}
// rest of program
```

- Condition is checked before each execution of the loop body
- Condition should contain at least 1 variable, which
  changes within the loop body

<!-- end_slide -->

Examples
---

```c +exec {all|3|4|5-6|5|6|all}
/// #include <stdio.h>
#define MAX 5

/// int main(void) {
int counter = 0;
while (counter < MAX) {
    printf("%d\n", counter);
    counter++;
}
/// }
```

<!-- end_slide -->

Examples, cont'd
---

```c
char answer = 'n';
while (answer != 'y') {
    printf("Are we there yet? ");
    scanf(" %c", &answer);
}
printf("yippee!!\n");
```

<!-- pause -->

```
$ dcc example.c -o example
$ ./example
Are we there yet? n
Are we there yet? n
Are we there yet? s
Are we there yet? n
Are we there yet? y
yippee!!
```

<!-- end_slide -->

Examples, cont'd
---

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
Price: hello
Total: 600
```

<!-- end_slide -->

2D While Loop
---

- A while loop that contains another while loop

```c
#define MAX_ROW 2
#define MAX_COL 4

/// #include <stdio.h>
/// int main(void) {
// outer loop starts here
int row = 0;
while (row < MAX_ROW) {
    printf("Outer loop running, row = %d\n", row);

    // inner loop starts here
    int col = 0;
    while (col < MAX_COL) {
        printf(" > Inner loop running, col = %d\n", col);
        col++;
    }
    // end of inner loop

    row++;
}
// end of outer loop
/// }
```

<!-- end_slide -->

Enums
---

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

<!-- end_slide -->

Structs
---

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

