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

