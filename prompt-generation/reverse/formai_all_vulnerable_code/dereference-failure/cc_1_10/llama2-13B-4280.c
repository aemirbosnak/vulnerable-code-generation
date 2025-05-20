//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person_t;

typedef struct {
    person_t *persons;
    int capacity;
    int size;
} party_t;

void init_party(party_t *party) {
    party->capacity = MAX_OBJS;
    party->size = 0;
    party->persons = calloc(party->capacity, sizeof(person_t));
}

void add_person(party_t *party, char *name, int age) {
    if (party->size == party->capacity) {
        party->capacity *= 2;
        party->persons = realloc(party->persons, party->capacity * sizeof(person_t));
    }

    party->persons[party->size].name = name;
    party->persons[party->size].age = age;
    party->size++;
}

void print_party(party_t *party) {
    for (int i = 0; i < party->size; i++) {
        printf("%s %d\n", party->persons[i].name, party->persons[i].age);
    }
}

int main() {
    party_t party;
    init_party(&party);

    char *names[] = {"Alice", "Bob", "Charlie", "David"};
    int ages[] = {25, 30, 35, 40};

    for (int i = 0; i < sizeof(names) / sizeof(char *); i++) {
        add_person(&party, names[i], ages[i]);
    }

    print_party(&party);

    return 0;
}