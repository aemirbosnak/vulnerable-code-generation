//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PW_MIN_LEN 8
#define PW_MAX_LEN 32

typedef enum {
    PW_STRENGTH_WEAK,
    PW_STRENGTH_MEDIUM,
    PW_STRENGTH_STRONG,
    PW_STRENGTH_VERY_STRONG
} password_strength_t;

static const char *pw_strength_strs[] = {
    "Weak",
    "Medium",
    "Strong",
    "Very Strong"
};

static int pw_contains_alpha(const char *pw) {
    int i;

    for (i = 0; pw[i] != '\0'; i++) {
        if (isalpha(pw[i])) {
            return 1;
        }
    }

    return 0;
}

static int pw_contains_digit(const char *pw) {
    int i;

    for (i = 0; pw[i] != '\0'; i++) {
        if (isdigit(pw[i])) {
            return 1;
        }
    }

    return 0;
}

static int pw_contains_special(const char *pw) {
    int i;

    for (i = 0; pw[i] != '\0'; i++) {
        if (ispunct(pw[i])) {
            return 1;
        }
    }

    return 0;
}

static int pw_length(const char *pw) {
    int i;

    for (i = 0; pw[i] != '\0'; i++);

    return i;
}

static password_strength_t pw_strength(const char *pw) {
    int score = 0;

    if (pw_length(pw) < PW_MIN_LEN) {
        return PW_STRENGTH_WEAK;
    }

    if (pw_contains_alpha(pw)) {
        score++;
    }

    if (pw_contains_digit(pw)) {
        score++;
    }

    if (pw_contains_special(pw)) {
        score++;
    }

    if (pw_length(pw) >= PW_MAX_LEN) {
        score++;
    }

    switch (score) {
        case 1:
        case 2:
            return PW_STRENGTH_WEAK;
        case 3:
            return PW_STRENGTH_MEDIUM;
        case 4:
            return PW_STRENGTH_STRONG;
        case 5:
            return PW_STRENGTH_VERY_STRONG;
    }

    return PW_STRENGTH_WEAK;
}

int main(int argc, char **argv) {
    char pw[PW_MAX_LEN + 1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(pw, argv[1], PW_MAX_LEN);
    pw[PW_MAX_LEN] = '\0';

    printf("Password strength: %s\n", pw_strength_strs[pw_strength(pw)]);

    return EXIT_SUCCESS;
}