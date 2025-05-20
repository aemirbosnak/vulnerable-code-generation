//Falcon2-11B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to check if a password is strong enough
int isStrongPassword(char* password) {
    int minLength = 8;
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    for (int i = 0; password[i]!= '\0'; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (isalpha(password[i])) {
            hasSpecial = 1;
        }
    }

    if (strlen(password) >= minLength && hasUpper && hasLower && hasDigit && hasSpecial) {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate a random password
char* generatePassword() {
    char* password = (char*) malloc(100);
    int length = 0;
    int minLength = 8;
    int maxLength = 16;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;

    while (length < minLength || length > maxLength) {
        srand(time(NULL));
        length = rand() % (maxLength - minLength) + minLength;
        for (int i = 0; i < length; i++) {
            char randomChar = 'A' + (rand() % 26);
            if (isupper(randomChar)) {
                upper++;
            } else if (islower(randomChar)) {
                lower++;
            } else if (isdigit(randomChar)) {
                digit++;
            } else {
                special++;
            }
            password[i] = randomChar;
        }
    }

    if (upper >= 1 && lower >= 1 && digit >= 1 && special >= 1) {
        return password;
    } else {
        return NULL;
    }
}

int main() {
    char* password = generatePassword();
    if (password) {
        printf("Generated password: %s\n", password);
        if (isStrongPassword(password)) {
            printf("Password is strong.\n");
        } else {
            printf("Password is not strong.\n");
        }
        free(password);
    } else {
        printf("Password generation failed.\n");
    }
    return 0;
}