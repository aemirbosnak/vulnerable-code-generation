//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value; 
    char* name; 
    struct Node *next;
};

void printNode(struct Node *root) {
    printf("The value is %d and the name is %s\n", root->value, root->name);
}

void addNode(struct Node *head, struct Node *newNode) {
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = newNode;
}

int main(){
    struct Node *head = malloc(sizeof(struct Node));
    head->value=2;
    head->name="Head";
    head->next=NULL;

    struct Node *node1 = malloc(sizeof(struct Node));
    node1->value=3;
    node1->name="Node1";
    node1->next=NULL;

    struct Node *node2 = malloc(sizeof(struct Node));
    node2->value=4;
    node2->name="Node2";
    node2->next=NULL;

    addNode(head, node1);
    addNode(head, node2);

    struct Node *current = head;
    while (current != NULL) {
        printNode(current);
        current = current->next;
    }

    free(head);
    free(node1);
    free(node2);

    return 0;
}