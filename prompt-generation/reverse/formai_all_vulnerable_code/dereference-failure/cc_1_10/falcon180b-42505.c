//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of a conspiracy theory
#define MAX_THEORY_LENGTH 100

typedef struct {
    char first_name[20];
    char last_name[20];
    char organization[20];
    char motive[20];
    char action[20];
    char location[20];
} ConspiracyTheory;

// Function to generate a random string of a given length
char* generate_random_string(int length) {
    char* result = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        result[i] = (char)(rand() % 26 + 'a');
    }
    result[length] = '\0';
    return result;
}

// Function to generate a random conspiracy theory
ConspiracyTheory generate_conspiracy_theory() {
    ConspiracyTheory theory;
    strcpy(theory.first_name, generate_random_string(10));
    strcpy(theory.last_name, generate_random_string(10));
    strcpy(theory.organization, generate_random_string(10));
    strcpy(theory.motive, generate_random_string(10));
    strcpy(theory.action, generate_random_string(10));
    strcpy(theory.location, generate_random_string(10));
    return theory;
}

int main() {
    srand(time(NULL));

    // Generate and print 10 random conspiracy theories
    for (int i = 0; i < 10; i++) {
        ConspiracyTheory theory = generate_conspiracy_theory();
        printf("Conspiracy theory #%d:\n", i + 1);
        printf("First name: %s\n", theory.first_name);
        printf("Last name: %s\n", theory.last_name);
        printf("Organization: %s\n", theory.organization);
        printf("Motive: %s\n", theory.motive);
        printf("Action: %s\n", theory.action);
        printf("Location: %s\n\n", theory.location);
    }

    return 0;
}