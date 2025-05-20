//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between [min, max]
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random character from the set of printable ASCII
// characters
char random_printable_char() {
    // Define the set of printable ASCII characters
    const char charset[] = "`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?" // Printable special characters
                            "0123456789" // Numerals
                            "abcdefghijklmnopqrstuvwxyz" // Lowercase letters
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Uppercase letters
    // Find the length of the charset array
    const int charset_length = sizeof(charset) - 1; // -1 to exclude the terminating null
    
    // Generate a random index into the charset array
    const int index = random_int(0, charset_length - 1);
    
    // Return the character at the random index
    return charset[index];
}

// Function to generate a secure password with the specified length
char* generate_password(int length) {
    // Allocate memory for the password string
    char* password = malloc((length + 1) * sizeof(char));
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random password
    for (int i = 0; i < length; i++) {
        password[i] = random_printable_char();
    }
    password[length] = '\0'; // Null-terminate the password string
    
    // Return the generated password
    return password;
}

int main() {
    // Prompt the user to enter the length of the password they want to generate
    printf("How long do you want your password to be?\n");
    int password_length;
    scanf("%d", &password_length);
    
    // Generate the password and print it
    char* password = generate_password(password_length);
    printf("Your new password is: %s\n", password);
    
    // Free the memory used by the password string
    free(password);
    
    return 0;
}