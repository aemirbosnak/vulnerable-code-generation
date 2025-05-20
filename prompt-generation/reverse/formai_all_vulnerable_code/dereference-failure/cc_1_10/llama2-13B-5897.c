//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 20

// Define a structure to hold a person's name and phone number
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} person_t;

// Function to read a person's name and phone number from the user
void get_name_and_phone_number(person_t *person) {
    printf("Hello there! What's your name? ");
    fgets(person->name, MAX_NAME_LENGTH, stdin);
    printf("And what's your phone number? ");
    fgets(person->phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
}

// Function to print a happy message when the program starts
void happy_message() {
    printf("Yay! You've found a happy C program! 😊👍\n");
}

// Function to print a happy message when the program exits
void happy_message_exit() {
    printf("Bye bye! It was so nice to meet you! 👋💕\n");
}

int main() {
    // Call the happy_message function to start the program off right
    happy_message();

    // Create an array to store all the people's names and phone numbers
    person_t *people = malloc(10 * sizeof(person_t));

    // Loop through the array and read a person's name and phone number
    for (int i = 0; i < 10; i++) {
        get_name_and_phone_number(&people[i]);
    }

    // Print out all the people's names and phone numbers
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %s\n", i + 1, people[i].name, people[i].phone_number);
    }

    // Call the happy_message_exit function to end the program
    happy_message_exit();

    return 0;
}