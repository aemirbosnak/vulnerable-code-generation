//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold information about a person
typedef struct {
    char *name;
    int age;
    char *address;
} Person;

// Helper function to allocate memory for a Person and initialize fields
Person* create_person(char *name, int age, char *address) {
    Person *person = malloc(sizeof(Person));
    person->name = name;
    person->age = age;
    person->address = address;
    return person;
}

// Helper function to print information about a Person
void print_person(Person *person) {
    printf("Name: %s\nAge: %d\nAddress: %s\n", person->name, person->age, person->address);
}

int main() {
    FILE *file;
    file = fopen("people.txt", "w");

    // Create some people
    Person *person1 = create_person("John Smith", 28, "123 Main St");
    Person *person2 = create_person("Jane Doe", 35, "456 Maple Ave");

    // Write the people to a file
    fprintf(file, "%s;%d;%s\n", person1->name, person1->age, person1->address);
    fprintf(file, "%s;%d;%s\n", person2->name, person2->age, person2->address);

    // Close the file
    fclose(file);

    // Read the people from the file
    file = fopen("people.txt", "r");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        char *name = strtok(line, ";");
        int age = atoi(strtok(NULL, ";"));
        char *address = strtok(NULL, ";");
        Person *person = create_person(name, age, address);
        print_person(person);
        free(person);
    }

    // Close the file and free memory
    fclose(file);
    if (line) {
        free(line);
    }

    return 0;
}