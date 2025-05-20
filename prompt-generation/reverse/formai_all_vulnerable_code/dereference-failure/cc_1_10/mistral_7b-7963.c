//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MIN_UPPER 1
#define MIN_LOWER 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

typedef struct {
    int upper;
    int lower;
    int digit;
    int special;
} Checker;

Checker check_password(const char *password) {
    Checker result;
    int i, length = strlen(password);

    result.upper = 0;
    result.lower = 0;
    result.digit = 0;
    result.special = 0;

    for (i = 0; i < length; ++i) {
        if (isupper(password[i])) {
            ++result.upper;
        }

        if (islower(password[i])) {
            ++result.lower;
        }

        if (isdigit(password[i])) {
            ++result.digit;
        }

        if (strchr("!@#$%^&*()-_+=[]{}|;:,.<>/?`~", password[i])) {
            ++result.special;
        }
    }

    return result;
}

void print_result(const Checker *checker) {
    if (checker->upper && checker->lower && checker->digit && checker->special) {
        printf("Password is strong.\n");
    } else if (checker->upper && checker->lower && checker->digit) {
        printf("Password is moderate.\n");
    } else {
        printf("Password is weak.\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s password\n", argv[0]);
        return 1;
    }

    const Checker check = check_password(argv[1]);

    print_result(&check);

    return 0;
}