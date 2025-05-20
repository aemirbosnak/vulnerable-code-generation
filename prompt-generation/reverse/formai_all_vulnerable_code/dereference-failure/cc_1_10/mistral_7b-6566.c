//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char name[50];
    int age;
    struct Element *next;
} Element;

Element *createElement(char name[], int age) {
    Element *newElement = (Element *) malloc(sizeof(Element));
    strcpy(newElement->name, name);
    newElement->age = age;
    newElement->next = NULL;
    return newElement;
}

void appendElement(Element **head, Element *newElement) {
    if (*head == NULL) {
        *head = newElement;
        return;
    }
    Element *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newElement;
}

void printList(Element *head) {
    Element *current = head;
    printf("--- SHERLOCK HOLMES'S --- \n");
    printf("--- LONDON CRIME LINKED LIST ---\n");
    printf("------------------------------- \n");
    while (current != NULL) {
        printf("Name : %s \n", current->name);
        printf("Age  : %d \n", current->age);
        current = current->next;
    }
}

int main() {
    Element *head = NULL;

    appendElement(&head, createElement("John Watson", 27));
    appendElement(&head, createElement("Moriarty", 45));
    appendElement(&head, createElement("Irene Adler", 32));
    appendElement(&head, createElement("James Moriarty's henchman", 30));

    printList(head);

    return 0;
}