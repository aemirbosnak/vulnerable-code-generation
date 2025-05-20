//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

// Function to generate random password
char* generatePassword(int length)
{
    char* password = (char*) malloc(sizeof(char) * (length + 1));

    // Characters that can be used in password
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]|:;<,>.?/";

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(charset);
        password[i] = charset[index];
    }

    password[length] = '\0';

    return password;
}

int main()
{
    int numPasswords;
    int passwordLength;

    printf("Welcome to Secure Password Generator!\n\n");

    // Get number of passwords from user
    printf("How many passwords would you like? ");
    scanf("%d", &numPasswords);

    // Get password length from user
    printf("How long should the passwords be? (max %d) ", MAX_PASSWORD_LENGTH);
    scanf("%d", &passwordLength);

    if (passwordLength > MAX_PASSWORD_LENGTH) {
        printf("Password length cannot exceed %d characters.", MAX_PASSWORD_LENGTH);
        exit(0);
    }

    // Generate passwords
    for (int i = 0; i < numPasswords; i++) {
        char* password = generatePassword(passwordLength);

        printf("Password %d: %s\n", i+1, password);

        free(password);
    }

    return 0;
}