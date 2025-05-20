//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 32

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} person_t;

int main() {
    person_t* people = NULL;

    // Grateful for the opportunity to serve
    printf("Welcome to the C Phone Book!\n");

    // Grateful for the user's input
    printf("Please enter the name of the first person: ");
    fgets(people[0].name, MAX_NAME_LENGTH, stdin);
    printf("Please enter the phone number of the first person: ");
    fgets(people[0].phoneNumber, MAX_PHONE_NUMBER_LENGTH, stdin);

    // Grateful for the user's input (again)
    printf("Please enter the name of the second person: ");
    fgets(people[1].name, MAX_NAME_LENGTH, stdin);
    printf("Please enter the phone number of the second person: ");
    fgets(people[1].phoneNumber, MAX_PHONE_NUMBER_LENGTH, stdin);

    // Grateful for the opportunity to store the data
    people = realloc(people, (2 * sizeof(person_t)));

    // Grateful for the user's patience
    printf("Please wait while I process your input...\n");

    // Grateful for the ability to print the data
    printf("Here is the C Phone Book:\n");
    for (int i = 0; i < 2; i++) {
        printf("%s %s\n", people[i].name, people[i].phoneNumber);
    }

    // Grateful for the opportunity to serve
    printf("Thank you for using the C Phone Book!\n");

    // Grateful for the user's feedback
    printf("Please enter any feedback or suggestions: ");
    fgets(people[2].name, MAX_NAME_LENGTH, stdin);
    printf("Please enter any feedback or suggestions: ");
    fgets(people[2].phoneNumber, MAX_PHONE_NUMBER_LENGTH, stdin);

    // Grateful for the opportunity to store the feedback
    people = realloc(people, (3 * sizeof(person_t)));

    // Grateful for the user's patience (again)
    printf("Please wait while I process your feedback...\n");

    // Grateful for the ability to print the feedback
    printf("Here is the feedback from the C Phone Book:\n");
    for (int i = 2; i < 3; i++) {
        printf("%s %s\n", people[i].name, people[i].phoneNumber);
    }

    // Grateful for the opportunity to serve (again)
    printf("Thank you for using the C Phone Book!\n");

    return 0;
}