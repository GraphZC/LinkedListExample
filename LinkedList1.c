#include <stdlib.h>
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

Node *createNode(int num) {
    // Allocate memory
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = num;
    node->next = NULL;
    return node;
} 

void addNode(Node **head, Node **tail, int num) {
    Node *newNode = createNode(num);

    // check if node is head
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }

    // node isn't head
    (*tail)->next = newNode;
    *tail = newNode;
}

void deleteNode(Node **head, int delete_num) {
    Node *target = NULL;
    Node *prev = NULL;
    // loop to find delete node
    for (target = *head; target != NULL; prev = target, target = target->next) {
        if (target->data == delete_num)
            break;
    }

    // not found deleted node
    if (target == NULL)
        return;

    // deleted node is head
    if (target == *head) {
        *head = target->next;
        free(target);
        return;
    }
    // deleted node isn't head
    prev->next = target->next;
    free(target);
}

int main() {
    Node *head = NULL, *tail = NULL;
    addNode(&head, &tail, 5);
    addNode(&head, &tail, 10);
    addNode(&head, &tail, 15);
    addNode(&head, &tail, 25);
    deleteNode(&head, 25);
    printList(head);
}