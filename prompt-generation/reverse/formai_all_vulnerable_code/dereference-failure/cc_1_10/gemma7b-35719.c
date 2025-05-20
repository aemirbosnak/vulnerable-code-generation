//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    struct Element *next;
} Element;

void create_element(Element **head) {
    *head = malloc(sizeof(Element));
    (*head)->name[0] = '\0';
    (*head)->atomic_number = 0;
    (*head)->atomic_mass = 0.0f;
    (*head)->next = NULL;
}

void insert_element(Element **head, char *name, int atomic_number, float atomic_mass) {
    Element *new_element = malloc(sizeof(Element));
    new_element->name[0] = '\0';
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    new_element->next = NULL;

    if (*head == NULL) {
        *head = new_element;
    } else {
        (*head)->next = new_element;
        *head = new_element;
    }
}

void print_elements(Element *head) {
    while (head) {
        printf("%s (%d) - %.2f\n", head->name, head->atomic_number, head->atomic_mass);
        head = head->next;
    }
}

int main() {
    Element *head = NULL;
    create_element(&head);
    insert_element(&head, "Hydrogen", 1, 1.0f);
    insert_element(&head, "Helium", 2, 4.0f);
    insert_element(&head, "Lithium", 3, 6.940f);
    print_elements(head);

    return 0;
}