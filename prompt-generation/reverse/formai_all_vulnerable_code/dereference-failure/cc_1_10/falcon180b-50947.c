//Falcon-180B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a person
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Function to create a new person with default values
Person* createPerson() {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    if (newPerson == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newPerson->name, "Unknown");
    newPerson->age = 0;
    newPerson->height = 0.0;
    return newPerson;
}

// Function to set a person's name
void setName(Person* person, char* newName) {
    strcpy(person->name, newName);
}

// Function to set a person's age
void setAge(Person* person, int newAge) {
    person->age = newAge;
}

// Function to set a person's height
void setHeight(Person* person, float newHeight) {
    person->height = newHeight;
}

// Function to print a person's information
void printPerson(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
}

// Main function
int main() {
    Person* person1 = createPerson();
    Person* person2 = createPerson();

    setName(person1, "John Doe");
    setAge(person1, 25);
    setHeight(person1, 1.80);

    setName(person2, "Jane Smith");
    setAge(person2, 30);
    setHeight(person2, 1.65);

    printPerson(person1);
    printPerson(person2);

    free(person1);
    free(person2);

    return 0;
}