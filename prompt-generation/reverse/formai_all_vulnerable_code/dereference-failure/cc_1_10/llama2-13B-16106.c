//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define MAX_ARRAY_SIZE 10

typedef struct {
    char *name;
    int age;
} person_t;

typedef struct {
    person_t *people;
    int capacity;
    int size;
} party_t;

void init_party(party_t *party) {
    party->people = NULL;
    party->capacity = 0;
    party->size = 0;
}

person_t *add_person(party_t *party, char *name, int age) {
    if (party->size >= party->capacity) {
        party->capacity *= 2;
        party->people = realloc(party->people, party->capacity * sizeof(person_t));
    }
    party->people[party->size] = (person_t) {
        .name = name,
        .age = age
    };
    party->size++;
    return &party->people[party->size - 1];
}

void print_party(party_t *party) {
    printf("Party members:\n");
    for (int i = 0; i < party->size; i++) {
        printf("- %s (%d)\n", party->people[i].name, party->people[i].age);
    }
}

int main() {
    party_t party;
    init_party(&party);

    // Add some party members
    add_person(&party, "Alice", 25);
    add_person(&party, "Bob", 30);
    add_person(&party, "Charlie", 35);

    // Print the party members
    print_party(&party);

    // Reallocate memory to accommodate more party members
    party.capacity *= 2;
    party.people = realloc(party.people, party.capacity * sizeof(person_t));

    // Add some more party members
    add_person(&party, "David", 28);
    add_person(&party, "Eve", 22);

    // Print the party members again
    print_party(&party);

    return 0;
}