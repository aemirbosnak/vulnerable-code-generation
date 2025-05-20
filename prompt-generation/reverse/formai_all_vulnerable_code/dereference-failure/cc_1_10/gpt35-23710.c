//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char rand_upper() {
    return (rand() % 26) + 'A';
}

// Function to generate a random lowercase letter
char rand_lower() {
    return (rand() % 26) + 'a';
}

// Function to generate a random digit
char rand_digit() {
    return (rand() % 10) + '0';
}

// Function to generate a random special character
char rand_special() {
    char specials[] = { '!', '@', '#', '$', '%', '&', '*' };
    return specials[rand() % 7];
}

// Function to generate a random password
void generate_password(char *password, int length) {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate at least one of each character type
    password[0] = rand_upper();
    password[1] = rand_lower();
    password[2] = rand_digit();
    password[3] = rand_special();
    
    // Fill the rest of the password with random characters
    for (int i = 4; i < length; i++) {
        int type = rand() % 4;
        switch (type) {
            case 0:
                password[i] = rand_upper();
                break;
            case 1:
                password[i] = rand_lower();
                break;
            case 2:
                password[i] = rand_digit();
                break;
            case 3:
                password[i] = rand_special();
                break;
        }
    }
    
    // Shuffle the password using the Fisher–Yates shuffle algorithm
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    // Set password length to 12 characters
    int length = 12;
    
    // Allocate memory for password string
    char *password = (char *) malloc(length + 1);
    
    // Generate random password
    generate_password(password, length);
    
    // Print password to console
    printf("Generated Password: %s\n", password);
    
    // Free memory
    free(password);
    
    return 0;
}