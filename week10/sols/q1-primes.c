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

// NEW HELPER FUNCTION I MADE:
int is_prime(int n);

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
    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i])) {
            // exit early since we only need to find the first prime
            return arr[i];
        }
    }
    // once we reach here, we have checked all numbers in the list
    // and none are prime, thus we return -1
    return -1;
}

int find_prime_list(struct node *head) {
    // we dont need curr here since we can traverse with head without losing any info
    while (head != NULL) {
        if (is_prime(head->value)) {
            return head->value;
        }
        head = head->next;
    }
    return -1;
}

int is_prime(int n) {
    if (n == 1) {
        // 1 is not prime (nor composite)
        return 0;
    }

    // we want to check all the numbers between 2 and n-1 and see if they divide n
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            // n is divisible by i (an integer smaller than n greater than 1)
            // hence it is not prime
            return 0;
        }
    }
    // once we reach here, we have checked all numbers from 2 to n-1 and none of them divide n
    // thus n is prime
    return 1;
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
