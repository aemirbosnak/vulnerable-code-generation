//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

int main(int argc, char *argv[]) {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(password, argv[1]);
    length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (isupper(c)) {
                uppercase_count++;
            } else {
                lowercase_count++;
            }
        } else if (isdigit(c)) {
            digit_count++;
        } else {
            special_count++;
        }
    }

    int total_count = uppercase_count + lowercase_count + digit_count + special_count;
    double strength = (double)total_count / length;

    printf("Password strength: %.2f\n", strength);

    return 0;
}