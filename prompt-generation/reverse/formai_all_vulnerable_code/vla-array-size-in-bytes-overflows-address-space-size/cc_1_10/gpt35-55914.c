//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length, int uppercase, int lowercase, int numbers, int symbols);

int main() {
    int length, uppercase, lowercase, numbers, symbols;

    // Get user input
    printf("Enter password length: ");
    scanf("%d", &length);
    printf("Include uppercase letters? [1 for yes / 0 for no]: ");
    scanf("%d", &uppercase);
    printf("Include lowercase letters? [1 for yes / 0 for no]: ");
    scanf("%d", &lowercase);
    printf("Include numbers? [1 for yes / 0 for no]: ");
    scanf("%d", &numbers);
    printf("Include symbols? [1 for yes / 0 for no]: ");
    scanf("%d", &symbols);

    generatePassword(length, uppercase, lowercase, numbers, symbols);

    return 0;
}

void generatePassword(int length, int uppercase, int lowercase, int numbers, int symbols) {
    char password[length];
    int i, index, type;
    int totalTypes = uppercase + lowercase + numbers + symbols;
    int typeCounter[totalTypes];
    int passwordCounter[length];
    char character;

    // Seed the random number generator
    srand(time(NULL));

    // Set typeCounter and passwordCounter to 0
    for (i = 0; i < totalTypes; i++) {
        typeCounter[i] = 0;
    }
    for (i = 0; i < length; i++) {
        passwordCounter[i] = 0;
    }

    // Generate the password
    for (i = 0; i < length; i++) {
        // Generate a random type
        type = rand() % totalTypes;
        while (typeCounter[type] == 0) {
            type = rand() % totalTypes;
        }
        typeCounter[type]--;

        // Generate a random index
        index = rand() % length;
        while (passwordCounter[index] != 0) {
            index = rand() % length;
        }
        passwordCounter[index] = 1;

        // Determine the character to add
        if (uppercase && type == 0) {
            character = 'A' + (rand() % 26);
        } else if (lowercase && type == 1) {
            character = 'a' + (rand() % 26);
        } else if (numbers && type == 2) {
            character = '0' + (rand() % 10);
        } else if (symbols && type == 3) {
            character = '!' + (rand() % 15);
        } else {
            // If no character was added, decrement the index so it can be tried again
            passwordCounter[index] = 0;
            i--;
            continue;
        }

        // Add character to password
        password[index] = character;
    }

    // Print the password
    printf("Secure Password: ");
    for (i = 0; i < length; i++) {
        printf("%c", password[i]);
    }
    printf("\n");
}