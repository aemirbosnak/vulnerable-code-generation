//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 1024
#define MAX_OBJECT_SIZE 64

typedef struct {
    char name[MAX_OBJECT_SIZE];
    int age;
} person;

void* malloc_fn(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        printf("Error: Could not allocate %zu bytes of memory\n", size);
        return NULL;
    }
    return mem;
}

void free_fn(void* mem) {
    free(mem);
}

void* create_person(const char* name, int age) {
    person* p = malloc_fn(sizeof(person));
    if (p == NULL) {
        return NULL;
    }
    strcpy(p->name, name);
    p->age = age;
    return p;
}

void destroy_person(void* person) {
    free_fn(person);
}

int main() {
    person* p1 = create_person("Alice", 25);
    person* p2 = create_person("Bob", 30);
    person* p3 = create_person("Charlie", 35);

    printf("p1: %s, age: %d\n", p1->name, p1->age);
    printf("p2: %s, age: %d\n", p2->name, p2->age);
    printf("p3: %s, age: %d\n", p3->name, p3->age);

    destroy_person(p1);
    destroy_person(p2);
    destroy_person(p3);

    return 0;
}