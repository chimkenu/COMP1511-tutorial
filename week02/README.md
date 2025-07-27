# COMP1511 Tutorial - Week 02

## Variables

- Needs to be declared and initialized
    - Declaration: `data_type variable_name;`
    - Initialization: `variable_name = value;`
    - Can be done in one step: `data_type variable_name = value;`
        - Eg. `int num = 1;` _(declaring an integer variable named 'num' initialized with the value 1)_
- Values may be changed after initialization
    - Can be done with: `variable_name = value;` _(no need to put the data type again)_
    - The value stored in a variable can be changed, however data type **cannot**.

### Data Types

| Data Type      | Keyword  | Example                     | Format specifier | Additional notes                                                                                                                                                                      |
| -------------- | -------- | --------------------------- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Integer        | `int`    | `1`, `100`, `-3`            | `%d`             | May be positive or negative                                                                                                                                                           |
| Character      | `char`   | `'a'`, `'1'`, `'\n'`, `'$'` | `%c`             | Must be wrapped in single quotes. Stored as an integer ASCII value                                                                                                                    |
| Decimal number | `double` | `1.1`, `3.0`, `-5.25`       | `%lf`            | May have as many or as little decimal places. Must use explicit `.0` if using whole number as double in calculations. Can specify `X` number of decimal places to print using `.Xlf`. |

```c
////////////////////////////////////
// Declaration and Initialization //
////////////////////////////////////

// Integers
int n1 = 0;
int n2 = -213;

// Characters
char l1 = 'a';
char l2 = '*';
char l3 = '\n';
char l4 = 65;     // Don't do this (= 'A')

// Doubles
double d1 = 1.0;
double d2 = 3.14159;
double d3 = -123.456;

////////////////////////////////////
////// Scanning and Printing ///////
////////////////////////////////////

// Integers
printf("%d\n", n1);     // Prints 0
scanf("%d", &n2);       // Scans an integer from standard input and puts it in n2 (overwriting -213)

// Characters
printf("%c\n", l1);     // Prints a
scanf(" %c", &l2);      // Scans a character from standard input and puts it in l2 (overwriting '*')
                        // The space before the %c is to ignore leading whitespace (try this on your own!)

// Doubles
printf("%lf\n", d1);    // Prints out all decimal places
printf("%.2lf\n", d2);  // Prints up to 2 decimal places
scanf("%lf", &d3);      // Scans a double from standard input and puts it in d3 (overwriting -123.456)
```

### Constants

- Essentially are variables whose value never changes.
- Name of constants should always be in capital letters (`SCREAMING_SNAKE_CASE`).
- Declared at the top of the program using `#define NAME_OF_CONSTANT value`

```c
#define PI 3.14159
#define NUM_ALPHABET 26
#define MONDAY 'm'
```

## Operators

| Type of Operator | Operators         |
| ---------------- | ----------------- |
| Arithmetic       | `+ - * / %`       |
| Logic            | `&& \|\| !`       |
| Comparison       | `< > <= >= != ==` |

### Logic Operators

- Used for combining Boolean (True/False) expressions
- Can combine multiple at once (eg. `A && B && C`)
- Must use brackets to group if combining `&&` and `||` in the same expression
- Truth table below:

| A     | B     | `A && B` | `A  \|\| B` | `!A`  |
| ----- | ----- | -------- | ----------- | ----- |
| True  | True  | True     | True        | False |
| True  | False | False    | True        | False |
| False | True  | False    | True        | True  |
| False | False | False    | False       | True  |

### Arithmetic Operators

- Has the usual:
    - Addition `+`
    - Subtraction `-`
    - Multiplication `*`
    - Division `/` _(not really)_
- Order of operations:
    - Similar to maths in terms of brackets, multiplication/division, then addition/subtraction.

#### Operator `%` (remainder/modulo)

- Not exactly modulo in maths terms
- Calculates the remainder of the division
    - `5 % 3` will result in `2` since `5 / 3 = 1 remainder 2`
    - Will return a negative number of original number to divide is negative
    - `-5 % 3` will result in `-2`

#### Integer vs Float division

- If the operands (the numbers) of a division operation are both integers, the result is always an integer
    - `3 / 2` will result in `1` since both `3` and `2` are treated as integers
- If there is a double in either operand, the result will be also be a double.
    - `3.0 / 2` has a double (`3.0`) hence the result will be a double (`1.5`)

_if you are curious, search [floating-point arithmetic](https://en.wikipedia.org/wiki/Floating-point_arithmetic). it will make more sense if you take COMP1521._

#### More Examples

- `(7 / 2) = 3`
    - Both operands are integers, hence result is also an integer
- `(3.0 / 2) + 1 = 2.5`
    - Division is calculated first
    - Division involves a double in the operands hence result is a double (`3.0 / 2.0 = 1.5`)
- `'a' + 5 = 'f'`
    - Characters are stored as ASCII integers, so arithmetic occurs treating them as integers
    - Here `'a' = 97`, so `97 + 5 = 102`, and in ASCII `102 = 'f'`
- `('F' - 'A') + 'a' = 'f'`
    - Similar to previous example, convert all characters to ASCII integers to perform calculation
    - `(70 - 65) + 97 = 102`
    - Convert result back to ASCII character
