//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
int checkPasswordStrength(char* password)
{
    // Check length of password
    if (strlen(password) < 8)
        return 0;

    // Check if password contains uppercase, lowercase, digits and special characters
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    for (int i = 0; password[i]!= '\0'; i++)
    {
        if (isupper(password[i]))
            hasUpper = 1;
        if (islower(password[i]))
            hasLower = 1;
        if (isdigit(password[i]))
            hasDigit = 1;
        if (!isalnum(password[i]))
            hasSpecialChar = 1;
    }

    if (!hasUpper ||!hasLower ||!hasDigit ||!hasSpecialChar)
        return 0;

    // Check if password contains repeated characters
    char* temp = strdup(password);
    int j = 0;
    while (temp[j]!= '\0')
    {
        if (temp[j]!= temp[j + 1])
            j++;
        else
            j++;
    }
    if (j < 5)
        return 0;

    return 1;
}

int main()
{
    char password[100];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    int strength = checkPasswordStrength(password);

    if (strength == 0)
        printf("Password is weak.\n");
    else
        printf("Password is strong.\n");

    return 0;
}