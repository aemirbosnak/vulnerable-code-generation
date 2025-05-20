//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random character from the given string
char rand_char(char *str) {
    int len = strlen(str);
    return str[rand() % len];
}

// Function to generate a random password of the given length
char *rand_password(int len) {
    char *password = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        int type = rand() % 3;
        switch (type) {
            case 0:
                password[i] = rand_char("abcdefghijklmnopqrstuvwxyz");
                break;
            case 1:
                password[i] = rand_char("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
                break;
            case 2:
                password[i] = rand_char("0123456789");
                break;
        }
    }
    password[len] = '\0';
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int len;
    printf("Enter the length of the password: ");
    scanf("%d", &len);

    // Generate a random password
    char *password = rand_password(len);

    // Print the password to the console
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}