//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20
#define MAX_ATTEMPTS 3

// This structure will hold each password record
typedef struct {
    char username[MAX_LENGTH+1];
    char password[MAX_LENGTH+1];
} PasswordRecord;

// This function will prompt the user for input and return it as a dynamically-allocated string
char *get_input(char *prompt) {
    char *input = NULL;
    printf("%s: ", prompt);
    size_t input_size;
    getline(&input, &input_size, stdin);
    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';
    return input;
}

// This function will compare two strings in a case-insensitive manner
int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (tolower(*s1) != tolower(*s2))
            return tolower(*s1) - tolower(*s2);
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

// This function will check if a password meets our requirements
int check_password(char *password) {
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else
            has_special = 1;
    }
    return (has_upper && has_lower && has_digit && has_special && length >= 8);
}

// This function will prompt the user for a new password and validate it
void set_password(PasswordRecord *record) {
    char *password;
    do {
        password = get_input("Enter new password");
        if (!check_password(password))
            printf("Password does not meet requirements. Please try again.\n");
    } while (!check_password(password));
    strncpy(record->password, password, MAX_LENGTH+1);
}

// This function will prompt the user for a username and password, and validate them
int verify_password(PasswordRecord *record) {
    char *username = get_input("Enter username");
    char *password = get_input("Enter password");
    int authenticated = (stricmp(record->username, username) == 0) &&
                        (stricmp(record->password, password) == 0);
    free(username);
    free(password);
    return authenticated;
}

int main() {
    PasswordRecord record = {"admin", "password123"};
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        if (verify_password(&record)) {
            printf("Access granted.\n");
            set_password(&record);
            printf("Password changed successfully.\n");
            exit(0);
        } else {
            printf("Access denied.\n");
            attempts++;
        }
    }
    printf("Too many failed attempts. Try again later.\n");
    return 0;
}