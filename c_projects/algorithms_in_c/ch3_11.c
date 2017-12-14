
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_link(link x);
void release_link(link x);

int main(int argc, char *argv[])
{
    struct node heada, headb;
    link t, u, x, a = &heada, b;
    int i = 0;
    int N = atoi(argv[1]);
    for (i = 0, t = a; i < N; i++)
    {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000;
    }
    print_link(a->next);

    b = &headb; b->next = NULL;
    for (t = a->next; t != NULL; t = u)
    {
        u = t->next;
        for (x = b; x->next != NULL; x = x->next)
        {
          if (x->next->item > t->item) break;
        }
        t->next = x->next;
        x->next = t;
    }
    print_link(b->next);

    release_link(b->next);
    return 0;
}


void print_link(link x)
{
    while (x)
    {
        printf("%d\t", x->item);
        x = x->next;
    }
    printf("\n\n");
}


void release_link(link x)
{
    link temp = NULL;
    while (x)
    {
        temp = x;
        x = x->next;
        printf("released node:%d\n", temp->item);
        free(temp);
        temp = NULL;
    }
    printf("\n");
}
