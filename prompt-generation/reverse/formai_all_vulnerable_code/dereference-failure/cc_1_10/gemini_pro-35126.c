//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define OK 1
#define GOOD 2
#define STRONG 3

// Define the password requirements
#define MIN_LENGTH 8
#define MAX_LENGTH 128
#define MIN_UPPER_CASE 1
#define MIN_LOWER_CASE 1
#define MIN_DIGITS 1
#define MIN_SPECIAL_CHARS 1

// Define the special characters
#define SPECIAL_CHARS "!@#$%^&*()-_+="

// Check if the password is long enough
int check_length(char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Your password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
        return WEAK;
    } else if (length > MAX_LENGTH) {
        printf("Your password is too long. It must be less than %d characters long.\n", MAX_LENGTH);
        return WEAK;
    } else {
        return OK;
    }
}

// Check if the password contains enough upper case letters
int check_upper_case(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    if (count < MIN_UPPER_CASE) {
        printf("Your password does not contain enough upper case letters. It must contain at least %d upper case letters.\n", MIN_UPPER_CASE);
        return WEAK;
    } else {
        return OK;
    }
}

// Check if the password contains enough lower case letters
int check_lower_case(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    if (count < MIN_LOWER_CASE) {
        printf("Your password does not contain enough lower case letters. It must contain at least %d lower case letters.\n", MIN_LOWER_CASE);
        return WEAK;
    } else {
        return OK;
    }
}

// Check if the password contains enough digits
int check_digits(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    if (count < MIN_DIGITS) {
        printf("Your password does not contain enough digits. It must contain at least %d digits.\n", MIN_DIGITS);
        return WEAK;
    } else {
        return OK;
    }
}

// Check if the password contains enough special characters
int check_special_chars(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (strchr(SPECIAL_CHARS, password[i]) != NULL) {
            count++;
        }
    }
    if (count < MIN_SPECIAL_CHARS) {
        printf("Your password does not contain enough special characters. It must contain at least %d special characters.\n", MIN_SPECIAL_CHARS);
        return WEAK;
    } else {
        return OK;
    }
}

// Check the strength of the password
int check_strength(char *password) {
    int strength = WEAK;

    // Check the length of the password
    if (check_length(password) == OK) {
        strength++;
    }

    // Check if the password contains enough upper case letters
    if (check_upper_case(password) == OK) {
        strength++;
    }

    // Check if the password contains enough lower case letters
    if (check_lower_case(password) == OK) {
        strength++;
    }

    // Check if the password contains enough digits
    if (check_digits(password) == OK) {
        strength++;
    }

    // Check if the password contains enough special characters
    if (check_special_chars(password) == OK) {
        strength++;
    }

    return strength;
}

// Get the password from the user
char *get_password(void) {
    char *password = NULL;
    size_t len = 0;

    printf("Enter your password: ");
    getline(&password, &len, stdin);

    return password;
}

// Print the strength of the password
void print_strength(int strength) {
    switch (strength) {
        case WEAK:
            printf("Your password is weak. Please try again.\n");
            break;
        case OK:
            printf("Your password is OK. It could be stronger though.\n");
            break;
        case GOOD:
            printf("Your password is good. It is strong enough to protect your account.\n");
            break;
        case STRONG:
            printf("Your password is strong. It is very difficult to crack.\n");
            break;
    }
}

// Main function
int main(void) {
    char *password;
    int strength;

    // Get the password from the user
    password = get_password();

    // Check the strength of the password
    strength = check_strength(password);

    // Print the strength of the password
    print_strength(strength);

    // Free the memory allocated for the password
    free(password);

    return 0;
}