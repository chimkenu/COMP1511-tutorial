#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *to_list(char *arr[], int size);
void free_list(struct node *head);
int count_unique(struct node *head);

// helper function i made:
int count_value(struct node *head, int value);

int main(int argc, char *argv[]) {
    struct node *list = to_list(&argv[1], argc - 1);
    printf("%d\n", count_unique(list));
    free_list(list);
    return 0;
}

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

// counts the number of elements in the
// list that equal the given value
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

