//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

// Function prototypes
int isLengthValid(const char *password);
int hasUpperCase(const char *password);
int hasLowerCase(const char *password);
int hasDigit(const char *password);
int hasSpecialChar(const char *password);
void printStrength(int score);

int main() {
    char password[MAX_LENGTH + 1];
    
    printf("Enter your password (8 to 20 characters): ");
    scanf("%20s", password);  // Limit input to 20 characters

    int score = 0;

    if (isLengthValid(password)) {
        score++;
    }
    if (hasUpperCase(password)) {
        score++;
    }
    if (hasLowerCase(password)) {
        score++;
    }
    if (hasDigit(password)) {
        score++;
    }
    if (hasSpecialChar(password)) {
        score++;
    }

    printStrength(score);

    return 0;
}

// Validate password length
int isLengthValid(const char *password) {
    int length = strlen(password);
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

// Check for at least one uppercase letter
int hasUpperCase(const char *password) {
    while (*password) {
        if (isupper((unsigned char)*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Check for at least one lowercase letter
int hasLowerCase(const char *password) {
    while (*password) {
        if (islower((unsigned char)*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Check for at least one digit
int hasDigit(const char *password) {
    while (*password) {
        if (isdigit((unsigned char)*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Check for at least one special character
int hasSpecialChar(const char *password) {
    const char* specialChars = "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~";
    while (*password) {
        if (strchr(specialChars, *password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Print password strength based on score
void printStrength(int score) {
    switch(score) {
        case 0:
        case 1:
            printf("Weak password. Please choose a stronger one.\n");
            break;
        case 2:
            printf("Moderate password strength. Consider making it stronger.\n");
            break;
        case 3:
            printf("Good password strength. But you can still improve it!\n");
            break;
        case 4:
        case 5:
            printf("Strong password! Well done!\n");
            break;
        default:
            printf("Error in scoring.\n");
    }
}