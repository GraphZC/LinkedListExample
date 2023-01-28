#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    for (Node *node = head; node != NULL; node = node->next) {
        printf("%d ", node->data);
    }
    printf("\n");
}

void printListRec(Node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printListRec(node->next);
}

int main() {
    Node *node1, *node2, *node3;
    Node *head = NULL;

    node1 = (Node *)malloc(sizeof(Node));    
    node2 = (Node *)malloc(sizeof(Node));
    node3 = (Node *)malloc(sizeof(Node));

    head = node1;

    node1->data = 1;
    node1->next = node2;
    
    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = NULL;

    // printf("%d", node1->next->next->data);

    // printListRec(head);
    printList(head);
}