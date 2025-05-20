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

// Function to generate a random name and phone number
void generate_random_info(person_t* person) {
    int i;
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        person->name[i] = 'A' + (rand() % 26);
    }
    for (i = 0; i < MAX_PHONE_NUMBER_LENGTH; i++) {
        person->phone_number[i] = '0' + (rand() % 10);
    }
}

// Function to print the person's name and phone number in a puzzling way
void print_info(person_t* person) {
    int i;
    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        if (person->name[i] == 'A') {
            printf("A%c", person->name[i + 1]);
        } else {
            printf("%c", person->name[i]);
        }
    }
    printf(": ");
    for (i = 0; i < MAX_PHONE_NUMBER_LENGTH; i++) {
        if (person->phone_number[i] == '0') {
            printf("0%c", person->phone_number[i + 1]);
        } else {
            printf("%c", person->phone_number[i]);
        }
    }
    printf("\n");
}

int main() {
    person_t person;
    generate_random_info(&person);
    print_info(&person);
    return 0;
}