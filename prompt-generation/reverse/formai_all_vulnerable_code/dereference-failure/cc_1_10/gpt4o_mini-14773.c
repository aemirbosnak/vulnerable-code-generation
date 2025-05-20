//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

void initialize_person(Person *p, const char *name, int age, float height) {
    p->name = (char *)malloc(strlen(name) + 1); // Allocate memory for name
    if (p->name == NULL) {
        perror("Failed to allocate memory for name");
        exit(EXIT_FAILURE);
    }
    strcpy(p->name, name); // Copy name
    p->age = age; // Set age
    p->height = height; // Set height
}

void display_person(const Person *p) {
    if (p == NULL) {
        printf("No person data available.\n");
        return;
    }
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f meters\n", p->height);
}

void free_person(Person *p) {
    if (p != NULL) {
        free(p->name); // Free allocated memory for name
        p->name = NULL; // Set pointer to NULL to avoid dangling pointer
    }
}

void sort_persons(Person *persons, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (persons[j].age > persons[j + 1].age) {
                Person temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = temp; // Swap
            }
        }
    }
}

int main() {
    int count = 3;
    Person *persons = (Person *)malloc(count * sizeof(Person)); // Allocate memory for persons
    if (persons == NULL) {
        perror("Failed to allocate memory for persons");
        exit(EXIT_FAILURE);
    }

    // Initialize person data
    initialize_person(&persons[0], "Alice", 30, 1.65);
    initialize_person(&persons[1], "Bob", 25, 1.75);
    initialize_person(&persons[2], "Charlie", 35, 1.80);

    printf("Before Sorting:\n");
    for (int i = 0; i < count; i++) {
        display_person(&persons[i]);
    }

    // Sort persons by age
    sort_persons(persons, count);

    printf("\nAfter Sorting:\n");
    for (int i = 0; i < count; i++) {
        display_person(&persons[i]);
    }

    // Free memory allocated for each person
    for (int i = 0; i < count; i++) {
        free_person(&persons[i]);
    }

    // Free memory allocated for persons
    free(persons);
    persons = NULL; // Avoid dangling pointer

    return 0;
}