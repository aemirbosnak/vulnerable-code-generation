//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the medieval-style data types
typedef enum {
    FALSE = 0,
    TRUE = 1
} BOOL;

typedef struct {
    char* name;
    int age;
} PERSON;

// Define the medieval-style functions
void print_person(PERSON* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

PERSON* create_person(char* name, int age) {
    PERSON* person = (PERSON*)malloc(sizeof(PERSON));
    person->name = strdup(name);
    person->age = age;
    return person;
}

BOOL is_adult(PERSON* person) {
    return person->age >= 18;
}

// Define the main function in a medieval-style syntax
int main() {
    // Declare the variables
    PERSON* king = NULL;
    PERSON* queen = NULL;
    PERSON* knight = NULL;

    // Create the king
    king = create_person("King Arthur", 45);

    // Create the queen
    queen = create_person("Queen Guinevere", 35);

    // Create the knight
    knight = create_person("Sir Lancelot", 25);

    // Print the details of the king
    print_person(king);

    // Check if the queen is an adult
    if (is_adult(queen)) {
        printf("The queen is an adult.\n");
    } else {
        printf("The queen is not an adult.\n");
    }

    // Check if the knight is an adult
    if (is_adult(knight)) {
        printf("The knight is an adult.\n");
    } else {
        printf("The knight is not an adult.\n");
    }

    // Free the memory allocated for the persons
    free(king->name);
    free(king);
    free(queen->name);
    free(queen);
    free(knight->name);
    free(knight);

    return 0;
}