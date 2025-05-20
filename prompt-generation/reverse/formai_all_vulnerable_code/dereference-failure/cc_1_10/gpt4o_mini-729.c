//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

typedef struct {
    int has_upper;
    int has_lower;
    int has_digit;
    int has_special;
} PasswordCriteria;

void check_password_strength(const char *password, PasswordCriteria *criteria) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) criteria->has_upper = 1;
        else if (islower(password[i])) criteria->has_lower = 1;
        else if (isdigit(password[i])) criteria->has_digit = 1;
        else if (ispunct(password[i])) criteria->has_special = 1;
    }
}

int is_valid_length(const char *password) {
    int len = strlen(password);
    return len >= MIN_LENGTH && len <= MAX_LENGTH;
}

void print_strength_message(PasswordCriteria criteria) {
    int total_criteria = criteria.has_upper + criteria.has_lower + criteria.has_digit + criteria.has_special;

    if (total_criteria == 4) {
        printf("Your password strength: Strong\n");
    } else if (total_criteria == 3) {
        printf("Your password strength: Moderate\n");
    } else {
        printf("Your password strength: Weak\n");
    }
}

void get_password(char *password) {
    printf("Enter your password: ");
    // Using a safe method to read string input
    fgets(password, MAX_LENGTH + 2, stdin); // +2 for newline and null terminator
    password[strcspn(password, "\n")] = 0; // Remove newline character
}

int main() {
    char password[MAX_LENGTH + 1];
    PasswordCriteria criteria = {0, 0, 0, 0};

    // The password is obtained from user's input
    get_password(password);

    // Length validation
    if (!is_valid_length(password)) {
        printf("Password must be between %d and %d characters long.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // Check the various criteria
    check_password_strength(password, &criteria);

    // Provide feedback on strength
    print_strength_message(criteria);

    return 0;
}