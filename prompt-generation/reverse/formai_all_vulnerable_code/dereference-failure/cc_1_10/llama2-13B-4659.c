//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 256
#define MAX_ARRAY_SIZE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    int height;
} person_t;

typedef struct {
    person_t** array;
    int size;
    int capacity;
} people_t;

void init_people(people_t* p) {
    p->array = malloc(MAX_ARRAY_SIZE * sizeof(person_t*));
    p->size = 0;
    p->capacity = MAX_ARRAY_SIZE;
}

void add_person(people_t* p, char* name, int age, int height) {
    if (p->size == p->capacity) {
        int new_capacity = p->capacity * 2;
        person_t** new_array = realloc(p->array, new_capacity * sizeof(person_t*));
        if (new_array == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        p->array = new_array;
        p->capacity = new_capacity;
    }
    p->array[p->size] = malloc(sizeof(person_t));
    strcpy(p->array[p->size]->name, name);
    p->array[p->size]->age = age;
    p->array[p->size]->height = height;
    p->size++;
}

void search_person(people_t* p, char* name) {
    int low = 0;
    int high = p->size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(p->array[mid]->name, name) == 0) {
            printf("Found person: %s\n", name);
            return;
        } else if (strcmp(p->array[mid]->name, name) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Person not found\n");
}

int main() {
    people_t* p = malloc(sizeof(people_t));
    init_people(p);

    add_person(p, "Alice", 25, 165);
    add_person(p, "Bob", 30, 180);
    add_person(p, "Charlie", 20, 170);
    add_person(p, "David", 35, 190);
    add_person(p, "Eve", 28, 175);

    search_person(p, "Alice");

    return 0;
}