# COMP1511 Tutorial - Week 9

## Memory Leaks

A particular bug that arises with the use of `malloc` and its related functions.
This happens when you forget to call `free`. For example:

```c
int main(void) {
    int *x = malloc(sizeof(int));
    *x = 5;
    return 0; // oh no! i forgot to free x!
}
```

or, more commonly:

```c
int main(void) {
    struct node *head = create_node(3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    return 0; // oh no! i forgot to free my entire list!
}
```

More likely, you may have called `free` for some but not all of the memory allocated with `malloc`.
For example:

```c
int main(void) {
    struct node *head = create_node(3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    free(head);
    return 0; // oh no! i forgot to free the rest of my list!!!
}
```

In the case above, the remaining two nodes (2 and 3) were not `free`d.

## Freeing lists

Deleting elements from a linked list requires you to free the deleted memory.
You can do this operation until the list is empty. For example:

```c
struct node *delete_head(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct node *new_head = head->next;
    free(head);
    return new_head;
}

void free_list(struct node *head) {
    while (head != NULL) {
        head = delete_head(head);
    }
}
```

The function `free_list` runs `delete_head` until the head is `NULL`.
This frees all the memory in the linked list, avoiding any memory leaks.

