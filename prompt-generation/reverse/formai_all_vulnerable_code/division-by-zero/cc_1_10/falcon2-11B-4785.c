//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// A function to check password strength
int checkPasswordStrength(char* password) {
    int length = strlen(password);
    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int digitCount = 0;
    int specialCharCount = 0;

    // Count lowercase characters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercaseCount++;
        }
    }

    // Count uppercase characters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercaseCount++;
        }
    }

    // Count digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digitCount++;
        }
    }

    // Count special characters
    for (int i = 0; i < length; i++) {
        if (isalnum(password[i])) {
            specialCharCount++;
        }
    }

    // Calculate password strength
    int strength = (lowercaseCount + uppercaseCount + digitCount + specialCharCount);
    strength = (strength / length) * 100;
    strength = strength > 0? strength : 0;

    printf("Password strength: %d%%\n", strength);

    return strength >= 80;
}

int main() {
    char password[100];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character from input
    password[strcspn(password, "\n")] = '\0';

    checkPasswordStrength(password);

    return 0;
}