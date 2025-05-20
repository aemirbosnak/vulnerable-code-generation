//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

struct password {
    char *name;
    char *password;
};

int main() {
    struct password passwords[MAX_PASSWORDS];
    int i, j;

    // Initialize passwords array with random passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = (char *)malloc(MAX_LENGTH * sizeof(char));
        passwords[i].password = (char *)malloc(MAX_LENGTH * sizeof(char));
        for (j = 0; j < MAX_LENGTH; j++) {
            passwords[i].name[j] = 'A' + (rand() % 26);
            passwords[i].password[j] = 'A' + (rand() % 26);
        }
    }

    // Password selection and verification loop
    while (1) {
        printf("Select a password to use: ");
        scanf("%s", passwords[i].name);
        for (j = 0; j < MAX_PASSWORDS; j++) {
            if (strcmp(passwords[j].name, passwords[i].name) == 0) {
                printf("Incorrect password. Try again.\n");
                continue;
            }
        }

        // Verify the password
        if (strcmp(passwords[i].password, passwords[i].name) == 0) {
            printf("Password correct!\n");
            break;
        } else {
            printf("Password incorrect. Try again.\n");
        }
    }

    // Clean up
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].name);
        free(passwords[i].password);
    }

    return 0;
}