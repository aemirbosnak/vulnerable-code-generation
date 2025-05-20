//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float mass;
    struct Element *next;
} Element;

void display_table(Element *head) {
    printf("--------------------------------------------------------\n");
    printf("  Element Name | Atomic Number | Mass |\n");
    printf("--------------------------------------------------------\n");
    while (head) {
        printf("  %-20s | %d | %.2f |\n", head->name, head->atomic_number, head->mass);
        head = head->next;
    }
    printf("--------------------------------------------------------\n");
}

int main() {
    Element *head = NULL;
    Element *tail = NULL;

    // Create a few elements
    Element *element1 = malloc(sizeof(Element));
    strcpy(element1->name, "Hydrogen");
    element1->atomic_number = 1;
    element1->mass = 1.00784;

    Element *element2 = malloc(sizeof(Element));
    strcpy(element2->name, "Helium");
    element2->atomic_number = 2;
    element2->mass = 4.002602;

    Element *element3 = malloc(sizeof(Element));
    strcpy(element3->name, "Lithium");
    element3->atomic_number = 3;
    element3->mass = 6.940922;

    // Add the elements to the table
    if (head == NULL) {
        head = element1;
        tail = element1;
    } else {
        tail->next = element1;
        tail = element1;
    }

    display_table(head);

    return 0;
}