# Q3 - Unique Numbers

> **Q3.** Find the number of unique numbers in a given list.

A unique number is a number in the list that appears exactly once.

This question uses a linked list. (though you can make use of an array as well)

Below is the function prototype to implement:

```c
int count_unique(struct node head);
```

and a `struct node` is given by

```c
struct node {
    int value;
    struct node *next;
};
```

## Example Usage

Assuming you name the file `q3.c`, you should expect to see:

```
$ dcc q3.c -o q3
$ ./q2 1 2 3 4 5
5
$ ./q2 1 3 3 5 5
1
$ ./q2 2 2 2 2
0
$ ./q2
0
```

The first input is a list of the numbers 1 to 5, which are
all unique and thus the program outputs 5.

The next input is `1 3 3 5 5`, where we see 3 and 5 repeated.
The program should output 1 here, since 1 is the only number that is not repeated.

The next input is `2 2 2 2`, all 2 and thus there are no unique numbers.

Finally, an empty list has no unique numbers and should thus output 0 as well.

## Starter Code

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *to_list(char *arr[], int size);
void free_list(struct node *head);
int count_unique(struct node *head);

int main(int argc, char *argv[]) {
    struct node *list = to_list(&argv[1], argc - 1);
    printf("%d\n", count_unique(list));
    free_list(list);
    return 0;
}

int count_unique(struct node *head) {
    // TODO: Write your solution here!
    return -1;
}

// ignore these helper functions...
struct node *to_list(char *arr[], int size) {
    struct node *head = NULL;
    struct node *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = atoi(arr[i]);
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
        }
        tail = new_node;
    }
    return head;
}

void free_list(struct node *head) {
    while (head != NULL) {
        struct node *del = head;
        head = head->next;
        free(del);
    }
}
```

## Variations

To test your understanding, see if you can modify
your existing code to do the following:

1. Find the max, min, and mean unique value, if it exists.
2. Assuming the list is sorted, find the median unique value.
3. Now assume the list is not necessarily sorted for variation 2.

The last variation is quite the jump in difficulty
(i am basically asking you to [sort a linked list](https://www.geeksforgeeks.org/dsa/sorting-a-singly-linked-list))
but it is actually doable with the content learned in week 8 and 9.

## Solution

[*click me for the full solution*](../sols/q3-unique.c)

The solution I came up with for this is to first make a function
that checks how many nodes in the list contain some value.
The idea is to see if any count is exactly 1, which would
imply that this particular value is unique in the list.
I thus created the following helper function:

```c
int count_value(struct node *head, int value) {
    int count = 0;
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->value == value) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}
```

This is a linear search on the linked list, and count keeps
track of how many nodes contain the value in question.

In the actual `count_unique` function, I made another linear search.
This time, I checked if the current node's value is unique (by checking
the return value of the helper function above).

```c
int count_unique(struct node *head) {
    int count = 0;
    struct node *curr = head;
    while (curr != NULL) {
        if (count_value(head, curr->value) == 1) {
            count++;
        }
        curr = curr->next;
    }
    return count;
}
```

Which is notably very similar to the helper function.
In fact, the only difference is the condition for counting. 
This completes the solution for this question.
See if you can modify the code to solve the variations.

