//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct Element {
    char name[MAX_LEN];
    int age;
    struct Element *next;
} Element;

Element *head = NULL;

void addElement(Element *head, const char *name, int age) {
    Element *newNode = (Element *) malloc(sizeof(Element));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = head;
    head = newNode;
}

void printList(Element *head) {
    Element *current = head;
    while (current != NULL) {
        printf("%s is %d years old.\n", current->name, current->age);
        current = current->next;
    }
}

int findElement(Element *head, const char *name) {
    Element *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->age;
        }
        current = current->next;
    }
    return -1;
}

int main() {
    addElement(head, "Watson", 35);
    addElement(head, "Holmes", 45);
    addElement(head, "Moriarty", 55);

    printList(head);

    printf("Age of Moriarty: %d\n", findElement(head, "Moriarty"));

    return 0;
}