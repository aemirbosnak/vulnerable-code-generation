//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 100

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
    party->capacity = MAX_ARRAY_SIZE;
    party->size = 0;
}

void add_person(party_t *party, char *name, int age) {
    if (party->size == party->capacity) {
        party->capacity *= 2;
        party->people = realloc(party->people, sizeof(person_t) * party->capacity);
    }

    party->people[party->size].name = name;
    party->people[party->size].age = age;
    party->size++;
}

void print_party(party_t *party) {
    printf("Party members:\n");
    for (int i = 0; i < party->size; i++) {
        printf("  %s (%d)\n", party->people[i].name, party->people[i].age);
    }
}

int main() {
    party_t party;

    // Initialize party
    init_party(&party);

    // Add some party members
    add_person(&party, "Alice", 25);
    add_person(&party, "Bob", 30);
    add_person(&party, "Charlie", 35);

    // Print the party
    print_party(&party);

    // Free the party
    free(party.people);

    return 0;
}