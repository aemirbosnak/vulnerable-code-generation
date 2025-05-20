//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_password_strength(char *password)
{
    int strength = 0;
    int min_length = 8;

    // Check for minimum length
    if (strlen(password) < min_length)
    {
        strength--;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A'))
    {
        strength--;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a'))
    {
        strength--;
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9'))
    {
        strength--;
    }

    // Check for special character
    if (!strchr(password, '$') && !strchr(password, '&') && !strchr(password, '%'))
    {
        strength--;
    }

    // Calculate strength
    strength += password[0] - 'a' + 1;
    strength += password[strlen(password) - 1] - 'a' + 1;

    // Print strength
    printf("Password Strength: %d/%d\n", strength, min_length);
}

int main()
{
    char password[256];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    check_password_strength(password);

    return 0;
}