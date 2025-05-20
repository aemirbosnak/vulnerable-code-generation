//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of the password and the number of times to repeat the password
#define MAX_PASSWORD_LENGTH 20
#define REPEAT_PASSWORD_COUNT 3

// Define a struct to store the password and its repeat counts
typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int repeat_counts[REPEAT_PASSWORD_COUNT];
} password_struct;

// Define a function to prompt the user for their password
void get_password(password_struct *password) {
    printf("Enter your password: ");
    fgets(password->password, MAX_PASSWORD_LENGTH, stdin);
}

// Define a function to check if the password is valid
bool validate_password(password_struct *password) {
    int i;
    for (i = 0; i < REPEAT_PASSWORD_COUNT; i++) {
        if (password->repeat_counts[i] != 0 && strcmp(password->password, password->repeat_counts[i]) != 0) {
            return false;
        }
    }
    return true;
}

// Define a function to store the password and its repeat counts
void store_password(password_struct *password) {
    int i;
    for (i = 0; i < REPEAT_PASSWORD_COUNT; i++) {
        password->repeat_counts[i] = get_repeat_count(password->password, i);
    }
}

// Define a function to get the repeat count of a character in the password
int get_repeat_count(char *password, int index) {
    int repeat_count = 0;
    while (index < strlen(password) && password[index] == password[index + 1]) {
        repeat_count++;
        index++;
    }
    return repeat_count;
}

int main() {
    password_struct password;

    // Prompt the user for their password
    get_password(&password);

    // Check if the password is valid
    if (!validate_password(&password)) {
        printf("Invalid password. Try again!\n");
        return 1;
    }

    // Store the password and its repeat counts
    store_password(&password);

    // Print the password and its repeat counts
    printf("Your password is: %s\n", password.password);
    for (int i = 0; i < REPEAT_PASSWORD_COUNT; i++) {
        printf("Repeat count %d: %d\n", i + 1, password.repeat_counts[i]);
    }

    return 0;
}