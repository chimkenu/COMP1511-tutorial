# COMP1511 Tutorial - Week 04

## Arrays

- Stores a collection of values with the same data type
- Must be declared with a **constant** size [(**CANNOT BE A VARIABLE**)](https://www.geeksforgeeks.org/cpp/variable-length-arrays-in-c-and-c/)
- Contents must be explicitly initialized otherwise elements are "empty"
- Use square brackets `[]` and index to access a specific element
  - Index starts at `0`
  - Index of last element is always `SIZE - 1`

```c
// Array of 5 integers, explicitly initialized
int array1[5] = {1, 2, 3, 4, 5};
printf("%d\n", array1[1]); // prints "2"

// Array of 3 doubles, all 0
double array2[10] = {0};
array2[1] = 3.14;
// array2 is now: {0, 3.14, 0}

// this is how to initialize every
// to a value other than 0
int array3[15];
for (int i = 0; i < 15; i++) {
    array3[i] = 1; // this sets all elements to 1
}
```

## Functions

- Should only do **1** logical task
- Can be split into many smaller functions
- Should be maximum **50 lines** long (split into smaller functions if needed)
- Can be reused with different arguments

### Function Implementations (Definitions)

- Goes below `main`, and contains the actual code for what the function should do
- Follows the syntax below where
  - `return type` is the data type of the return value, which can be stored
  - `parameters` are variables which are given value when the function is called
  - The `return` statement is not required when return type is `void`

```c
/* return type */ function_name(/* parameters */) {
    // Function body

    return /* value */;
}
```

### Function Prototypes

- Goes above `main`
- Only declares the return type, parameter types and function name
- Looks like the first line of the function, without its body

### Example

```c
// Prototype above main
int sum(int num1, int num2);

int main(void) {
    int a = 1;
    int b = 2;

    // Call the function and save return value to variable called "total"
    // Note how the name of variables passed to the function
    // doesn't need to match the name of the parameter
    int total = sum(a, b);

    return 0;
}

// Function implementation
int sum(int num1, int num2) {
    return num1 + num2;
}
```

### So what makes a good function?

The quality of a function is usually tied to the typical properties
that we expect of a function (i.e. reusable, reduces complexity).
So we wish to make functions that are good in the sense that they
have these properties, which hopefully speed up development process.

Consider the following functions:

```c
// Returns 1 if n is even and 0 if n is odd
int is_even(int n) {
    return n % 2 == 0;
}
```

This function is reusable, as it allows us to input any integer `n`
and determine if it is even. However, this function is very short,
which implies that it does not hide a lot of information away from
anyone using this function. Thus it does not reduce the complexity
of your code. Sometimes in fact, it may even make your code longer,
as a short `if (n % 2 == 0)` would be replaced by a function prototype,
declaration and an `if (is_even(n))` function call.

```c
// Scans items from the user and prints the sum
void scan_items() {
    int sum = 0;
    int keep_going = 1;
    while (keep_going == 1) {
        int item = 0;
        keep_going = scanf("%d", &item);
        sum += item;
    }
    printf("Total: %d\n", sum);
}
```

This next example is a function that scans integers from the user and
eventually prints their sum after the user types `ctrl+d`. This function
hides information, as anyone using this function does not need to know
how it scans or takes a sum and prints, only that it does. This thus
reduces complexity where you call this function*. However, this function
is not very reusable: it only sums integers, not doubles, and has a fixed
printf message. Anyone who wishes to change any functionality (e.g. wanting
a different print message like `"The total is: %d\n"` will have to create
an entirely new function.

*now you can argue that this function doesn't actually reduce complexity
either, and I would agree: not only does the name of the function hide the
fact that it does several other things as well (i.e. take a sum), but also
that anyone using the function still implicitly needs to know exactly what
the function is doing in order to use it properly.

Despite this, there may be cases where you make functions like the ones above.
This is not a hard rule, and if writing a function like the above is what
you need to solve a problem, then that is the correct function to write.

Consider the function prototypes below:

```c
// Sorts an array in place
void sort(int array[SIZE], int size);

// Returns 1 if n is prime and 0 otherwise
int is_prime(int n);
```

These two functions are very general**: they can be used in many contexts,
especially the `sort` function, as sorting data one of the most common operations to solve many problems.
Additionally, `is_prime` is used in areas like cryptography and number theory.
The functions can take in a wide range of inputs, and all this makes them very reusable.

**so the `sort` function (in its formulation above) is limited; simply
because the type system in C forces you to pick a data type and size
for an array. There are certainly ways to get around this.

Additionally, I have not included an implementation for these functions.
Despite this, you can (hopefully) see how you would use them without
needing to see how they actually work. The functions are able to hide
information (about their implementation), and thus reduces the complexity
of code where they are used. If you were to use those functions, you need
not know how they work, only that they do.

So what qualities of a function make it good?
- information hiding => reduces complexity
- generality => reusability

> This is not a strict rule! we live in a free world

