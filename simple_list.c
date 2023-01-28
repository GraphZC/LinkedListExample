#include <stdio.h>

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

int main() {
    Node node1, node2, node3;
    Node *head = &node1;
    
    node1.data = 1;
    node1.next = &node2;
    
    node2.data = 2;
    node2.next = &node3;

    node3.data = 3;
    node3.next = NULL;

    printList(head);
}