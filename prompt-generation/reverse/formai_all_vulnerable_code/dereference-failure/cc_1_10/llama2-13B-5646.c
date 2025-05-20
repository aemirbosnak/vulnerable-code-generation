//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_OBJS 10

typedef struct {
    char name[MAX_STR_LEN];
    int age;
} person;

typedef struct {
    person *arr[MAX_OBJS];
} pool;

pool *create_pool(void) {
    pool *p = malloc(sizeof(pool));
    for (int i = 0; i < MAX_OBJS; i++) {
        p->arr[i] = malloc(sizeof(person));
    }
    return p;
}

void destroy_pool(pool *p) {
    for (int i = 0; i < MAX_OBJS; i++) {
        free(p->arr[i]->name);
        free(p->arr[i]);
    }
    free(p);
}

person *create_person(char *name, int age) {
    person *p = malloc(sizeof(person));
    strcpy(p->name, name);
    p->age = age;
    return p;
}

void print_person(person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    pool *p = create_pool();

    // Create and allocate memory for a few objects
    person *p1 = create_person("Alice", 25);
    person *p2 = create_person("Bob", 30);
    person *p3 = create_person("Charlie", 35);

    // Add the objects to the pool
    p->arr[0] = p1;
    p->arr[1] = p2;
    p->arr[2] = p3;

    // Print the objects
    for (int i = 0; i < MAX_OBJS; i++) {
        print_person(p->arr[i]);
    }

    // Destroy the pool and free the memory
    destroy_pool(p);

    return 0;
}