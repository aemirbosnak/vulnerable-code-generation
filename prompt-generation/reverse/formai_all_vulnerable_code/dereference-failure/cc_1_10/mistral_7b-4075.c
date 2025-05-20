//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Node *next;
} Node;

Node *createNode(char *name, int age) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, Node *newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%s (%d)\n", current->name, current->age);
        current = current->next;
    }
}

int main() {
    Node *romeo = NULL;
    Node *juliet = NULL;

    romeo = createNode("Romeo", 16);
    addNode(&juliet, romeo);

    juliet = createNode("Juliet", 13);
    addNode(&romeo, &juliet);

    Node *benvolio = createNode("Benvolio", 21);
    addNode(&romeo, benvolio);

    Node *tybalt = createNode("Tybalt", 28);
    addNode(&juliet, tybalt);

    printf("Capulet's Line:\n");
    displayList(juliet);

    printf("\nMontague's Line:\n");
    displayList(romeo);

    free(romeo);
    free(juliet);

    printf("\nMemory is now free. Our star-crossed lovers have met their end.\n");

    return 0;
}