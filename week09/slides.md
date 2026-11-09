---
title: COMP1511 Tutorial - Week 9
---

Announcements
---

- Assignment 2!!! `Due Week 10 Friday 5pm`
- Lab exam next week (again)

<!-- end_slide -->

Memory Leaks
---

A particular bug that arises with the use of `malloc` and its related functions.

This happens when you forget to call `free`.

```c
int main(void) {
    int *x = malloc(sizeof(int));
    *x = 5;
    return 0; // oh no! i forgot to free x!
}
```

<!-- pause -->

```c
int main(void) {
    struct node *head = create_node(3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    return 0; // oh no! i forgot to free my entire list!
}
```

<!-- end_slide -->

Memory Leaks, cont'd.
---

```c
int main(void) {
    struct node *head = create_node(3);
    head = insert_head(head, 2);
    head = insert_head(head, 1);
    free(head);
    return 0; // oh no! i forgot to free the rest of my list!!!
}
```

How can you free a list of any length?

