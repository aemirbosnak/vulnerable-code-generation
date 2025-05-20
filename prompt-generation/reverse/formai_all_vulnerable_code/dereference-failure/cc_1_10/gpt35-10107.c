//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void generatePassword(char *password, int length);
void printGeneratedPassword(char *password, int length);

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Define the length of the password
    int length = 12;

    // Allocate memory for the password string
    char *password = (char*) malloc((length + 1) * sizeof(char));

    // Generate the password
    generatePassword(password, length);

    // Print the generated password
    printGeneratedPassword(password, length);

    // Deallocate memory for the password string
    free(password);

    return 0;
}

// Function to generate a secure password
void generatePassword(char *password, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':\",./<>?";
    int index;
    for(int i = 0; i < length; i++) {
        index = rand() % sizeof(charset);
        password[i] = charset[index];
    }
    password[length] = '\0';
}

// Function to print the generated password
void printGeneratedPassword(char *password, int length) {
    printf("Generated Password: ");
    for(int i = 0; i < length; i++) {
        printf("%c", password[i]);
    }
    printf("\n");
}