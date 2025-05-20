//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 20
#define MAX_OBJS 10

typedef struct {
    char name[MAX_STRLEN];
    int age;
} person_t;

void *malloc_with_len(size_t size, size_t len) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Failed to allocate memory\n");
        return NULL;
    }
    memset(ptr, 0, size);
    return ptr;
}

void free_with_len(void *ptr, size_t len) {
    free(ptr);
    if (ptr == NULL) {
        return;
    }
    memset(ptr, 0, len);
}

person_t *create_person(const char *name, int age) {
    person_t *person = malloc_with_len(sizeof(person_t), strlen(name) + 1);
    if (person == NULL) {
        printf("Failed to allocate memory for person\n");
        return NULL;
    }
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void print_person(person_t *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    person_t *person1 = create_person("Alice", 25);
    person_t *person2 = create_person("Bob", 30);
    person_t *person3 = create_person("Charlie", 35);

    print_person(person1);
    print_person(person2);
    print_person(person3);

    free_with_len(person1, sizeof(person_t));
    free_with_len(person2, sizeof(person_t));
    free_with_len(person3, sizeof(person_t));

    return 0;
}