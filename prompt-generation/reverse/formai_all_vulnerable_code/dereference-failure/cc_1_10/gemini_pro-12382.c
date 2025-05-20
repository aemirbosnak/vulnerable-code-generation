//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Custom character set for generating passwords
char custom_chars[] = {
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '=', '[', ']', '{', '}', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/'
};

// Function to generate a random number within a specified range
int generate_random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random character from the custom character set
char generate_random_character() {
    return custom_chars[generate_random_number(0, sizeof(custom_chars) - 1)];
}

// Function to generate a random string of a specified length
char *generate_random_string(int length) {
    // Allocate memory for the string
    char *random_string = malloc(length + 1);
    
    // Generate the random characters
    for (int i = 0; i < length; i++) {
        random_string[i] = generate_random_character();
    }
    
    // Terminate the string with a null character
    random_string[length] = '\0';
    
    // Return the random string
    return random_string;
}

// Function to generate a secure password
char *generate_secure_password(int length) {
    // Generate a random string
    char *random_string = generate_random_string(length);
    
    // Add special characters to the string
    for (int i = 0; i < length / 4; i++) {
        int random_index = generate_random_number(0, length - 1);
        random_string[random_index] = generate_random_character();
    }
    
    // Add digits to the string
    for (int i = 0; i < length / 4; i++) {
        int random_index = generate_random_number(0, length - 1);
        random_string[random_index] = generate_random_number(0, 9) + '0';
    }
    
    // Add uppercase letters to the string
    for (int i = 0; i < length / 4; i++) {
        int random_index = generate_random_number(0, length - 1);
        random_string[random_index] = generate_random_number('A', 'Z');
    }
    
    // Add lowercase letters to the string
    for (int i = 0; i < length / 4; i++) {
        int random_index = generate_random_number(0, length - 1);
        random_string[random_index] = generate_random_number('a', 'z');
    }
    
    // Shuffle the characters in the string
    for (int i = 0; i < length; i++) {
        int random_index = generate_random_number(0, length - 1);
        char temp = random_string[i];
        random_string[i] = random_string[random_index];
        random_string[random_index] = temp;
    }
    
    // Return the secure password
    return random_string;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Generate a secure password of length 20
    char *password = generate_secure_password(20);
    
    // Print the generated password
    printf("Generated password: %s\n", password);
    
    // Free the allocated memory
    free(password);
    
    return 0;
}