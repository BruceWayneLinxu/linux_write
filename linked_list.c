/***************************************************************************************************************************************
 *
 * Project Data Structures (C Version)
 * Copyright (C) 2017, linxu, <charliebrownlinxu@yahoo.com>, et al.
 *
***************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int val_type;

struct node {
    val_type data;
    struct node *next;
};


int insert_node(struct node **head, val_type data) {
    if (!*head) {
        return -1;
    }

    struct node *cur_node = NULL;
    cur_node = (struct node *)malloc(sizeof(*cur_node));
    if (!cur_node) {
        return -1;
    }
    cur_node->data = data;
    cur_node->next = NULL;
    (*head)->next = cur_node;
    (*head) = (*head)->next;
    return 0;
}

int print_list(const struct node *head) {
    if (!head) {
        return -1;
    }
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
    return 0;
}

int free_list(struct node **head) {
    if (!*head) {
        return -1;
    }

    struct node *cur = NULL;
    while (*head != NULL) {
        cur = *head;
        *head = (*head)->next;
        free(cur);
        cur = NULL;
    }
    return 0;
}

// wrong
int free_list_err(struct node *head) {
    if (!head) {
        return -1;
    }

    struct node *cur = NULL;
    while (head != NULL) {
        cur = head;
        head = head->next;
        free(cur);
        cur = NULL;
    }
    return 0;
}

// https://www.quora.com/How-do-you-reverse-a-linked-list
int reverse_list(struct node **head) {
    // **head, so you can update it;
    if (!*head)                                  // validate input
        return 0;

    struct node *tmp = *head;
    struct node *prev = NULL;
    while (tmp) {
        struct node *next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    *head = prev;                                // update the head;
    return 0;
}

int main(int argc, char *argv[]) {
    struct node *cur = NULL;
    struct node *head = NULL;

    head = (struct node*)malloc(sizeof(*head));
    if (!head) {
        return -1;
    }
    head->data = 5;
    head->next = NULL;
    cur = head;
    for (size_t loop = 1; loop <= 5; ++loop)
        insert_node(&cur, loop * loop);

    print_list(head);

    reverse_list(&head);

    print_list(head);

    free_list(&head);

    printf("linked list!\n");
    return 0;
}
