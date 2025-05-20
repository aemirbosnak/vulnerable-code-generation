//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>

/* Function to generate a secure password */
char* generate_password(int length)
{
    char* password = malloc(length * sizeof(char)); // allocate memory for password
    int i;

    /* Characters that can be used in password */
    const char char_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+=";
    int set_length = sizeof(char_set) - 1; // get length of character set

    /* Seed the random number generator */
    srand(time(NULL));

    /* Loop through password length to generate password */
    for(i=0; i<length; i++)
    {
        password[i] = char_set[rand() % set_length]; // choose random character from character set
    }

    password[length] = '\0'; // add null terminator to end of password

    return password; // return password
}

/* Main function */
int main()
{
    int length;
    char* password;

    /* Prompt user for password length */
    printf("Enter password length: ");
    scanf("%d", &length);

    /* Generate password */
    password = generate_password(length);

    /* Print password */
    printf("Your secure password is: %s\n", password);

    /* Free allocated memory */
    free(password);

    return 0;
}