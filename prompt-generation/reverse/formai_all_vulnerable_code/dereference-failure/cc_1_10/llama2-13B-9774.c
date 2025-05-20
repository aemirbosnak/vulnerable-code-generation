//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 20

// Structure to store a person's name and phone number
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} person_t;

// Function to print a happy message
void print_happy_message() {
    printf("Hello! 😊 I'm so glad you're here! 😄\n");
}

// Function to create a new person
person_t* create_person(char* name, char* phoneNumber) {
    person_t* new_person = malloc(sizeof(person_t));
    strcpy(new_person->name, name);
    strcpy(new_person->phoneNumber, phoneNumber);
    return new_person;
}

// Function to print all people in a happy way
void print_people(person_t* people[], int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Hey there, %s! 😊 Your phone number is %s.\n", people[i]->name, people[i]->phoneNumber);
    }
}

int main() {
    // Create some people
    person_t* person1 = create_person("John", "555-1234");
    person_t* person2 = create_person("Jane", "555-5678");
    person_t* person3 = create_person("Bob", "555-9012");

    // Store the people in an array
    person_t people[3] = {person1, person2, person3};

    // Print the people in a happy way
    print_people(people, 3);

    // Free the memory of the people
    free(person1);
    free(person2);
    free(person3);

    return 0;
}