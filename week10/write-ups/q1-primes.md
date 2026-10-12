# Q1 - Searching for Primes

> Given a list of strictly positive integers, return the first prime number. If the list does not contain any primes, return -1.

A prime number is defined to be a positive integer that is divisible only by 1 and itself.
We do not count 1 as a prime number.

This question can use either a 1D array or a linked list.
It is recommended to write a solution for both data structures.

Below are the function prototypes to implement:

```c
// 1D ARRAY VERSION
int find_prime_array(int arr[], int size);

// LINKED LIST VERSION
int find_prime_list(struct node *head);
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

    printf("find_prime_array: %d\n", find_prime_array(arr, size));
    printf("find_prime_list: %d\n", find_prime_list(list));

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

0. Count the number of prime numbers in a given list.
1. Find the last prime in the list (or more generally, find the *n*th prime in the list).
2. Print "All Prime" if there are only prime numbers in the list.
3. Find a composite number in the list that is divisible by all the primes in the same list.

Variations 2 and 3 need more than a small modification in the code, with 3 having a noticable jump in difficulty.

> Email me if you have any questions about these!

## Solution

[*click me for the full solution*](../sols/q1-primes.c)

The solution to this involves two important parts.

### Linear search

The solution invloves a [linear search](https://en.wikipedia.org/wiki/Linear_search), which
is a fancy way of saying we are going to check each element of the array one by one in order.
Recall how to print all the elements in an array:

```c
int find_prime_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
    return -1;
}
```

This is *almost* a linear search, you just need to add an if statement to choose a particular element.
We specifically want to choose *prime* elements. For now, I propose we use a function called `is_prime`,
that can tell us whether a given number is prime.

```c
int find_prime_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i]) {
            printf("%d\n", arr[i]);
        }
    }
    return -1;
}
```

The code above will print out all prime elements in the array.
If we wanted to print out at most once, try to exit the loop after finding the first instance.
```c
int find_prime_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i]) {
            return arr[i]; // this return here will exit the loop/function early,
                           // right after finding the first instance of a prime.
        }
    }
    return -1;
}
```

Since the problem is asking us to return the prime number rather than print it, I also removed the printf statement.

### Primality test

The code above will work if we have this magic function `is_prime`.
It is typical to do this; using a function *before* you implement it, so long as you know what it should do.
In this case it is clear: `is_prime` is given a number, and outputs a true value if the given number is prime.
This creates the following function signature:

```c
int is_prime(int n);
```

The return value here is either 1 (true) or 0 (false).
Now the task is implementing a [primality test](https://en.wikipedia.org/wiki/Primality_test):
a way to check if a number is prime.

Here it is useful (necessary) to know the definition of a prime number.
We know that a number `n` can only be divisible by numbers that are smaller
than `n`, and hence we only need to check numbers from the range `(1, n)`(exclusive)
and see if there exists a number in that range that divides `n`.

That is, if we can find a number in from 1 to `n` that divides `n`,
then we know `n` is not prime. This statement sounds [linear search](#linear-search)-able to me.
We can literally check each number starting from 2 and count up and see if that number divides `n`.

Now we just need to remember how to check if a number divides another number.
Divisibility can be checked using the modulo `%` operator.

```c
int is_prime(int n) {
    // note that this for loop excludes 1 and n
    // and only checks integers between those numbers.
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0; // i found a number that is not 1 or n
                      // that can divide n, hence n is not prime.
        }
    }
    return 1; // i looked at all the integers between 1 and n
              // and none divide n, so n is prime.
}
```

This completes the solution. See if you can write a faster primality test.

