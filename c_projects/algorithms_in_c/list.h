//
//  list.h
//  chapter03
//
//  Created by linx on 15/10/15.
//

typedef struct node
{
    int item;
    struct node *next;
} node, *link, *Node;

void initNodes(int N);
link newNode(int i);
void freeNode(link x);
void insertNext(link x, link t);
link deleteNext(link x);
link Next(link x);
int Item(link x);
