//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 16

// Function declarations
char *generate_password();
int is_special_character(char ch);
int is_uppercase(char ch);
int is_lowercase(char ch);
int is_digit(char ch);

// Main function
int main(void)
{
    char *password = generate_password();

    printf("Your secure password is: %s\n", password);

    return 0;
}

// Function to generate a secure password
char *generate_password()
{
    char *password = malloc(PASSWORD_LENGTH + 1);
    int i, count_special = 0, count_upper = 0, count_lower = 0, count_digit = 0;
    srand(time(0)); // Initialize the seed for the random number generator

    // Generate password with a minimum count of special characters, uppercase letters, lowercase letters, and digits
    while (count_special < 2 || count_upper < 2 || count_lower < 2 || count_digit < 2)
    {
        for (i = 0; i < PASSWORD_LENGTH; i++)
        {
            int random_num = rand() % 4; // Generate a random number between 0 and 3 to determine which type of character to add to the password

            if (random_num == 0 && count_special < 2)
            {
                password[i] = '!'; // Add special character
                count_special++;
            }
            else if (random_num == 1 && count_upper < 2)
            {
                password[i] = 'A' + rand() % 26; // Add uppercase letter
                count_upper++;
            }
            else if (random_num == 2 && count_lower < 2)
            {
                password[i] = 'a' + rand() % 26; // Add lowercase letter
                count_lower++;
            }
            else if (random_num == 3 && count_digit < 2)
            {
                password[i] = '0' + rand() % 10; // Add digit
                count_digit++;
            }
            else
            {
                // If a character of that type has already been added to the password, generate a new random number to try again
                i--;
            }
        }
    }

    // Add remaining random characters to password
    for (i = count_special + count_upper + count_lower + count_digit; i < PASSWORD_LENGTH; i++)
    {
        int random_num = rand() % 62; // Generate a random number between 0 and 61 to map to all possible characters

        if (random_num < 10)
        {
            password[i] = '0' + random_num; // Add digit
        }
        else if (random_num < 36)
        {
            password[i] = 'A' + random_num - 10; // Add uppercase letter
        }
        else
        {
            password[i] = 'a' + random_num - 36; // Add lowercase letter
        }
    }

    password[PASSWORD_LENGTH] = '\0'; // Add null terminating character

    return password;
}

// Helper function to determine if a character is a special character
int is_special_character(char ch)
{
    return ispunct(ch) && !isalnum(ch);
}

// Helper function to determine if a character is an uppercase letter
int is_uppercase(char ch)
{
    return isupper(ch);
}

// Helper function to determine if a character is a lowercase letter
int is_lowercase(char ch)
{
    return islower(ch);
}

// Helper function to determine if a character is a digit
int is_digit(char ch)
{
    return isdigit(ch);
}