---
title: COMP1511 Tutorial - Week 04
---

Announcements
---

Assignment 1 !!! (due week 7 monday, Oct 26)

<!-- end_slide -->

Last week, we learned how to execute the same code multiple times using loops.
```c
int sum = 0;
int keep_going = 1;
while (keep_going == 1) {
    int item = 0;
    keep_going = scanf("%d", &item);
    sum += item;
}
printf("Total: %d\n", sum);
```

<!-- pause -->

What if we wanted to list the items? *Sort them by value?*

<!-- pause -->

```c
int sum = 0;
int item1;
int item2;
int item3;
// and so on...

printf("Total: %d\n", sum);
printf("Item 1: %d\n", item1);
printf("Item 2: %d\n", item2);
printf("Item 3: %d\n", item3);
```

<!-- end_slide -->

<!-- jump_to_middle -->

Arrays
---

<!-- end_slide -->

Arrays
---

<!-- column_layout: [1, 1] -->

<!-- column: 0 -->

- Stores a collection of values with the same data type
- Must be declared with a constant size (**CANNOT BE A VARIABLE**)
- Contents must be explicitly initialized otherwise elements are "empty"
- Use square brackets `[]` and index to access a specific element
  - Index starts at `0`
  - Index of last element is always `SIZE - 1`

<!-- column: 1 -->

```c
// Array of 5 integers, explicitly initialized
int array1[5] = {1, 2, 3, 4, 5};
printf("%d\n", array1[1]); // prints "2"

// Array of 3 doubles, all 0
double array2[3] = {0};
array2[1] = 3.14;
// array2 is now: {0, 3.14, 0}

// this is how to initialize every
// element to a value other than 0
int array3[15];
for (int i = 0; i < 15; i++) {
    array3[i] = 1; // this sets all elements to 1
}
```

<!-- end_slide -->

<!-- jump_to_middle -->

Functions
---

<!-- end_slide -->

Why make functions?
---

- Reduce complexity
    - Should only do **1** logical task
    - Can be split into many smaller functions
    - Should be maximum **50 lines** long (split into smaller functions if needed)
- Reusable
    - Can be reused with different arguments
    - Avoids code repetition

<!-- pause -->

> To meet the 50 line limit imposed by COMP1511 style

<!-- pause -->

<!-- column_layout: [1, 1] -->

<!-- column: 0 -->

```c
int radius;
printf("Enter radius: ");
scanf("%d", &radius);

int area;
area = radius * radius * 3.14159;

printf("Circle of radius %d has area %d\n", radius, area);
```

<!-- column: 1 -->

```c
int radius = scan_radius();

int area = calculate_circle_area(radius);

display_data(radius, area);
```

<!-- end_slide -->

Function Prototypes
---

- Always think about this first!
- Goes above `main` (or in its own header file)
- Only declares the return type, parameter types and function name
- Looks like the first line of the function, without its body

```c
/*return_type*/ function_name(/*parameters*/);

// Examples:
int main(void);
int factorial(int n);           // n!
double sum(double a, double b); // a + b
double pow(double x, int p);    // x^p
```

<!-- end_slide -->

Function Implementations (Definitions)
---

- Goes below `main`, and contains the actual code for what the function should do
- Follows the syntax below where
  - `return type` is the data type of the return value, which can be stored
  - `parameters` are variables which are given value when the function is called
  - The `return` statement is not required when return type is `void`

```c
/*return_type*/ function_name(/*parameters*/) {
    // Function body

    return /*value*/;
}

// Example:
int main(void) {
    printf("Hello World!");
    return 0;
}
```

