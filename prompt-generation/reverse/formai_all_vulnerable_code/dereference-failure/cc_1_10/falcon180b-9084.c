//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 32
#define MAX_PASSWORD_COUNT 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length = 0;
    int password_count = 0;
    int i;
    char *password_list[MAX_PASSWORD_COUNT];

    srand(time(NULL));

    // Initialize password list with empty strings
    for (i = 0; i < MAX_PASSWORD_COUNT; i++) {
        password_list[i] = (char *)malloc(MAX_PASSWORD_LENGTH * sizeof(char));
        memset(password_list[i], '\0', MAX_PASSWORD_LENGTH);
    }

    // Generate random passwords
    while (password_count < MAX_PASSWORD_COUNT) {
        password_length = rand() % MAX_PASSWORD_LENGTH + 1;
        for (i = 0; i < password_length; i++) {
            password[i] = rand() % 94 + 33; // Include uppercase letters, lowercase letters, and digits
        }
        password[i] = '\0'; // Add null terminator

        // Check if password already exists in the list
        int j;
        for (j = 0; j < password_count; j++) {
            if (strcmp(password, password_list[j]) == 0) {
                break;
            }
        }
        if (j == password_count) {
            strcpy(password_list[password_count], password);
            password_count++;
        }
    }

    // Print generated passwords
    printf("Generated passwords:\n");
    for (i = 0; i < password_count; i++) {
        printf("%s\n", password_list[i]);
    }

    for (i = 0; i < password_count; i++) {
        free(password_list[i]);
    }

    return 0;
}