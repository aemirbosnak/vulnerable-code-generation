//Gemma-7B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PASSWORDS 100

typedef struct Password {
    char *name;
    char *password;
    int strength;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (num_passwords < MAX_PASSWORDS) {
        // Get the password name
        printf("Enter password name: ");
        passwords[num_passwords].name = malloc(20);
        scanf("%s", passwords[num_passwords].name);

        // Get the password
        printf("Enter password: ");
        passwords[num_passwords].password = malloc(20);
        scanf("%s", passwords[num_passwords].password);

        // Calculate password strength
        passwords[num_passwords].strength = calculate_strength(passwords[num_passwords].password);

        // Increment the number of passwords
        num_passwords++;
    }

    // Print the passwords
    for (int i = 0; i < num_passwords; i++) {
        printf("Password name: %s\n", passwords[i].name);
        printf("Password: %s\n", passwords[i].password);
        printf("Strength: %d\n", passwords[i].strength);
        printf("\n");
    }

    return 0;
}

int calculate_strength(char *password) {
    int strength = 0;

    // Check for uppercase letters
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
        }
    }

    // Check for numbers
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
        }
    }

    // Check for symbols
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '!' && password[i] <= '@') {
            strength++;
        }
    }

    return strength;
}