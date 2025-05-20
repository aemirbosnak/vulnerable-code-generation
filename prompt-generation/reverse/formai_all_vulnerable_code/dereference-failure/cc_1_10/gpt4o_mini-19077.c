//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MIN_UPPER 1
#define MIN_LOWER 1
#define MIN_DIGITS 1
#define MIN_SPECIAL 1

void check_password_strength(const char *password) {
    int length = strlen(password);
    int upper_count = 0, lower_count = 0, digit_count = 0, special_count = 0;
    
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_count++;
        } else if (islower(password[i])) {
            lower_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        } else {
            special_count++;
        }
    }

    printf("Password strength summary:\n");
    printf("Length: %d (Minimum required: %d)\n", length, MIN_LENGTH);
    printf("Uppercase letters: %d (Minimum required: %d)\n", upper_count, MIN_UPPER);
    printf("Lowercase letters: %d (Minimum required: %d)\n", lower_count, MIN_LOWER);
    printf("Digits: %d (Minimum required: %d)\n", digit_count, MIN_DIGITS);
    printf("Special characters: %d (Minimum required: %d)\n", special_count, MIN_SPECIAL);

    int score = 0;

    if (length >= MIN_LENGTH) score++;
    if (upper_count >= MIN_UPPER) score++;
    if (lower_count >= MIN_LOWER) score++;
    if (digit_count >= MIN_DIGITS) score++;
    if (special_count >= MIN_SPECIAL) score++;

    printf("Overall password strength score: %d/5\n", score);
    
    if (score == 5) {
        printf("Strong password!\n");
    } else if (score >= 3) {
        printf("Moderate password. Consider adding more complexity.\n");
    } else {
        printf("Weak password! Please enhance your password.\n");
    }
}

void print_usage() {
    printf("Usage: ./password_strength_checker <password>\n");
    printf("Password must be at least %d characters long, with at least:\n", MIN_LENGTH);
    printf("- %d uppercase letters\n", MIN_UPPER);
    printf("- %d lowercase letters\n", MIN_LOWER);
    printf("- %d digits\n", MIN_DIGITS);
    printf("- %d special characters\n", MIN_SPECIAL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    const char *password = argv[1];
    
    check_password_strength(password);
    
    return 0;
}