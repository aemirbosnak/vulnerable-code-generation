//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_ARRAY_SIZE 100
#define MAX_STR_LEN 50

typedef struct {
    int id;
    char name[MAX_STR_LEN];
} person;

typedef struct {
    int capacity;
    person* array;
} person_array;

void init_person_array(person_array* pa, int capacity) {
    pa->capacity = capacity;
    pa->array = (person*) malloc(capacity * sizeof(person));
}

void add_person(person_array* pa, int id, char name[]) {
    if (pa->capacity == 0) {
        pa->capacity = 10;
        pa->array = (person*) realloc(pa->array, pa->capacity * sizeof(person));
    }
    if (pa->capacity <= id) {
        pa->capacity *= 2;
        pa->array = (person*) realloc(pa->array, pa->capacity * sizeof(person));
    }
    pa->array[id].id = id;
    strcpy(pa->array[id].name, name);
}

void print_person_array(person_array* pa) {
    for (int i = 0; i < pa->capacity; i++) {
        printf("%d: %s\n", pa->array[i].id, pa->array[i].name);
    }
}

int main() {
    person_array* pa = (person_array*) malloc(sizeof(person_array));
    init_person_array(pa, 5);

    add_person(pa, 1, "Alice");
    add_person(pa, 2, "Bob");
    add_person(pa, 3, "Charlie");
    add_person(pa, 4, "David");
    add_person(pa, 5, "Eve");

    print_person_array(pa);

    return 0;
}