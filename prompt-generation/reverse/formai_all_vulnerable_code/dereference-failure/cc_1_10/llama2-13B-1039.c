//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_ARR_LEN 10

typedef struct {
    char name[MAX_STR_LEN];
    int age;
} person_t;

typedef struct {
    person_t** people;
    int capacity;
    int size;
} party_t;

void init_party(party_t* party) {
    party->people = (person_t**) calloc(MAX_ARR_LEN, sizeof(person_t*));
    party->capacity = MAX_ARR_LEN;
    party->size = 0;
}

void add_person(party_t* party, char* name, int age) {
    if (party->size == party->capacity) {
        party->capacity *= 2;
        person_t** new_people = (person_t**) realloc(party->people, party->capacity * sizeof(person_t*));
        memset(new_people + party->capacity, 0, (party->capacity - party->size) * sizeof(person_t*));
        party->people = new_people;
    }

    party->people[party->size] = (person_t*) calloc(1, sizeof(person_t));
    strcpy(party->people[party->size]->name, name);
    party->people[party->size]->age = age;
    party->size++;
}

void print_party(party_t* party) {
    printf("Party members:\n");
    for (int i = 0; i < party->size; i++) {
        printf("  %s (%d)\n", party->people[i]->name, party->people[i]->age);
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

    // Print the party members
    print_party(&party);

    // Free the party
    free(party.people);

    return 0;
}