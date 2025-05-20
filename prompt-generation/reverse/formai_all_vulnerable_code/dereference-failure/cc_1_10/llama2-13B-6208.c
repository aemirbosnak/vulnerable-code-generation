//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 64

struct password {
    char *name;
    char *password;
};

int main() {
    struct password passwords[MAX_PASSWORDS];
    int i;

    // Initialize passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = malloc(MAX_LENGTH);
        passwords[i].password = malloc(MAX_LENGTH);
        passwords[i].name[0] = '\0';
        passwords[i].password[0] = '\0';
    }

    // Add passwords
    printf("Enter passwords:\n");
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("Name: ");
        fgets(passwords[i].name, MAX_LENGTH, stdin);
        printf("Password: ");
        fgets(passwords[i].password, MAX_LENGTH, stdin);
    }

    // Verify passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, "admin") == 0) {
            if (strcmp(passwords[i].password, "password1") == 0) {
                printf("Access granted\n");
            } else {
                printf("Invalid password\n");
            }
        } else {
            printf("Invalid name or password\n");
        }
    }

    // Free memory
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].name);
        free(passwords[i].password);
    }

    return 0;
}