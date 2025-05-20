//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[50];
    int age;
    char *description;
} Person;

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);

    if (person->description) {
        printf("Description: %s\n", person->description);
        free(person->description);
        person->description = NULL;
    }
}

int main() {
    Person *person = NULL;
    int choice;

    person = (Person *) malloc(sizeof(Person));
    if (!person) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    printf("Enter name: ");
    fgets(person->name, MAX_LINE_LENGTH, stdin);
    person->name[strcspn(person->name, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &person->age);

    printf("Do you want to enter a description? (1 for yes, 0 for no): ");
    scanf("%d", &choice);

    if (choice) {
        size_t description_length = 0;

        printf("Enter description: ");
        getline(&person->description, &description_length, stdin);
        person->description[description_length - 1] = '\0';
    }

    print_person(person);

    free(person->description);
    free(person);
    person = NULL;

    return EXIT_SUCCESS;
}