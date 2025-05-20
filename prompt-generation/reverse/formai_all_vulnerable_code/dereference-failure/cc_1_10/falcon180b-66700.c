//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *list = NULL;
int list_size = 0;

void add_person(char *name, int age) {
    list = realloc(list, sizeof(Person) * ++list_size);
    list[list_size - 1].name = strdup(name);
    list[list_size - 1].age = age;
}

void print_list() {
    int i;
    for (i = 0; i < list_size; i++) {
        printf("%s (%d)\n", list[i].name, list[i].age);
    }
}

int search_list(char *name) {
    int i;
    for (i = 0; i < list_size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    add_person("Alice", 25);
    add_person("Bob", 30);
    add_person("Charlie", 35);
    add_person("Dave", 40);

    print_list();

    int index = search_list("Bob");
    if (index!= -1) {
        printf("Found Bob at index %d\n", index);
    } else {
        printf("Bob not found\n");
    }

    return 0;
}