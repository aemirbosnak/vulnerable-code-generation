//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

int hasUpperCase(const char* password) {
    while (*password) {
        if (isupper(*password)) return 1;
        password++;
    }
    return 0;
}

int hasLowerCase(const char* password) {
    while (*password) {
        if (islower(*password)) return 1;
        password++;
    }
    return 0;
}

int hasDigit(const char* password) {
    while (*password) {
        if (isdigit(*password)) return 1;
        password++;
    }
    return 0;
}

int hasSpecialChar(const char* password) {
    const char* specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";
    while (*password) {
        if (strchr(specialChars, *password)) return 1;
        password++;
    }
    return 0;
}

int isLengthValid(const char* password) {
    int length = strlen(password);
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

void checkPasswordStrength(const char* password) {
    if (!isLengthValid(password)) {
        printf("Password must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        return;
    }

    int strengthScore = 0;
    strengthScore += hasUpperCase(password) ? 1 : 0;
    strengthScore += hasLowerCase(password) ? 1 : 0;
    strengthScore += hasDigit(password) ? 1 : 0;
    strengthScore += hasSpecialChar(password) ? 1 : 0;

    switch (strengthScore) {
        case 0:
        case 1:
            printf("Password strength: Very Weak\n");
            break;
        case 2:
            printf("Password strength: Weak\n");
            break;
        case 3:
            printf("Password strength: Strong\n");
            break;
        case 4:
            printf("Password strength: Very Strong\n");
            break;
        default:
            printf("Error: Unable to assess password strength.\n");
    }
}

int main(int argc, char* argv[]) {
    char password[MAX_LENGTH + 1];

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(password, argv[1], MAX_LENGTH);
    password[MAX_LENGTH] = '\0';  // Ensuring null termination

    printf("Checking the strength of your password: \"%s\"\n", password);
    checkPasswordStrength(password);

    return EXIT_SUCCESS;
}