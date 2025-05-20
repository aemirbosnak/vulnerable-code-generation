//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i].name = (char *)malloc(MAX_SIZE);
        array[i].age = i;
        sprintf(array[i].name, "Person %d", i);
    }
}

void print(Person *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", array[i].name, array[i].age);
    }
}

void search(Person *array, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i].name, name) == 0) {
            printf("Found person with name %s\n", name);
        }
    }
}

int main() {
    Person *array;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    array = (Person *)malloc(size * sizeof(Person));

    create(array, size);
    print(array, size);

    char name[MAX_SIZE];
    printf("Enter the name to search: ");
    scanf("%s", name);

    search(array, size, name);

    free(array);
    return 0;
}