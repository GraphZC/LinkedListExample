#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
} Node;

int main() {
    Node *node1 = (Node *)malloc(sizeof(Node));
    node1->data = 5;

    printf("%d", (*node1).data);
}