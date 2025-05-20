//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    float height;
} Person;

Person *people;
int num_people = 0;

void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f\n", p->height);
}

Person *create_person(const char *name, int age, float height) {
    Person *new_person = malloc(sizeof(Person));

    if (new_person == NULL) {
        fprintf(stderr, "Failed to allocate memory for new person.\n");
        return NULL;
    }

    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->height = height;

    num_people++;
    return new_person;
}

void free_person(Person *p) {
    free(p);
    num_people--;
}

int main() {
    people = NULL;

    // Create some people
    people = create_person("John Doe", 30, 1.75);
    if (people != NULL) {
        print_person(people);
        people = create_person("Jane Doe", 25, 1.65);
        if (people != NULL) {
            print_person(people);
            people = create_person("Bob Smith", 45, 1.85);
            if (people != NULL) {
                print_person(people);

                // Free the memory of a person
                free_person(people - 1);
                print_person(people - 1); // Should print an error message

                // Free all the memory
                while (num_people > 0) {
                    free_person(people);
                }
            }
        }
    }

    free(people);

    return 0;
}