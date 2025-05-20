//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

struct node {
    char name[50];
    int age;
    float salary;
    struct node *next;
};

struct node *head = NULL;

void createNode(struct node *node) {
    printf("Enter name: ");
    scanf("%s", node->name);

    printf("Enter age: ");
    scanf("%d", &node->age);

    printf("Enter salary: ");
    scanf("%f", &node->salary);

    node->next = NULL;
}

void insertNode(struct node *node) {
    if (head == NULL) {
        head = node;
        return;
    }

    struct node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = node;
}

void displayNode(struct node *node) {
    printf("Name: %s\n", node->name);
    printf("Age: %d\n", node->age);
    printf("Salary: %f\n", node->salary);
}

int main() {
    struct node *node1, *node2, *node3;

    createNode(node1);
    createNode(node2);
    createNode(node3);

    insertNode(node1);
    insertNode(node2);
    insertNode(node3);

    displayNode(head);

    return 0;
}