//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 8

/* Random password generator */
char* generate_password(int length) {
    int i;
    char* password = malloc(length + 1);
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        int index = rand() % (int) (sizeof(charset) - 1);
        password[i] = charset[index];
    }
    password[length] = '\0';
    return password;
}

/* Check if password is secure */
int is_secure(char* password) {
    int i;
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    for (i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    return (has_upper && has_lower && has_digit && has_special);
}

int main() {
    char* password = NULL;

    printf("Secure Password Generator\n");

    do {
        int length = 0;
        printf("Enter the length of password (minimum %d, maximum %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);
        while (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid length. Please enter a number between %d and %d: ", MIN_LENGTH, MAX_LENGTH);
            scanf("%d", &length);
        }

        password = generate_password(length);

    } while (!is_secure(password));

    printf("Your password is: %s\n", password);

    free(password);
    return 0;
}