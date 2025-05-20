//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

char *generate_random_string(int length);

int main()
{
    char *password = generate_random_string(16);
    int strength = check_password_strength(password);
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
        default:
            printf("Error: Invalid password strength\n");
            break;
    }
    free(password);
    return 0;
}

char *generate_random_string(int length)
{
    char *str = malloc(length);
    for (int i = 0; i < length; i++)
    {
        str[i] = rand() % 26 + 'a';
    }
    str[length - 1] = '\0';
    return str;
}

int check_password_strength(char *password)
{
    int length = strlen(password);
    int has_upper = 0;
    int has_number = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_upper = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_number = 1;
        }
        else if (password[i] >= '`' && password[i] <= 'z')
        {
            has_special = 1;
        }
    }

    if (length < 8)
    {
        return 0;
    }
    else if (has_upper && has_number && has_special)
    {
        return 3;
    }
    else if (has_upper || has_number || has_special)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}