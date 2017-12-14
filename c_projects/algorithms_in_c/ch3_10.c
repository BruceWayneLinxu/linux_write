//
//  ch3_10.c
//  chapter03
//
//  Created by linx on 15/10/15.
//



#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
} node, *link;


link add_node(int value);
link reverse_link(link head);
void release_link(link head);

int main(int argc, char *argv[])
{
    int count = atoi(argv[1]);
    link temp = NULL;
    link new_node = NULL;
    link head = (node*)malloc(sizeof(node));

    head->next = NULL;
    head->item = -1;

    temp = head;

    for (int loop = 0; loop < count; ++loop)
    {
        new_node = add_node(loop);
        temp->next = new_node;
        temp = temp->next;
    }

    link reversed_link = reverse_link(head);
    release_link(reversed_link);

    return 0;
}

/**
 *  generate a node
 *
 *  @param value assign value to the new node's item
 *
 *  @return a new node
 */
link add_node(int value)
{
    link new_node = (link)malloc(sizeof(*new_node));
    new_node->item = value;
    new_node->next = NULL;
    return new_node;
}


/**
 *  release link
 *
 *  @param head
 */
void release_link(link head)
{
    while(head)
    {
        node *destoried = head;
        printf("current node value is %d\n", destoried->item);
        head = head->next;
        free(destoried);
        destoried = NULL;
    }
}


/**
 *  reverse the link
 *
 *  @param head
 *
 *  @return reversed link
 */
link reverse_link(link head)
{
    link t, y = head, r = NULL;
    while(y != NULL)
    {
        t = y->next;

        y->next = r;
        r = y;

        y = t;
    }
    return r;
}
