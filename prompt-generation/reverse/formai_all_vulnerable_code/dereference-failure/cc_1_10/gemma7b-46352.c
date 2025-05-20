//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_password(char *pass)
{
    int len = strlen(pass);
    int strong = 0;

    if (len >= 8)
    {
        strong++;
    }

    if (pass[0] >= 'a' && pass[0] <= 'z')
    {
        strong++;
    }

    if (pass[len - 1] >= 'a' && pass[len - 1] <= 'z')
    {
        strong++;
    }

    if (strchr(pass, '$') || strchr(pass, '%') || strchr(pass, '&') || strchr(pass, '*'))
    {
        strong++;
    }

    if (strong >= 4)
    {
        printf("Your password is strong!\n");
    }
    else
    {
        printf("Your password is not strong enough. Please try again.\n");
    }
}

int main()
{
    char pass[20];

    printf("Enter your password: ");
    scanf("%s", pass);

    check_password(pass);

    return 0;
}