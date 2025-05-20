//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// A simple struct to store a person's name and age
struct person {
    char *name;
    int age;
};

// A function to create a new person struct
struct person *create_person(const char *name, int age) {
    // Allocate memory for the new person struct
    struct person *p = (struct person *)malloc(sizeof(struct person));

    // Copy the name and age into the new struct
    p->name = (char *)malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->age = age;

    // Return the new person struct
    return p;
}

// A function to free the memory allocated for a person struct
void free_person(struct person *p) {
    // Free the memory allocated for the person's name
    free(p->name);

    // Free the memory allocated for the person struct
    free(p);
}

// A function to print the information about a person
void print_person(struct person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main() {
    // Create a new person struct
    struct person *p = create_person("John Doe", 30);

    // Print the information about the person
    print_person(p);

    // Free the memory allocated for the person struct
    free_person(p);

    return 0;
}