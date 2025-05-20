//Falcon-180B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for our data
typedef struct {
    char* name;
    int age;
} person_t;

// Function to allocate memory for a new person
person_t* create_person(char* name, int age) {
    // Allocate memory for the struct
    person_t* person = (person_t*)malloc(sizeof(person_t));
    
    // Check if memory allocation was successful
    if (person == NULL) {
        printf("Error: could not allocate memory for person.\n");
        exit(1);
    }
    
    // Allocate memory for the name string
    person->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    
    // Check if memory allocation was successful
    if (person->name == NULL) {
        printf("Error: could not allocate memory for person's name.\n");
        exit(1);
    }
    
    // Copy the name into the allocated memory
    strcpy(person->name, name);
    
    // Set the age
    person->age = age;
    
    // Return the newly created person
    return person;
}

// Function to print a person's information
void print_person(person_t* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Function to free the memory used by a person
void delete_person(person_t* person) {
    // Free the memory for the name string
    free(person->name);
    
    // Free the memory for the struct
    free(person);
}

int main() {
    // Create a new person
    person_t* person1 = create_person("John Doe", 30);
    
    // Print the person's information
    print_person(person1);
    
    // Create another new person
    person_t* person2 = create_person("Jane Smith", 25);
    
    // Print the second person's information
    print_person(person2);
    
    // Delete the first person
    delete_person(person1);
    
    // Print the second person's information again
    print_person(person2);
    
    // Delete the second person
    delete_person(person2);
    
    // Try to print the first person's information again (should be NULL)
    print_person(person1);
    
    return 0;
}