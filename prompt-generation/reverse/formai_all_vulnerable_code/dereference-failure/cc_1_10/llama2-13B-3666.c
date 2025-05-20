//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person;

void *malloc_pool[MAX_OBJS];

void init_pool() {
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        malloc_pool[i] = malloc(sizeof(person));
        if (malloc_pool[i] == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
}

void free_pool() {
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        if (malloc_pool[i] != NULL) {
            free(malloc_pool[i]);
            malloc_pool[i] = NULL;
        }
    }
}

person *create_person(const char *name, int age) {
    person *p = malloc_pool[rand() % MAX_OBJS];
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->name = name;
    p->age = age;
    return p;
}

void print_person(person *p) {
    printf("%s is %d years old\n", p->name, p->age);
}

int main() {
    init_pool();

    person *p1 = create_person("Alice", 25);
    person *p2 = create_person("Bob", 30);
    person *p3 = create_person("Charlie", 35);

    print_person(p1);
    print_person(p2);
    print_person(p3);

    free_pool();

    return 0;
}