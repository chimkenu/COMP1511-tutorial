# Q5 - Stalin Sort

> **Q5.** Given a linked list of integers, delete elements that are out of order.

In this case we are considering **ascending** order.
Given any linked list of integers, delete elements of the linked
list that are not in ascending order until the list is ordered.

In particular, you should delete all nodes
whose value is smaller than the previous node.

This algorithm is a joke 'sorting' algorithm called [Stalin sort](https://www.google.com/search?q=stalin+sort).
You can search this algorithm for more information if the above explanation is not enough.

You are to implement the function:

```c
struct node *delete_unordered(struct node *head);
```

Which takes in the head of a linked list and should return
the head of the updated linked list.

Since you're deleting elements from a linked list,
make sure you do not have any memory leaks.
Compile or test with a memory leak checker like [valgrind](https://en.wikipedia.org/wiki/Valgrind)

## Example Usage

Assuming you name the file `q5.c`, you should expect to see:

```
$ dcc --leak-check q5.c -o q5
$ ./q5 1 2 3 4 5
1 -> 2 -> 3 -> 4 -> 5 -> X
$ ./q5 5 4 3 2 1
5 -> X
$ ./q5 3 1 2 5 4
3 -> 5 -> X
$ ./q5
X
```

The first example is a list of numbers from 1 to 5, and since this is
already sorted in ascending order, the function will not delete any nodes.

The second example is the same set of numbers, but in descending order.
Since every number except 5 is less than its previous, then all nodes
will be deleted except 5 (the first one).

The third example is the list `3 -> 1 -> 2 -> 5 -> 4 -> X` which has node with
values 1, 2, and 4 out of order (since they come after numbers that are greater than them).
The resulting list must delete those numbers, resulting in `3 -> 5 -> X`

The final example is an empty list. Your function should be able to handle this,
and the resulting list should remain empty.

## Starter Code

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *delete_unordered(struct node *head);
struct node *to_list(char *arr[], int size);
void print_list(struct node *head);
void free_list(struct node *head);

int main(int argc, char *argv[]) {
    struct node *list = to_list(argv + 1, argc - 1);
    print_list(delete_unordered(list));
    free_list(list);
    return 0;
}

struct node *delete_unordered(struct node *head) {
    // TODO: Write your solution here!
    return NULL;
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

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("X\n");
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

1. 
2. What if you wanted to get a sorted list in the *minimum* number of deletions?
    - e.g. `1 -> 5 -> 2 -> 3 -> 4 -> X` results in `1 -> 5 -> X` on stalin sort, but the minimum deletions solution is `1 -> 2 -> 3 -> 4 -> X` (delete only 5)

2 is interesting. I think it's a rewording of [longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence),
and so I don't think its a reasonable question to ask in an exam.

## Solution

[*click me for the full solution*](../sols/q5-sort.c)

Here I want to traverse the linked list and remove any cases where
there are nodes 'out of order'. Since we want a list in ascending order,
I wish to delete any nodes whose next node is smaller than it.

In this case I will be using some kind of linked list traversal:

```c
struct node *curr = head;
while (curr != NULL) {
    // something something
    curr = curr->next;
}
return head;
```

I want to compare two nodes together, and so only knowing that
the current node is not null is not enough. I want to be able
to access at least two nodes at a time, and so I add:

```c
struct node *curr = head;
while (curr != NULL && curr->next != NULL) {
    // something something
    curr = curr->next;
}
return head;
```

By modifying the condition on the while loop, I am able to
access both curr and curr->next safely. I can now check the values
of these two nodes:

```c
if (curr->value ? curr->next->value) {
```

What I want is to delete the node whos previous is smaller.
In this case, I only have access to the previous node of curr->next (that is, curr)
and so the node I might be deleting is curr->next.

The condition I wish to check then is:

```c
if (curr->value > curr->next->value) {
    // delete curr->next
}
```

Because if the condition is true, then I have found that I have a larger number
followed by a smaller number, implying the list is not in ascending order. Thus
I must delete the curr->next node.

The list could look like this:

```
head -> something... -> curr -> curr->next -> curr->next->next -> more stuff -> NULL
```

Note that it's possible for `curr->next->next` to be NULL. It doesn't matter in our case.
We thus need to delete curr->next and connect the pointer of curr to curr->next->next,
and end up with:

```
head -> something... -> curr -> curr->next->next -> more stuff -> NULL
                            ^ i deleted curr->next
```

if the diagram doesnt help (my bad) then the code below does the deletion:

```c
if (curr->value > curr->next->value) {
    struct node *delete = curr->next; // i need to save the node to delete later
    curr->next = curr->next->next;    // connect curr with curr->next->next
    free(delete);                     // actually delete curr->next
}
```

So the code should look something like this:

```c
struct node *curr = head;
while (curr != NULL && curr->next != NULL) {
    if (curr->value > curr->next->value) {
        struct node *delete = curr->next;
        curr->next = curr->next->next;
        free(delete);
    }
    curr = curr->next;
}
return head;
```

Try this with some inputs. Particularly when there are consecutive values that are out of order (e.g. `4 1 2 3`).

You might notice that the code above only deletes the first instance of an out of order case, and moves on.
We only want to move on when the two values that we are looking at are indeed in ascending order, and thus we need to
move the `curr = curr->next` line inside an else case. That is, we move to the next node once we are sure that
`curr` and `curr->next` are in order. Thus the final solution is as follows:

```c
struct node *curr = head;
while (curr != NULL && curr->next != NULL) {
    if (curr->value > curr->next->value) {
        struct node *delete = curr->next;
        curr->next = curr->next->next;
        free(delete);
    } else {
        curr = curr->next;
    }
}
return head;
```

