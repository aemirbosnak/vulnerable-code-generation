//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function declarations
int randInt(int min, int max);
void shuffleChar(char* arr, int len);
void generatePassword(char* dest, int len);

// Main program
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Set password length
    int len = 12;

    // Generate password
    char password[len];
    generatePassword(password, len);

    // Print password
    printf("Generated password: %s\n", password);

    return 0;
}

// Function to generate a random integer between min and max (inclusive)
int randInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to shuffle the characters in an array
void shuffleChar(char* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int j = randInt(i, len - 1);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to generate a secure password
void generatePassword(char* dest, int len) {
    // Define character sets
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special[] = "!@#$%^&*()_+-={}[]\\|;:'\",.?/";

    // Define minimum requirements
    int minLower = 2;
    int minUpper = 2;
    int minNumbers = 2;
    int minSpecial = 2;

    // Calculate remaining slots for random characters
    int remaining = len - minLower - minUpper - minNumbers - minSpecial;

    // Check for impossible requirements
    if (len < (minLower + minUpper + minNumbers + minSpecial)) {
        printf("Error: Password length too short to meet minimum requirements.\n");
        exit(1);
    }
    if (remaining < 0) {
        printf("Error: Minimum requirements are greater than password length.\n");
        exit(1);
    }

    // Generate random characters
    char random[remaining];
    for (int i = 0; i < remaining; i++) {
        int set = randInt(0, 3);
        switch (set) {
            case 0:
                random[i] = randInt(97, 122); // lowercase letters
                break;
            case 1:
                random[i] = randInt(65, 90); // uppercase letters
                break;
            case 2:
                random[i] = randInt(48, 57); // numbers
                break;
            case 3:
                random[i] = special[randInt(0, strlen(special) - 1)]; // special characters
                break;
        }
    }

    // Combine characters and shuffle
    char all[len + 1]; // create temp array to hold all characters
    strncpy(all, lower, minLower);
    strncpy(all + minLower, upper, minUpper);
    strncpy(all + minLower + minUpper, numbers, minNumbers);
    strncpy(all + minLower + minUpper + minNumbers, special, minSpecial);
    strncpy(all + minLower + minUpper + minNumbers + minSpecial, random, remaining);
    all[len] = '\0'; // add null terminator
    shuffleChar(all, len);

    // Copy to destination string
    strncpy(dest, all, len);
    dest[len] = '\0'; // add null terminator
}