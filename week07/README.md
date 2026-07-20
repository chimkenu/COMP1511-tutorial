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
// (that is, 'number'), and updates the value to be 5.
*pointer = *pointer + 1;
number = number + 1; // this is the equivalent of the above line.

printf("%d", *pointer); // prints '1', the value 'pointer' is pointing to
printf("%p", pointer);  // prints the memory address of 'number',
                        // the address stored inside 'pointer'

printf("%d", number);   // prints '1', the value stored inside 'number'
printf("%p", &number);  // prints the memory address of 'number', same as 2nd printf

printf("%p", &pointer); // prints the memory address of 'pointer'.

*pointer = 2;           // this 'dereferences' pointer (i.e. accessing 'number')
                        // and updates the value to 2.
printf("%d", number);   // this prints '2' since we updated it in the line above.
```

## Command Line Arguments

We typically get user input using scanf like this:

```c
int main(void) {
    int x;
    printf("give me a number NOW!\n");
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

