---
title: COMP1511 Tutorial - Week 8
---

Announcements
---

- Assignment 2 is out !!!
- Lab exam today!

<!-- end_slide -->

Memory Lifespan
---

We have been implicitly using the *stack* when creating our variables.
Currently, we run into the limitation where data cannot live outside a function.

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

How can we make this work?

<!-- end_slide -->

Malloc
---

We can allocate memory to the *heap*.

```c
// function prototype as declared in <stdlib.h>
void *malloc(size_t size);
```

What is the input and output of `malloc`?

<!-- pause -->

- Takes in a `size_t` as input (OS dependent, typically `unsigned int` or `unsigned long`)
- Outputs a `void *` (void pointer)
- A void pointer is still a pointer (but we don't know what it is pointing to)

```c
// Example: allocating memory (on the heap) for an integer
int *x = malloc(sizeof(int));
int *y = malloc(4); // i mean, this also works but just use sizeof
*x = 5; // you can use it like a normal pointer
```

Note that we explicitly cast the void pointer (`void *`) that is returned by malloc
into an integer pointer (`int *`), because we as the programmers know what we are
going to use the allocated memory for.

<!-- end_slide -->

Malloc, cont'd.
---

How to malloc a `double`?

<!-- pause -->

```c
double *number = malloc(sizeof(double));
free(number);
```

How to malloc a `char`?

<!-- pause -->

```c
char *c = malloc(sizeof(char));
free(c);
```

How to malloc an array of 10 `char`s?

<!-- pause -->

```c
char *arr = malloc(10 * sizeof(char));
free(arr);
```

<!-- end_slide -->

Malloc, cont'd.
---

How to malloc the following struct:

```c
struct my_struct {
    int number;
    char letter;
    double another_number;
}
```

<!-- pause -->

```c
struct my_struct *thing = malloc(sizeof(struct my_struct));
thing->number = 1;
thing->letter = 'c';
thing->another_number = 6.7;
free(thing);
```

Why are we using a function called `free`?

<!-- end_slide -->

Don't forget free!
---

Using `malloc` allows us to allocate data to memory that will persist throughout the lifetime of a program.
With this, the responsibility falls on you as the programmer to free the memory after its use.

```c
// function prototype as declared in <stdlib.h>
void free(void *_Nullable ptr);
```

- `free` deallocates memory back to the heap to be used elsewhere.
- takes in a `void *`, which is just any kind of pointer. (can be `NULL`)

```c
int *x = malloc(sizeof(int));
*x = 1;
free(x); // this releases the memory back to the computer
free(x); // this is undefined behaviour since we already called free
free(NULL); // this is fine, does nothing

int y = 2;
free(&y); // this is undefined behaviour also since
          // the memory was not allocated on the heap
```

<!-- end_slide -->

<!-- jump_to_middle -->

Linked List
---

<!-- end_slide -->

Linked List
---

Another way to store a collection of (the same) data.

<!-- pause -->

> Wait, what's wrong with arrays?

<!-- pause -->

Let's say I wanted to make a playlist on spotify and queue up songs.

<!-- pause -->
With arrays, you might do:

```c
struct song playlist[MAX];
```
<!-- pause -->

where `MAX` is some constant. However, note that this is highly inefficient
(using more memory than needed) for playlists with very few songs,
and it is impossible for me to make a playlist with more than `MAX + 1` songs.

What if I wanted a list that could grow and shrink in size as needed?

<!-- end_slide -->

Linked List
---

Solution: Create each element of the list individually and connect them together.

```c
struct node {
    int data;           // this can be changed to be whatever you need to store
    struct node *next;  // this is the important part
}
```

The `next` field of the node allows us to access the succeeding element in the list.
That is, if we have access to the `n`th element in the list, we have access to the `n+1`th element.

```c
struct node *new_node = malloc(sizeof(struct node));
new_node->data = 5;
new_node->next = NULL;

struct node *next_node = malloc(sizeof(struct node));
next_node->data = 6;
next_node->next = NULL;

new_node->next = next_node; // this links 5 -> 6
```

> Challenge: Can you try doing this without using the arrow (`->`) operator?

<!-- end_slide -->

<!-- jump_to_middle -->

Linked List Operations
---

<!-- end_slide -->

The Anatomy of a Linked List Operation
---

```c
struct node *operation(struct node *head); // e.g. delete_head
struct node *op_with_args(struct node *head, int arg1, char arg2, double arg3, ...);
// e.g. insert_at_position
```

1. All operations require giving the linked list itself (obviously), we typically provide the `head`
   (since we can access all elements via the head)
2. We also usually want to return the updated linked list (if we did something to it).
   That is, we provide the new head of the linked list (if the head didn't change, return the old head)
3. Sometimes you want other arguments aside from the linked list, e.g. inserting a new element or searching for an element

Alternatively,
```c
int get_info_about_list(struct node *head); // e.g. list_length
void do_something_with_list(struct node *head); // e.g. print_list
```

<!-- end_slide -->

Common Linked List Operations
---

```c
// INSERT
struct node *insert_at_head(struct node *head, int data);
struct node *insert_at_tail(struct node *head, int data);
struct node *insert_at_position(struct node *head, int data, int pos);

// SEARCH
// returns the pointer to the node containing data,
// or NULL if not found
struct node *find(struct node *head, int data);
int list_contains(struct node *head, int data); // returns true or false (1 or 0)

// DELETE
struct node *delete_head(struct node *head);
struct node *delete_tail(struct node *head); // still need to return the new head. why?
struct node *delete_at_position(struct node *head, int pos);
struct node *delete_first(struct node *head, int data);
```

You will be implementing (most) of these in the problem sets!

