//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between two values
int generateRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a secure password with a combination of uppercase letters, lowercase letters, numbers, and symbols
char* generatePassword(int length)
{
    // Arrays of possible characters for each category
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=";

    // Create an array to hold the password
    char* password = malloc(sizeof(char) * length);

    // Use srand to seed the random number generator with the current time
    srand((unsigned int) time(NULL));

    // Loop through until the desired length is reached
    for (int i = 0; i < length; i++)
    {
        // Generate a random number to determine which category to use
        int category = generateRand(1, 4); // 1 = uppercase, 2 = lowercase, 3 = numbers, 4 = symbols

        // Generate a random index within the chosen category's array
        int index;
        switch (category)
        {
            case 1: // Uppercase
                index = generateRand(0, 25);
                password[i] = uppercase[index];
                break;

            case 2: // Lowercase
                index = generateRand(0, 25);
                password[i] = lowercase[index];
                break;

            case 3: // Numbers
                index = generateRand(0, 9);
                password[i] = numbers[index];
                break;

            case 4: // Symbols
                index = generateRand(0, 11);
                password[i] = symbols[index];
                break;
        }
    }

    // Add a null terminator to the end of the password array
    password[length] = '\0';

    // Return the password
    return password;
}

int main()
{
    int length;

    // Get the desired length of the password from the user
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    // Generate the password
    char* password = generatePassword(length);

    // Print the password to the console
    printf("\nGenerated Password: %s\n", password);

    // Free the memory used by the password array
    free(password);

    // Return 0 to indicate successful program completion
    return 0;
}