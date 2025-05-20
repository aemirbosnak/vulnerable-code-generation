//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
    int id;
    char *name;
    char *occupation;
    char *address;
} person;

// Create a new person
person *new_person(int id, char *name, char *occupation, char *address) {
    person *p = malloc(sizeof(person));
    p->id = id;
    p->name = strdup(name);
    p->occupation = strdup(occupation);
    p->address = strdup(address);
    return p;
}

// Free a person
void free_person(person *p) {
    free(p->name);
    free(p->occupation);
    free(p->address);
    free(p);
}

// Print a person
void print_person(person *p) {
    printf("%d %s %s %s\n", p->id, p->name, p->occupation, p->address);
}

// Main function
int main() {
    // Create a database of suspects
    person *suspects[] = {
        new_person(1, "John Smith", "Doctor", "221B Baker Street"),
        new_person(2, "Mary Jones", "Nurse", "10 Downing Street"),
        new_person(3, "Charles Brown", "Lawyer", "The Strand"),
        new_person(4, "Sarah Miller", "Teacher", "Piccadilly Circus")
    };

    // Print the suspects
    for (int i = 0; i < 4; i++) {
        print_person(suspects[i]);
    }

    // Free the suspects
    for (int i = 0; i < 4; i++) {
        free_person(suspects[i]);
    }

    return 0;
}