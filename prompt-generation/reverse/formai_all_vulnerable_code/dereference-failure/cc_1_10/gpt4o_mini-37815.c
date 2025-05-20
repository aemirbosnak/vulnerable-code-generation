//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8

typedef struct {
    int length;
    int upper;
    int lower;
    int digits;
    int special;
} PasswordCriteria;

void printUsage() {
    printf("Usage: PasswordStrengthChecker <password>\n");
}

PasswordCriteria analyzePassword(const char *password) {
    PasswordCriteria criteria = {0, 0, 0, 0, 0};
    criteria.length = strlen(password);
    
    for (int i = 0; i < criteria.length; i++) {
        if (isupper(password[i])) {
            criteria.upper++;
        } else if (islower(password[i])) {
            criteria.lower++;
        } else if (isdigit(password[i])) {
            criteria.digits++;
        } else {
            criteria.special++;
        }
    }
    
    return criteria;
}

void printCriteria(const PasswordCriteria *criteria) {
    printf("Password Analysis:\n");
    printf("Length: %d\n", criteria->length);
    printf("Uppercase letters: %d\n", criteria->upper);
    printf("Lowercase letters: %d\n", criteria->lower);
    printf("Digits: %d\n", criteria->digits);
    printf("Special characters: %d\n", criteria->special);
}

int assessStrength(const PasswordCriteria *criteria) {
    int score = 0;

    // Length check
    if (criteria->length >= MIN_LENGTH) score += 1;

    // Uppercase letter check
    if (criteria->upper > 0) score += 1;

    // Lowercase letter check
    if (criteria->lower > 0) score += 1;

    // Digit check
    if (criteria->digits > 0) score += 1;

    // Special characters check
    if (criteria->special > 0) score += 1;

    return score;
}

void printStrength(int score) {
    printf("Password Strength: ");
    switch (score) {
        case 0:
        case 1:
            printf("Very Weak\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        case 3:
            printf("Moderate\n");
            break;
        case 4:
            printf("Strong\n");
            break;
        case 5:
            printf("Very Strong\n");
            break;
        default:
            printf("Error in scoring.\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *password = argv[1];
    PasswordCriteria criteria = analyzePassword(password);

    printCriteria(&criteria);
    
    int strengthScore = assessStrength(&criteria);
    
    printStrength(strengthScore);

    return EXIT_SUCCESS;
}