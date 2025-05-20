//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

char * generate_random_password()
{
    const char LOWERCASE[] = "abcdefghijklmnopqrstuvwxyz";
    const char UPPERCASE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char NUMBERS[] = "0123456789";
    const char SYMBOLS[] = "!@#$%^&*()_+-=[]{}|;':,.<>?";

    char * password = malloc((PASSWORD_LENGTH + 1) * sizeof(char));
    int i, j;

    srand(time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        j = rand() % 4;

        switch (j) {
            case 0:
                password[i] = LOWERCASE[rand() % 26];
                break;
            case 1:
                password[i] = UPPERCASE[rand() % 26];
                break;
            case 2:
                password[i] = NUMBERS[rand() % 10];
                break;
            case 3:
                password[i] = SYMBOLS[rand() % 19];
                break;
        }
    }

    password[PASSWORD_LENGTH] = '\0';

    return password;
}

int main()
{
    char * password = generate_random_password();

    printf("Your new password is: %s\n", password);

    free(password);

    return 0;
}