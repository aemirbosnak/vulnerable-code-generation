//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
// Linus Torvalds style C Data Mining Example Program

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define data structures
typedef struct {
    char *name;
    int age;
    char *gender;
    char *occupation;
} Person;

// Define function prototypes
Person *createPerson(char *name, int age, char *gender, char *occupation);
void printPerson(Person *person);
void freePerson(Person *person);

// Main function
int main()
{
    // Create a person
    Person *person = createPerson("John Doe", 30, "Male", "Software Engineer");

    // Print the person
    printPerson(person);

    // Free the person
    freePerson(person);

    return 0;
}

// Function to create a person
Person *createPerson(char *name, int age, char *gender, char *occupation)
{
    // Allocate memory for the person
    Person *person = malloc(sizeof(Person));

    // Copy the name, age, gender, and occupation to the person
    person->name = strdup(name);
    person->age = age;
    person->gender = strdup(gender);
    person->occupation = strdup(occupation);

    // Return the person
    return person;
}

// Function to print a person
void printPerson(Person *person)
{
    // Print the person's name, age, gender, and occupation
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %s\n", person->gender);
    printf("Occupation: %s\n", person->occupation);
}

// Function to free a person
void freePerson(Person *person)
{
    // Free the person's name, age, gender, and occupation
    free(person->name);
    free(person->gender);
    free(person->occupation);

    // Free the person
    free(person);
}