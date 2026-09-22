# Q1 - Searching for Primes

> Given a list of strictly positive integers, return the first prime number. If the list does not contain any primes, return -1.

This question can use either a 1D array or a linked list.
It is recommended to write a solution for both data structures.

Below are the function prototypes to implement:

```c
// 1D ARRAY VERSION
int find_prime(int arr[], int size);

// LINKED LIST VERSION
int find_prime(struct node *head);
```

## Example Usage

Assuming you name the file `q1.c`, you should expect to see:

```
$ dcc q1.c -o q1
$ ./q1 1 2 3 4 5 6 7 8 9
find_prime array: 2
find_prime list: 2
$ ./q1 4 8 12 16 20 24
find_prime array: -1
find_prime list: -1
$ ./q1 6 9 10 11
find_prime array: 11
find_prime list: 11
$ ./q1 49 600 5601 31 56 169 11 289
find_prime array: 31
find_prime list: 31
```

Note that find_prime for both arrays and linked lists should always agree since they are supposed to do the same thing.

The first test, `./q1 1 2 3 4 5 6 7 8 9`, creates a list with the integers from 1 to 9 inclusive and in order.
Note that the first prime number that appears in this list is 2.

For `./q1 4 8 12 16 20 24`, we have a list with all composite numbers (not prime).
Hence, we expect to see that both functions return `-1` as there are no prime numbers to find.

Consider making your own lists and checking if your function agrees with your calculations by hand.

## Starter Code

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

int find_prime_array(int arr[], int size);
int find_prime_list(struct node *head);
int *to_array(char *argv[], int size);
struct node *to_list(int arr[], int size);
void free_list(struct node *head);

int main(int argc, char *argv[]) {
    int size = argc - 1;
    int *arr = to_array(&argv[1], size);
    struct node *list = to_list(arr, size);

    printf("find_prime array: %d\n", find_prime_array(arr, size));
    printf("find_prime list: %d\n", find_prime_list(list));

    free(arr);
    free_list(list);
    return 0;
}

int find_prime_array(int arr[], int size) {
    // TODO: Write a solution for an array of integers.
    return -1;
}

int find_prime_list(struct node *head) {
    // TODO: Write a solution for an integer linked list.
    return -1;
}

// ignore these helper functions...
int *to_array(char *argv[], int size) {
    int *arr = malloc(sizeof(int) * size);
    for (int i; i < size; i++) {
        arr[i] = atoi(argv[i]);
    }
    return arr;
}

struct node *to_list(int arr[], int size) {
    struct node *head = NULL;
    struct node *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = arr[i];
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

To test your understanding, see if you can modify your existing code to do the following:

1. Find the last prime in the list (or more generally, find the *n*th prime in the list).
2. Print "All Prime" if there are only prime numbers in the list.
3. Find a composite number in the list that is divisible by all the primes in the same list.

Variations 2 and 3 need more than a small modification in the code, with 3 having a noticable jump in difficulty.

> Email me if you have any questions about these!

