# COMP1511 Tutorial - Week 07

## Pointers

- A special kind of data type
- Allows us to reference memory addresses and the data stored in it
- Gives more control over data

```c
// This creates a variable called 'number'
// with data type integer and stores the value 1
int number = 1;

// This creates a variable called 'pointer'
// with data type integer pointer and
// stores the memory address of 'number'
int *pointer = &number;

// works for char, double, structs, and enums as well
char c = 'a';
char *p = &c;
```

So how do we access and manipulate pointers?

```c
int number = 1;
int *pointer = &number;

// This accesses the memory address that 'pointer' holds
// (that is, 'number'), and updates the value to be number + 1 (which is 2).
*pointer = *pointer + 1;
// number = number + 1; // this is the equivalent of the above line.

printf("%d", *pointer); // prints '2', the value 'pointer' is pointing to
printf("%p", pointer);  // prints the memory address of 'number',
                        // the address stored inside 'pointer'

printf("%d", number);   // prints '2', the value stored inside 'number'
printf("%p", &number);  // prints the memory address of 'number', same as 2nd printf

printf("%p", &pointer); // prints the memory address of 'pointer'.

*pointer = 3;           // this 'dereferences' pointer (i.e. accessing 'number')
                        // and updates the value to 3.
printf("%d", number);   // this prints '3' since we updated it in the line above.
```

### Using Pointers in Functions

Suppose we wanted to update a variable in main, but from a function:

```c
#include <stdio.h>

void increment(int x);

int main(void) {
    int x = 6;
    printf("x before increment: %d\n", x);
    increment(x);
    printf("x after increment: %d\n", x);
    return 0;
}

void increment(int x) {
    x = x + 1;
}
```

We expect the above program to print:

```
x before increment: 6
x after increment: 7
```

However, if you were to try the above program yourself, you would see:

```
x before increment: 6
x after increment: 6
```

It seems like `x` did not update.

What is actually happening is that function parameters copy values that you pass in,
and so when you do `x = x + 1` in the increment function, `x` is 6 only in the increment function,
not in main. That is, the `x` variable in `main` is different from the `x` variable in `increment`.

To get around this, you have to access the memory address of `x` in main itself to update it,
and we do this using pointers.

```c
#include <stdio.h>

void increment(int *x); // int x becomes int *x
                        // since we are now using pointers

int main(void) {
    int x = 6;
    printf("x before increment: %d\n", x);
    increment(&x); // here we have to give the memory address of x,
                   // not the value stored inside of x.
    printf("x after increment: %d\n", x);
    return 0;
}

void increment(int *x) {
    *x = *x + 1; // note that we have to 'go to' or "dereference"
                 // the memory address that x is pointing to.
}
```

Note now that `x` in main is a normal integer, but `x` in increment
is now a pointer to an integer.

## Command Line Arguments

We typically get user input using scanf like this:

```c
int main(void) {
    int x;
    printf("give me a number NOW! ");
    scanf("%d", &x);
    printf("thanks :D\n");
}
```

This is somewhat cumbersome, since we have to type input in several lines.
What if we could get input in one line like `dcc`?

```c
int main(int argc, char *argv[]) {
    // code
}
```

```c
int main(int argc, char **argv) {
    // this also works! can you explain why?
}
```

Running `./program test 123` will give
```
argc = 3
argv = {"./program", "test", "123"}
```

Try this:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", argv[i]);
    }
    return 0;
}
```

and run the compiled program with different arguments.

