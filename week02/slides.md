---
title: COMP1511 Tutorial - Week 02
---

<!-- jump_to_middle -->

Variables and Constants
---

<!-- end_slide -->

Exercise #1
---

In this short activity we will recap how to declare, initialise and print variables.

```c
// part1_variables
//
// This program was written by YOUR-NAME (ZID)
// on [DATE]
//
// This program calculates the area of a circle

#include <stdio.h>

int main(void) {
    // 1. Declare the variables

    // 2. Initalise the variables

    // 3. Calculate the area of the circle

    // 4. Print the result

    return 0;
}
```

> [!caution] Make sure all your variables are sensibly named!
> No "x" or "y" variables (unless provided in started code)
> Should be considerably descriptive (e.g. int row, char cmd)

<!-- end_slide -->

Exercise #1 Solution
---

```c
// part1_variables
//
// This program was written by Marcus Alejo (z5559853)
// on 27/07/2025
//
// This program calculates the area of a circle

#include <stdio.h>

#define PI 3.14159

int main(void) {
    // 1. Declare the variables
    double radius;
    double area;

    // 2. Initalise the variables
    printf("Please enter the radius of your circle: ");
    scanf("%lf", &radius);

    // 3. Calculate the area of the circle
    area = PI * radius * radius;

    // 4. Print the result
    printf("The area of a circle with radius %lf is %lf\n", radius, area);

    return 0;
}
```

<!-- end_slide -->

<!-- jump_to_middle -->

Calculating Values in Programs
---

or, Operators
---

<!-- end_slide -->

Exercise #2
---

Let's try to recall all the operators that have been discussed in the lectures.

<!-- pause -->
<!-- alignment: center -->

| Type of Operator | Operators         |
| ---------------- | ----------------- |
| Arithmetic       | `+ - * / %`       |
| Logic            | `&& \|\| !`       |
| Comparison       | `< > <= >= != ==` |

<!-- pause -->
<!-- alignment: left -->

What is the difference between `/` and `%`?
<!-- pause -->
- `5 / 2 = 2` (the remainder `1` is discarded)
- `5 % 2 = 1` (the quotient `2` is discarded)

<!-- end_slide -->
Exercise #2, cont'd
---

How can we tell if a number is even or odd?
<!-- pause -->
- Use modulo 2:

```c +exec {2-6}
/// #include <stdio.h>
/// int main(void) {
int num = 5;
if (num % 2 == 0) {
    printf("num is even!\n");
} else if (num % 2 == 1) {
    printf("num is odd!\n");
}
/// }
```

<!-- end_slide -->

<!-- jump_to_middle -->

Weird Data Types and Arithmetic
---

<!-- end_slide -->

Data Types
---

<!-- alignment: center -->
| Data Type      | Keyword  | Example                     | Format specifier |
| -------------- | -------- | --------------------------- | ---------------- |
| Integer        | `int`    | `1`, `100`, `-3`            | `%d`             |
| Character      | `char`   | `'a'`, `'1'`, `'\n'`, `'$'` | `%c`             |
| Decimal number | `double` | `1.1`, `3.0`, `-5.25`       | `%lf`            |

<!-- end_slide -->

Exercise #3
---

Let's try to evaluate the following expressions!

<!-- column_layout: [1, 1] -->

<!-- column: 0 -->

`7 / 2`
<!-- pause -->
- Mathematical Answer: `3.5`
- C Answer: `3`

`(3.0 / 2) + 1`
<!-- pause -->
- Mathematical Answer: `2.5`
- C Answer: `2.5`

<!-- column: 1 -->

`'a' + 5`
<!-- pause -->
- Mathematical Answer: `¯\_(ツ)_/¯`
- C Answer: `'f'`

`('F' - 'A') + 'a'`
<!-- pause -->
- Mathematical Answer: `¯\_(ツ)_/¯`
- C Answer: `'f'`

<!-- end_slide -->

<!-- jump_to_middle -->

Diagramming
---

<!-- end_slide -->

Exercise #4 Solution
---

```python {1-2|3-10|4-5|7-8|9-10|12-19|13-14|16-17|18-19|21-28|21|all}
print "How many days till your assignment is due?"
scan days
if days > 10:
    print "Are you up to date with lectures and labs?"
    scan up_to_date

    if up_to_date == yes:
        print "Work on your assignment."
    else:
        print "Catch up on them!"

else if days >= 7 and days <= 10:
    print "Have you started your assignment?"
    scan started

    if started == yes:
        print "Great! Don’t forget to check style as you go!"
    else:
        print "You should start! Ask for help if you need."

else (i.e days < 7):
    print "Are you on track to finish?"
    scan on_track

    if on_track == yes:
        print "You got this, keep at it!"
    else:
        print "Attend help sessions, ask your tutors and forums for assistance"
```

<!-- end_slide -->

Exercise #5
---

In this activity, you'll be writing a program to determine whether someone is tall enough to ride a roller coaster. It should:

1. `Scan` in the users `height`.
2. If the height is `0 or less`, it should `print` an error message,
3. If the height is `below the minimum` height, it should print a message telling the user they are not tall enough to ride,
4. If the height is `above the minimum` but `below the ride alone threshold`, it should print a message telling the user they can ride with an adult,
5. If the height `is or is above` the ride alone threshold, it should print a message telling the user they can ride.

For the purposes of this activity the minimum height to ride if `100cm` and the minimum height to ride alone is `160cm`.

<!-- end_slide -->

Exercise #5 Solution
---
```c
// part5_roller_coaster_improved
//
// This program was written by Sofia De Bellis (z5418801)
// on February 2024

#include <stdio.h>

#define MINIMUM_HEIGHT 100
#define RIDE_ALONE_HEIGHT 160

int main(void) {
    printf("Please enter your height: ");
    double height;
    scanf("%lf", &height);

    if (height <= 0) {
        printf("Invalid height!\n");
    } else if (height < MINIMUM_HEIGHT) {
        printf("Sorry, you are not tall enough to ride :<\n");
    } else if (height < RIDE_ALONE_HEIGHT) {
        printf("Yay! You are tall enough to ride. But only with an adult!\n");
    } else {
        printf("Congratulations! You are tall enough to ride alone!\n");
    }

    return 0;
}
```
