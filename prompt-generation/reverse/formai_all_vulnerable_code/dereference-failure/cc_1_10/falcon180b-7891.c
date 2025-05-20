//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32
#define PASSWORD_LOWER_CASE "abcdefghijklmnopqrstuvwxyz"
#define PASSWORD_UPPER_CASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define PASSWORD_NUMBERS "0123456789"
#define PASSWORD_SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>/?`~"

int is_password_valid(char *password);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    char *password = argv[1];
    if (is_password_valid(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }

    return 0;
}

int is_password_valid(char *password) {
    int length = strlen(password);
    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        return 0;
    }

    int has_lower_case = 0;
    int has_upper_case = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (strchr(PASSWORD_LOWER_CASE, c)) {
            has_lower_case = 1;
        } else if (strchr(PASSWORD_UPPER_CASE, c)) {
            has_upper_case = 1;
        } else if (strchr(PASSWORD_NUMBERS, c)) {
            has_number = 1;
        } else if (strchr(PASSWORD_SPECIAL_CHARS, c)) {
            has_special_char = 1;
        }
    }

    if (!has_lower_case ||!has_upper_case ||!has_number ||!has_special_char) {
        return 0;
    }

    return 1;
}