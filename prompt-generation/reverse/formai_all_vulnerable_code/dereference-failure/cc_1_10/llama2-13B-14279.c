//LLAMA2-13B DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person;

void greet(person *p) {
    printf("Hello, my name is %s and I am %d years old.\n", p->name, p->age);
}

int main() {
    person p = {
        .name = "Alice",
        .age = 25
    };

    srand(time(NULL));

    printf("Welcome to my thoughtful world!\n");

    // Generate a random name and age for a new person
    char random_name[MAX_NAME_LENGTH];
    int random_age = rand() % MAX_AGE + 1;

    printf("I see a person entering the room...\n");

    // Create a new person with the random name and age
    person *new_person = malloc(sizeof(person));
    strcpy(new_person->name, random_name);
    new_person->age = random_age;

    // Print a greeting message for the new person
    greet(new_person);

    // Ask the user for their name and age
    printf("What is your name and age?\n");

    // Get the user's name and age using scanf()
    char user_name[MAX_NAME_LENGTH];
    int user_age;
    scanf("%s %d", user_name, &user_age);

    // Print a personalized greeting message for the user
    printf("Hello, %s! I am %d years old.\n", user_name, user_age);

    // Free the memory allocated for the new person
    free(new_person);

    return 0;
}