//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define DIGIT_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]\\{}|;':\",./<>?"

// Function to generate a random integer within a range
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random character from a given string
char random_char(const char* str) {
    int index = random_int(0, strlen(str) - 1);
    return *(str + index);
}

// Function to generate a secure password with given options
char* generate_password(int length, int num_uppercase, int num_lowercase, int num_digit, int num_special_chars) {
    // Allocate memory for the password string
    char* password = malloc((length + 1) * sizeof(char));

    // Generate random uppercase characters
    for (int i = 0; i < num_uppercase; i++) {
        password[i] = random_char(UPPERCASE_CHARS);
    }

    // Generate random lowercase characters
    for (int i = num_uppercase; i < num_uppercase + num_lowercase; i++) {
        password[i] = random_char(LOWERCASE_CHARS);
    }

    // Generate random digits
    for (int i = num_uppercase + num_lowercase; i < num_uppercase + num_lowercase + num_digit; i++) {
        password[i] = random_char(DIGIT_CHARS);
    }

    // Generate random special characters
    for (int i = num_uppercase + num_lowercase + num_digit; i < num_uppercase + num_lowercase + num_digit + num_special_chars; i++) {
        password[i] = random_char(SPECIAL_CHARS);
    }

    // Shuffle the password characters randomly
    for (int i = 0; i < length; i++) {
        int j = random_int(i, length - 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string and return it
    password[length] = '\0';
    return password;
}

int main() {
    // Initialize random number generator with current time as seed
    srand((unsigned int) time(NULL));

    // Generate 10 random passwords with different options
    for (int i = 0; i < 10; i++) {
        int length = random_int(8, 16);
        int num_uppercase = random_int(1, length / 4);
        int num_lowercase = random_int(1, length / 4);
        int num_digit = random_int(1, length / 4);
        int num_special_chars = length - num_uppercase - num_lowercase - num_digit;
        char* password = generate_password(length, num_uppercase, num_lowercase, num_digit, num_special_chars);

        printf("Password #%d: %s\n", i+1, password);

        // Free memory allocated for password string
        free(password);
    }

    return 0;
}