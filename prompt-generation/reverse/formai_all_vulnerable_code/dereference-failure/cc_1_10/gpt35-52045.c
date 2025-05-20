//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

// function declarations
void generatePassword(int length, char *password);
int checkConstraints(char *password);

// main function
int main()
{
    char password[PASSWORD_LENGTH + 1]; // initialize password array with size plus 1 for null terminator
    srand(time(NULL)); // seed random number generator

    // generate secure password
    generatePassword(PASSWORD_LENGTH, password);

    // print generated password
    printf("Your secure password is: %s\n", password);

    return 0;
}

// function definitions
void generatePassword(int length, char *password)
{
    int i;
    char character;
    do
    {
        // generate random character based on ASCII values
        character = rand() % 128;
        if (isalnum(character)) // check if character is alphanumeric
        {
            if (i < length) // add character to password if length constraint not violated
            {
                password[i++] = character;
            }
        }
    } while (i < length); // continue generating characters until length constraint violated

    password[length] = '\0'; // add null terminator to end of password
}

int checkConstraints(char *password)
{
    // check password constraints
    int i, uppercaseCount = 0, lowercaseCount = 0, digitCount = 0;
    for (i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i])) uppercaseCount++;
        if (islower(password[i])) lowercaseCount++;
        if (isdigit(password[i])) digitCount++;
    }

    if (uppercaseCount < 1 || lowercaseCount < 1 || digitCount < 1)
        return 0; // password constraints not met
    else
        return 1; // password constraints met
}