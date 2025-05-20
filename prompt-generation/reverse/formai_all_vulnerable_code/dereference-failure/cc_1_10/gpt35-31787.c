//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASS_SIZE 12

// Function to generate a random character
char rand_char(void)
{
    int num = rand() % 3;
    char c;

    switch(num)
    {
        case 0:
            c = rand() % 10 + '0';  // Digit
            break;
        case 1:
            c = rand() % 26 + 'a';  // Lowercase letter
            break;
        case 2:
            c = rand() % 26 + 'A';  // Uppercase letter
            break;
    }

    return c;
}

// Function to generate a secure random password
char* gen_password(void)
{
    char* password = (char*)malloc(PASS_SIZE+1);
    int i;

    srand(time(NULL));  // Seed the random number generator

    for(i = 0; i < PASS_SIZE; i++)
    {
        password[i] = rand_char();
    }

    password[PASS_SIZE] = '\0';  // Null-terminate the password string

    return password;
}

int main(void)
{
    char* password;

    printf("Generating a secure password...\n");
    password = gen_password();
    printf("Your new password is: %s\n", password);

    free(password);

    return 0;
}