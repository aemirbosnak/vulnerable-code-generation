//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>

// Function to check password strength
int checkPasswordStrength(char* password)
{
    // Check for password length
    if (strlen(password) < 6)
        return 0;

    // Check for uppercase characters
    if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", password[0]) == NULL)
        return 0;

    // Check for lowercase characters
    if (strchr("abcdefghijklmnopqrstuvwxyz", password[0]) == NULL)
        return 0;

    // Check for digits
    if (strchr("0123456789", password[0]) == NULL)
        return 0;

    // Check for special characters
    if (strchr("!@#$%^&*()-_+={}[]|:;<>,.?","") == NULL)
        return 0;

    // Check for repetition
    for (int i = 0; i < strlen(password) - 1; i++) {
        if (password[i] == password[i + 1])
            return 0;
    }

    // Password is strong
    return 1;
}

// Function to get password input
char* getPassword()
{
    int len = 0;
    printf("Enter password: ");
    char* password = malloc(sizeof(char) * 100);
    fgets(password, 100, stdin);
    len = strlen(password);
    password[len - 1] = '\0';
    return password;
}

// Function to print password strength
void printPasswordStrength(int strength)
{
    if (strength == 0)
        printf("Weak password\n");
    else if (strength == 1)
        printf("Medium password\n");
    else
        printf("Strong password\n");
}

int main()
{
    char* password = getPassword();
    int strength = checkPasswordStrength(password);
    printPasswordStrength(strength);
    free(password);
    return 0;
}