//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float mass;
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, float mass) {
    Element* element = malloc(sizeof(Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->mass = mass;
    element->next = NULL;

    return element;
}

void printElement(Element* element) {
    printf("%s (%d) - Mass: %.2f\n", element->name, element->atomic_number, element->mass);
}

Element* findElement(Element* head, int atomic_number) {
    Element* current = head;

    while (current) {
        if (current->atomic_number == atomic_number) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

int main() {
    Element* head = createElement("Hydrogen", 1, 1.0);
    Element* second = createElement("Helium", 2, 4.0);
    Element* third = createElement("Lithium", 3, 6.940);

    head->next = second;
    second->next = third;

    printElement(findElement(head, 2));

    return 0;
}