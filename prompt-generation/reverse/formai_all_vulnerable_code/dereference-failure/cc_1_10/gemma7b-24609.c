//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void decrypt(char **pw, int strength)
{
    system("rm -rf .tmp");
    system("touch .tmp");
    FILE *fp = fopen(".tmp", "w");
    fprintf(fp, "Strength: %d\n", strength);
    fclose(fp);
    system("cat .tmp");
    system("rm -f .tmp");
}

int main()
{
    char **pw = malloc(100);
    printf("Enter your password: ");
    fgets(pw, 100, stdin);
    int strength = password_strength(pw);
    decrypt(pw, strength);
    free(pw);

    return 0;
}

int password_strength(char *pw)
{
    int strength = 0;
    if (strlen(pw) >= 8) strength++;
    if (has_upper(pw)) strength++;
    if (has_number(pw)) strength++;
    if (has_symbol(pw)) strength++;

    return strength;
}

int has_upper(char *pw)
{
    for (int i = 0; pw[i] != '\0'; i++)
    {
        if (pw[i] >= 'A' && pw[i] <= 'Z') return 1;
    }

    return 0;
}

int has_number(char *pw)
{
    for (int i = 0; pw[i] != '\0'; i++)
    {
        if (pw[i] >= '0' && pw[i] <= '9') return 1;
    }

    return 0;
}

int has_symbol(char *pw)
{
    for (int i = 0; pw[i] != '\0'; i++)
    {
        if (pw[i] >= '`' && pw[i] <= 'z') return 1;
    }

    return 0;
}