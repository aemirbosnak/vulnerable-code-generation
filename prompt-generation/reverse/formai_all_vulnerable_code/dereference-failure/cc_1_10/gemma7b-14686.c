//Gemma-7B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>

char **passwords = NULL;
int num_passwords = 0;

void store_password(char *password)
{
    passwords = realloc(passwords, (num_passwords + 1) * sizeof(char *));
    passwords[num_passwords++] = strdup(password);
}

void generate_password(int length)
{
    char password[length];
    int i;

    for (i = 0; i < length; i++)
    {
        password[i] = rand() % 26 + 'a';
    }

    password[length] = '\0';

    store_password(password);
}

int main()
{
    char *username = getpwuid(getuid())->pw_name;
    time_t now = time(NULL);

    printf("Welcome, %s!", username);
    printf("\nWould you like to:");
    printf("\n1. Generate a new password\n");
    printf("2. View your stored passwords\n");

    int choice = getchar();

    switch (choice)
    {
        case '1':
            generate_password(16);
            printf("Your new password is: %s", passwords[num_passwords - 1]);
            break;
        case '2':
            printf("Your stored passwords are:");
            for (int i = 0; i < num_passwords; i++)
            {
                printf("\n%s", passwords[i]);
            }
            break;
        default:
            printf("Invalid choice.");
    }

    printf("\nTime: %s", now);

    return 0;
}