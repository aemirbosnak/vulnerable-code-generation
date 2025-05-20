//Falcon-180B DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    people = my_malloc(num_people * sizeof(Person));

    if (people == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < num_people; i++) {
        people[i].name = my_malloc(MAX_SIZE * sizeof(char));
        people[i].age = i + 1;

        if (people[i].name == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
    }

    for (int i = 0; i < num_people; i++) {
        printf("Name of person %d: %s\n", i + 1, people[i].name);
        printf("Age of person %d: %d\n", i + 1, people[i].age);
    }

    for (int i = 0; i < num_people; i++) {
        my_free(people[i].name);
    }

    my_free(people);

    return 0;
}