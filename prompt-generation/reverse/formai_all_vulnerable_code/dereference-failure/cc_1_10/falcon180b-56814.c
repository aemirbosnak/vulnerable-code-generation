//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 1024

int is_valid_password(const char *password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Password must be between 8 and %d characters long.\n", MAX_PASSWORD_LENGTH);
        return 0;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            has_uppercase |= isupper(c);
            has_lowercase |= islower(c);
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }
    const char *password = argv[1];
    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid.\n");
    }
    return 0;
}