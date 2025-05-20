//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 10

// Define a struct to store a person's name and phone number
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} person_t;

// Function to print a person's name and phone number in a puzzling way
void print_name_and_phone(person_t *person) {
    int i, j;
    char temp[MAX_NAME_LENGTH];

    // Scramble the person's name and phone number
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        temp[i] = person->name[i] + person->phone_number[i];
    }

    // Print the scrambled name and phone number
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        printf("%c", temp[i]);
    }
    printf("\n");

    // Reverse the scrambled name and phone number
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        temp[i] = person->name[i];
        person->name[i] = temp[i];
    }
    for (i = 0; i < MAX_PHONE_NUMBER_LENGTH; i++) {
        temp[i] = person->phone_number[i];
        person->phone_number[i] = temp[i];
    }
}

int main() {
    person_t person = {
        "Alice",
        "123-4567"
    };

    srand(time(NULL));

    // Scramble the person's name and phone number
    for (int i = 0; i < 10; i++) {
        print_name_and_phone(&person);
    }

    return 0;
}