//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define DIGITS "0123456789"
#define LOWER "abcdefghijklmnopqrstuvwxyz"
#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define SYMBOLS "!@#$%^&*()_+-=[]{}|;:,.<>?/~`"

typedef struct {
    int length;
    int hasDigit;
    int hasLower;
    int hasUpper;
    int hasSymbol;
} PasswordStats;

void print_stats(const PasswordStats *stats) {
    printf("Password length: %d\n", stats->length);
    printf("Has digit: %s\n", stats->hasDigit ? "Yes" : "No");
    printf("Has lowercase: %s\n", stats->hasLower ? "Yes" : "No");
    printf("Has uppercase: %s\n", stats->hasUpper ? "Yes" : "No");
    printf("Has symbol: %s\n", stats->hasSymbol ? "Yes" : "No");
}

PasswordStats check_password(const char *password) {
    PasswordStats stats = {0};
    int i;

    stats.length = strlen(password);

    for (i = 0; password[i] != '\0'; ++i) {
        if (isdigit(password[i])) {
            stats.hasDigit = 1;
            break;
        }
    }

    for (i = 0; password[i] != '\0'; ++i) {
        if (islower(password[i])) {
            stats.hasLower = 1;
            break;
        }
    }

    for (i = 0; password[i] != '\0'; ++i) {
        if (isupper(password[i])) {
            stats.hasUpper = 1;
            break;
        }
    }

    for (i = 0; password[i] != '\0'; ++i) {
        if (strchr(SYMBOLS, password[i]) != NULL) {
            stats.hasSymbol = 1;
            break;
        }
    }

    return stats;
}

int main(int argc, char *argv[]) {
    char password[MIN_LENGTH + 1];
    PasswordStats stats;

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(password, argv[1]);

    stats = check_password(password);
    print_stats(&stats);

    return 0;
}