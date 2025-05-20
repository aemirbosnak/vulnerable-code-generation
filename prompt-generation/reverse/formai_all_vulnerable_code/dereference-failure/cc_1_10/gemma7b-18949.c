//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LEN 255

typedef struct Password
{
    char *pass;
    int strength;
} Password;

int passwordStrength(char *pass)
{
    int score = 0;

    // Check for minimum length
    if (strlen(pass) < 8)
    {
        score -= 10;
    }

    // Check for uppercase letter
    if (!strchr(pass, 'A'))
    {
        score -= 10;
    }

    // Check for lowercase letter
    if (!strchr(pass, 'a'))
    {
        score -= 10;
    }

    // Check for number
    if (!strchr(pass, '0') || !strchr(pass, '9'))
    {
        score -= 10;
    }

    // Check for symbol
    if (!strchr(pass, '$') && !strchr(pass, '&') && !strchr(pass, '#'))
    {
        score -= 10;
    }

    // Calculate strength
    score = 100 - score;

    return score;
}

int main()
{
    Password pass;

    // Allocate memory for the password structure
    pass.pass = malloc(MAX_PASS_LEN);

    // Get the password from the user
    printf("Enter your password: ");
    fgets(pass.pass, MAX_PASS_LEN, stdin);

    // Calculate the password strength
    pass.strength = passwordStrength(pass.pass);

    // Display the password strength
    printf("Your password strength is: %d%%", pass.strength);

    // Free the memory allocated for the password structure
    free(pass.pass);

    return 0;
}