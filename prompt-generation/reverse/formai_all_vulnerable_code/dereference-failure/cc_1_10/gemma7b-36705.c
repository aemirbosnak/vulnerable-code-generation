//Gemma-7B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct Password
{
    char *name;
    char *password;
    int used;
} Password;

Password passwords[MAX_PASSWORDS];

void generate_passwords()
{
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        passwords[i].name = malloc(MAX_PASSWORD_LENGTH);
        passwords[i].password = malloc(MAX_PASSWORD_LENGTH);

        passwords[i].name[0] = '\0';
        passwords[i].password[0] = '\0';

        passwords[i].used = 0;
    }
}

void add_password(char *name, char *password)
{
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (!passwords[i].used)
        {
            strcpy(passwords[i].name, name);
            strcpy(passwords[i].password, password);

            passwords[i].used = 1;

            return;
        }
    }

    printf("Error: Maximum number of passwords exceeded.\n");
}

void print_passwords()
{
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (passwords[i].used)
        {
            printf("%s: %s\n", passwords[i].name, passwords[i].password);
        }
    }
}

int main()
{
    generate_passwords();

    add_password("John Doe", "Secret123");
    add_password("Jane Doe", "StrongPassword");
    add_password("Guest", "TemporaryPassword");

    print_passwords();

    return 0;
}