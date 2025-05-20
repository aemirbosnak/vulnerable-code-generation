//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define PASSWORD_LENGTH (sizeof(password) / sizeof(password[0]))

char password[MIN_LENGTH] = {0};
int hasUppercase = 0;
int hasLowercase = 0;
int hasDigit = 0;
int hasSpecialChar = 0;
int hasWhitespace = 0;

void checkPasswordStrength() {
    int i;

    if (strlen(password) < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return;
    }

    for (i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (isalpha(password[i])) {
            if (isupper(password[i])) {
                hasUppercase = 1;
            } else {
                hasLowercase = 1;
            }
        } else if (strchr("!@#$%^&*", password[i])) {
            hasSpecialChar = 1;
        } else {
            hasWhitespace = 1;
            printf("Password contains whitespace characters.\n");
            return;
        }
    }

    if (!hasUppercase || !hasLowercase || !hasDigit || !hasSpecialChar) {
        printf("Password is weak. It must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return;
    }

    printf("Password is strong.\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(password, argv[1]);

    checkPasswordStrength();

    return 0;
}