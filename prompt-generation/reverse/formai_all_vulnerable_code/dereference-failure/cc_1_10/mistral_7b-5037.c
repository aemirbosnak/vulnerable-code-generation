//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK_POINTS 3

typedef struct {
    char password[MIN_LENGTH + 1];
    int num_digits;
    int num_uppercase;
    int num_lowercase;
    int num_special_chars;
} Password;

void count_chars(const char *str, Password *password) {
    int i;
    memset(password, 0, sizeof(Password));

    for (i = 0; str[i] != '\0'; ++i) {
        if (isdigit(str[i])) {
            password->num_digits++;
        } else if (isupper(str[i])) {
            password->num_uppercase++;
        } else if (islower(str[i])) {
            password->num_lowercase++;
        } else {
            password->num_special_chars++;
        }
    }
}

int check_strength(const Password *password) {
    int strength = 0;

    if (password->num_digits >= 2) strength++;
    if (password->num_uppercase >= 2) strength++;
    if (password->num_lowercase >= 2) strength++;
    if (password->num_special_chars >= 1) strength++;

    if (strength < WEAK_POINTS) return 0;

    if (strlen(password->password) >= MIN_LENGTH) {
        strength += (strlen(password->password) - MIN_LENGTH) / 2;
    }

    return strength;
}

int main(int argc, char **argv) {
    char input[1024];
    Password password;

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    count_chars(input, &password);

    if (check_strength(&password) > 0) {
        printf("Password '%s' is strong.\n", input);
    } else {
        printf("Password '%s' is weak. Consider adding numbers, uppercase letters, lowercase letters, and special characters.\n", input);
    }

    return 0;
}