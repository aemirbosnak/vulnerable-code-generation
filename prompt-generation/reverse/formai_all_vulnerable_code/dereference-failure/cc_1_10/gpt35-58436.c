//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 20

// Function to generate a secure password
char* generate_password(int length) {
    char* password = (char*) malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        // Generate a random number from 0-2 to determine what type of character to add
        int rand_num = rand() % 3;
        if (rand_num == 0) {
            // Add a random lowercase letter
            password[i] = (char) ((rand() % 26) + 97);
        }
        else if (rand_num == 1) {
            // Add a random uppercase letter
            password[i] = (char) ((rand() % 26) + 65);
        }
        else {
            // Add a random symbol
            char symbols[] = "!@#$%^&*()_+-=";
            password[i] = symbols[rand() % strlen(symbols)];
        }
    }

    password[length] = '\0'; // Add null terminator to end of password
    return password;
}

int main() {
    int length;
    char* password;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter the length of the password you would like to generate (maximum %d): ", MAX_LENGTH);
    scanf("%d", &length);

    if (length > MAX_LENGTH) {
        printf("Error: Password length exceeds maximum length of %d\n", MAX_LENGTH);
        return -1;
    }

    password = generate_password(length);

    printf("Your secure password is: %s\n", password);

    free(password); // Free memory allocated for password

    return 0;
}