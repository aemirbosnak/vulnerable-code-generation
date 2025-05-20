//Gemma-7B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, key, flag = 0, password_strength = 0, arr_size = 10;
    char **passwords = NULL;

    passwords = (char **)malloc(arr_size * sizeof(char *));

    for (i = 0; i < arr_size; i++)
    {
        passwords[i] = (char *)malloc(20 * sizeof(char));
    }

    printf("Enter the number of passwords you want to manage: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a password: ");
        scanf("%s", passwords[i]);

        password_strength = check_password_strength(passwords[i]);

        if (password_strength < 80)
        {
            flag = 1;
            printf("Weak password. Please try again: ");
            scanf("%s", passwords[i]);
            password_strength = check_password_strength(passwords[i]);
        }

        if (flag == 0)
        {
            printf("Password added successfully.\n");
        }
    }

    free(passwords);

    return 0;
}

int check_password_strength(char *password)
{
    int strength = 0, i, has_number = 0, has_letter = 0;

    for (i = 0; password[i] != '\0'; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_letter = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_letter = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_number = 1;
        }
    }

    if (has_number && has_letter)
    {
        strength = 80;
    }
    else if (has_number || has_letter)
    {
        strength = 60;
    }
    else
    {
        strength = 20;
    }

    return strength;
}