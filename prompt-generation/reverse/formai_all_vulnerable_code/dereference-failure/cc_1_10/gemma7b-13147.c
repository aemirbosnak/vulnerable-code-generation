//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 118

typedef struct Atom {
    char name[20];
    int atomic_number;
    double mass;
    struct Atom* next;
} Atom;

void print_table(Atom* head) {
    while (head) {
        printf("%-20s | %4d | %.2lf\n", head->name, head->atomic_number, head->mass);
        head = head->next;
    }
}

int main() {
    Atom* head = NULL;
    Atom* current = NULL;

    // Create the first atom
    head = malloc(sizeof(Atom));
    current = head;
    strcpy(head->name, "Hydrogen");
    head->atomic_number = 1;
    head->mass = 1.008;

    // Create the remaining atoms
    current->next = malloc(sizeof(Atom));
    current = current->next;
    strcpy(current->name, "Helium");
    current->atomic_number = 2;
    current->mass = 4.002602;

    current->next = malloc(sizeof(Atom));
    current = current->next;
    strcpy(current->name, "Lithium");
    current->atomic_number = 3;
    current->mass = 6.940922;

    current->next = malloc(sizeof(Atom));
    current = current->next;
    strcpy(current->name, "Sodium");
    current->atomic_number = 11;
    current->mass = 22.989769;

    print_table(head);

    return 0;
}