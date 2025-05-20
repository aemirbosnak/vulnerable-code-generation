//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the character set for the password
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Get a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random password of length len
char *generate_password(int len) {
    char *password = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        password[i] = CHARSET[rand_range(0, strlen(CHARSET) - 1)];
    }
    password[len] = '\0';
    return password;
}

// Print the password and its length
void print_password(char *password) {
    printf("Your password is: %s\n", password);
    printf("Length: %ld\n", strlen(password));
}

// Free the memory allocated for the password
void free_password(char *password) {
    free(password);
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Get the length of the password from the user
    int len;
    printf("Enter the length of the password you want: ");
    scanf("%d", &len);

    // Generate the password
    char *password = generate_password(len);

    // Print the password
    print_password(password);

    // Free the memory allocated for the password
    free_password(password);

    return 0;
}