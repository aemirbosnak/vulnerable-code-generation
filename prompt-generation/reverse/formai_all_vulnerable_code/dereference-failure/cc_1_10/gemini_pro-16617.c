//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the password strength levels
enum PasswordStrength {
    WEAK,
    MODERATE,
    STRONG,
    VERY_STRONG
};

// Define the password complexity criteria
struct PasswordCriteria {
    int minLength;
    int maxRepetitions;
    int minUniqueChars;
    int minSpecialChars;
};

// Initialize the default password complexity criteria
struct PasswordCriteria defaultCriteria = {
    .minLength = 8,
    .maxRepetitions = 3,
    .minUniqueChars = 4,
    .minSpecialChars = 1
};

// Check if the password meets the minimum length requirement
int passwordMeetsMinimumLength(char *password, struct PasswordCriteria criteria) {
    return strlen(password) >= criteria.minLength;
}

// Check if the password contains excessive repetitions
int passwordHasExcessiveRepetitions(char *password, struct PasswordCriteria criteria) {
    int maxRepetitions = criteria.maxRepetitions;
    int currentRepetitions = 0;
    char currentChar = password[0];
    int i;

    for (i = 1; i < strlen(password); i++) {
        if (password[i] == currentChar) {
            currentRepetitions++;
        } else {
            currentChar = password[i];
            currentRepetitions = 0;
        }

        if (currentRepetitions >= maxRepetitions) {
            return 1;
        }
    }

    return 0;
}

// Check if the password contains enough unique characters
int passwordHasEnoughUniqueChars(char *password, struct PasswordCriteria criteria) {
    int minUniqueChars = criteria.minUniqueChars;
    int uniqueChars = 0;
    int i;

    for (i = 0; i < strlen(password); i++) {
        int j;
        int found = 0;

        for (j = 0; j < i; j++) {
            if (password[i] == password[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            uniqueChars++;
        }
    }

    return uniqueChars >= minUniqueChars;
}

// Check if the password contains enough special characters
int passwordHasEnoughSpecialChars(char *password, struct PasswordCriteria criteria) {
    int minSpecialChars = criteria.minSpecialChars;
    int specialChars = 0;
    int i;

    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            specialChars++;
        }
    }

    return specialChars >= minSpecialChars;
}

// Check the strength of the password
enum PasswordStrength checkPasswordStrength(char *password, struct PasswordCriteria criteria) {
    int meetsMinimumLength = passwordMeetsMinimumLength(password, criteria);
    int hasExcessiveRepetitions = passwordHasExcessiveRepetitions(password, criteria);
    int hasEnoughUniqueChars = passwordHasEnoughUniqueChars(password, criteria);
    int hasEnoughSpecialChars = passwordHasEnoughSpecialChars(password, criteria);

    if (!meetsMinimumLength) {
        return WEAK;
    } else if (hasExcessiveRepetitions) {
        return WEAK;
    } else if (!hasEnoughUniqueChars) {
        return MODERATE;
    } else if (!hasEnoughSpecialChars) {
        return STRONG;
    } else {
        return VERY_STRONG;
    }
}

// Get the password strength level as a string
char *getPasswordStrengthString(enum PasswordStrength strength) {
    switch (strength) {
        case WEAK:
            return "Weak";
        case MODERATE:
            return "Moderate";
        case STRONG:
            return "Strong";
        case VERY_STRONG:
            return "Very Strong";
        default:
            return "Unknown";
    }
}

// Prompt the user for a password
char *getpassword(const char *prompt) {
    char *password;
    size_t len;

    printf("%s", prompt);
    getline(&password, &len, stdin);
    password[strcspn(password, "\r\n")] = '\0';

    return password;
}

// Main function
int main() {
    char *password;
    enum PasswordStrength strength;
    char *strengthString;

    // Get the password from the user
    password = getpassword("Enter your password: ");

    // Check the strength of the password
    strength = checkPasswordStrength(password, defaultCriteria);

    // Get the password strength level as a string
    strengthString = getPasswordStrengthString(strength);

    // Print the password strength level
    printf("Your password is %s\n", strengthString);

    // Free the memory allocated for the password
    free(password);

    return 0;
}