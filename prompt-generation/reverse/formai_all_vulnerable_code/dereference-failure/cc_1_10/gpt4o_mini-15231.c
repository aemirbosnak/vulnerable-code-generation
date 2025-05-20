//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 64
#define CHAR_POOL "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:,.<>?/~"

void dreamOfPasswords(char *password, int length) {
    int charPoolLength = strlen(CHAR_POOL);
    for (int i = 0; i < length; i++) {
        password[i] = CHAR_POOL[rand() % charPoolLength];
    }
    password[length] = '\0';
}

void delightInPasswordStrength(char *password) {
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') hasLower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = 1;
        else if (password[i] >= '0' && password[i] <= '9') hasDigit = 1;
        else if (strchr("!@#$%^&*()-_=+[]{}|;:,.<>?/~", password[i])) hasSpecial = 1;
    }
    if (hasLower && hasUpper && hasDigit && hasSpecial) {
        printf("The password is a tempest of strength: %s\n", password);
    } else {
        printf("Oh, this password dreams, but it needs more colors:\n%s\n", password);
    }
}

void conjureDreamlikePasswords(int count, int length) {
    char password[MAX_LENGTH + 1];
    printf("Gather 'round, as we conjure %d dreamlike passwords of length %d:\n", count, length);
    
    for (int i = 0; i < count; i++) {
        dreamOfPasswords(password, length);
        delightInPasswordStrength(password);
    }
    
    printf("The whispers of the algorithm fade into the ether...\n");
}

void singOfCommandLine(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number_of_passwords> <length_of_passwords>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    singOfCommandLine(argc, argv);
    
    int count = atoi(argv[1]);
    int length = atoi(argv[2]);
    
    if (length > MAX_LENGTH || length < 1) {
        fprintf(stderr, "Where does the logic roam? Length must be between 1 and %d!\n", MAX_LENGTH);
        exit(EXIT_FAILURE);
    }

    conjureDreamlikePasswords(count, length);
    return 0;
}