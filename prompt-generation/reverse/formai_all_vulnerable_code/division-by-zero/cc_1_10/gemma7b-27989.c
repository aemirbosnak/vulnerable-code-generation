//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 256

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength;
    int i, j, k;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    strength = 0;
    for (i = 0; i < password_length; i++)
    {
        for (j = 0; j < MAX_PASSWORD_LENGTH; j++)
        {
            if (password[i] == password[j])
            {
                strength++;
            }
        }
    }

    strength = strength / password_length;

    switch (strength)
    {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Moderate\n");
            break;
        case 2:
            printf("Password strength: Strong\n");
            break;
        case 3:
            printf("Password strength: Very Strong\n");
            break;
    }

    return 0;
}