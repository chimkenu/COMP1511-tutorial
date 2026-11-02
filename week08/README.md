# COMP1511 Tutorial - Week 8

## Memory Lifespan

We have been implicitly using the [stack](https://www.geeksforgeeks.org/dsa/stack-vs-heap-memory-allocation/)
when creating our variables. Currently, we run into the limitation where data cannot live outside the function
it was created in.

```c
char *get_string() {
    char str[MAX];  // this string is *local*, i.e. the memory for str
                    // will be deleted after this function returns.
    fgets(str, MAX, stdin);
    return str; // in fact, the compiler will already complain here.
}

int main(void) {
    char *string = get_string();
    printf("got the string: %s", string); // this will not work!!!
    return 0;
}
```

This is because `char str[MAX]` is declared within the `get_string` function,
and all variables declared within a function are discarded after a function
finishes running. That is, the data that would have been stored inside `str`
after `fgets` takes in a string from the user is actually deleted after
`str` is returned.

Note that returning `str` returns a pointer to the string, not the string itself.

## Malloc

The `stdlib` library in C gives us the `malloc` function, which allows us to
have full control over the lifespan of a particular piece of memory. `malloc`
is defined as follows:

```c
void *malloc(size_t size);
```

`malloc` takes in a number `size`, which refers to how much memory (in bytes)
to request from the computer. `malloc` returns a `void *` (void pointer),
which is a pointer but to some unknown value. The programmer usually determines
what data type it is pointing to.

```c
int *foo() {
    int x = 5;
    return &x;
}

int *bar() {
    int *x = malloc(sizeof(int));
    *x = 5;
    return x;
}

int main(void) {
    int *from_foo = foo();
    int *from_bar = bar();

    printf("%d\n", *from_foo);
    printf("%d\n", *from_bar);
}
```

The above program has issues on purpose (it will likely crash), this is
to illustrate that stack memory (making a local variable in foo)
behaves differently from heap memory (using malloc in bar). Play around
with the above program and see what happens.

`malloc` gives you full control over the memory and its lifespan.
As a result, it is now your responsibility to return the memory back
to the computer after use. Remember to use the `free` function (also in `stdlib`)
to give the memory you have used back to the computer for reuse.

```c
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// full example for malloc
int main(void) {
    int *x = malloc(sizeof(int)); // x now points to memory that can store one integer
    *x = 10;
    printf("address: %p, contains: %d\n", x, *x); // prints some address (different each time*) and the value 10

    int *array = malloc(sizeof(int) * SIZE); // array now points to memory that can store 5 integers (consecutively)
                                             // you can treat this as an array.
    array[0] = 10; // you can do normal array things.


    // remember to free the memory afterwards
    free(x);
    free(array);
    return 0;
}
```

[click here for more info on dynamic memory](https://www.geeksforgeeks.org/c/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)

## Linked List

A linked list is a kind of data structure.
Similar to arrays, linked lists store a sequence of values of the same type.
Linked lists work by having each element in the list be contained within
a node, defined below:

```c
struct node {
    int data;
    struct node *next;
}
```

In this case, `struct node` can store one value (`int data`) and
a pointer to the `next` node. A linked list is made up of these nodes,
where each node is connected to another via the `next` field.

### Creating a node

Here, you generally want to use `malloc` to create nodes.
This is because we want nodes to exist until we explicitly
require their deletion.

```c
struct node *new_node = malloc(sizeof(struct node));
new_node->data = 5;
new_node->next = NULL;
```

> Note that we used the arrow operator `->` to initialise `new_node`.
> Can you think of a way to initialise the node without this operator?

In this case, the newly created node (accessed via the `new_node` variable)
persists throughout the lifespan of the program. That is, if you were to do:

```c
new_node = NULL;
```

The memory that you requested from the computer using `malloc` still
contains the data put above, though you no would no longer have access
to it (since `new_node` does not point to the memory address anymore).

You could then make more nodes, and create a linked list by setting
the `next` field accordingly:

```c
struct node *node_1 = malloc(sizeof(struct node));
node_1->data = 3;
node_1->next = NULL;

struct node *node_2 = malloc(sizeof(struct node));
node_2->data = 5;
node_2->next = NULL;

node_1->next = node_2; // this connects node_1 to node_2
```

The above code creates a linked list which diagramatically looks like:
`3 -> 5 -> X`, where 3 is the data inside `node_1` and 5 is the data
inside `node_2`, and `X` denotes the end of the linked list (that is,
node_2 points to `NULL`).

We commonly use the terms *head* and *tail* of a linked list to refer
to the first and last node of said list respectively. In the example
above, the head of the linked list would be 3 (or `node_1`) and the tail
of the linked list would be 5 (or `node_2`).

## Linked List Operations

As with most lists, here are a few common operations
that work on linked lists. When working with linked lists,
always think about the following:

1. What nodes (if any) do I need to look at? (e.g. current/previous node, head/tail node, etc.)
2. How do I handle edge cases? (e.g. empty list or list of size 1)
3. Does this operation affect what the head of the list is?

Then you can handle the case where you have a non-empty list.

### Insert

Insertion involves creating a node (using `malloc`) then moving pointers around.
Depending on where you insert, you might have to change the head of your linked list.

```c
// Inserts a new node at the head of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      data: The data to be stored in the new node
//
// Returns:
//      A pointer to the new head of the linked list
struct node *insert_head(struct node *head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}
```

### Delete

```c
// Deletes the head node of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      A pointer to the new head of the linked list
struct node *delete_head(struct node *head) {
    // handle the case when the list is empty
    if (head == NULL) {
        return NULL;
    }
    // keep track of the new head after deletion (could be null)
    struct node *new_head = head->next;
    free(head);
    return new_head;
}
```

### Traversal

```c
// Prints the contents of a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//
// Returns:
//      nothing
void print_list(struct node *head) {
    struct node *curr = head; // make current start at head

    // traverse the list using current,
    // printing current value at each iteration
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}
```

### Search

```c
// Determines existence of a node with the given value in a linked list
//
// Parameters:
//      head: A pointer to the head of the linked list
//      value: The value to check
//
// Returns:
//      1 if value is in the list and 0 otherwise
int list_contains(struct node *head, int value) {
    struct node *curr = head;

    while (curr != NULL) {
        if (curr->data == value) {
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}
```

