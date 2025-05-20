//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASS_LEN 256

char *get_pass(void)
{
    char *pass = malloc(MAX_PASS_LEN);
    printf("Enter your password: ");
    fgets(pass, MAX_PASS_LEN, stdin);
    return pass;
}

int main(void)
{
    char *pass = get_pass();
    int strength = check_pass_strength(pass);
    switch (strength)
    {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is acceptable.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
    }
    free(pass);
    return 0;
}

int check_pass_strength(char *pass)
{
    int strength = 0;
    if (strlen(pass) >= 8)
    {
        strength++;
    }
    if (has_upper(pass))
    {
        strength++;
    }
    if (has_number(pass))
    {
        strength++;
    }
    if (has_symbol(pass))
    {
        strength++;
    }
    return strength;
}

int has_upper(char *pass)
{
    for (int i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            return 1;
        }
    }
    return 0;
}

int has_number(char *pass)
{
    for (int i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= '0' && pass[i] <= '9')
        {
            return 1;
        }
    }
    return 0;
}

int has_symbol(char *pass)
{
    for (int i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= '!' && pass[i] <= '~')
        {
            return 1;
        }
    }
    return 0;
}