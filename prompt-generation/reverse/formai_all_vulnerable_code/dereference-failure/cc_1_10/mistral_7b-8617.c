//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LENGTH 16
#define NUM 10
#define LOWER 32
#define UPPER 64
#define DIGITS 52
#define SPECIAL 43

char *generatePassword(int length)
{
    char *password = malloc(length + 1);
    int random;
    int count = 0;

    if (password == NULL)
    {
        fprintf(stderr, "Memory error!\n");
        return NULL;
    }

    srand(time(NULL));

    for (int i = 0; i < length; i++)
    {
        random = rand() % 100;
        if (random < NUM)
        {
            password[i] = rand() % 10 + '0';
            count++;
        }
        else if (random < NUM + LOWER)
        {
            password[i] = rand() % 26 + 'a';
            count++;
        }
        else if (random < NUM + LOWER + UPPER)
        {
            password[i] = rand() % 26 + 'A';
            count++;
        }
        else
        {
            password[i] = rand() % SPECIAL + '!';
        }
    }

    password[length] = '\0';

    if (count != length)
    {
        fprintf(stderr, "Password length error!\n");
        free(password);
        return NULL;
    }

    return password;
}

int main()
{
    char *password;
    int length;

    printf("Enter password length: ");
    scanf("%d", &length);

    if (length > LENGTH)
    {
        printf("Password length too long!\n");
        return 1;
    }

    password = generatePassword(length);

    if (password != NULL)
    {
        printf("Generated password: %s\n", password);
        free(password);
    }

    return 0;
}