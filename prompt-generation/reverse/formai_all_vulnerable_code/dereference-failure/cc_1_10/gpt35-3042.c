//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to return a random uppercase letter
char random_uppercase() {
    return 'A' + rand() % 26; // return a random uppercase letter
}

// Function to return a random lowercase letter
char random_lowercase() {
    return 'a' + rand() % 26; // return a random lowercase letter
}

// Function to return a random digit
char random_digit() {
    return '0' + rand() % 10; // return a random digit
}

// Function to generate a secure password
void generate_password(char *password, int length) {
    srand(time(NULL)); // seed the random number generator
   
    for (int i = 0; i < length; i++) {
        int type = rand() % 3; // generate a random number to decide on the character type
        
        // Choose a random character based on the type
        if (type == 0) {
            password[i] = random_uppercase();
        } else if (type == 1) {
            password[i] = random_lowercase();
        } else {
            password[i] = random_digit();
        }
    }
    
    password[length] = '\0'; // add the null terminator to the end of the string
}

int main() {
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);
    
    char *password = malloc(length + 1); // allocate memory for the password
    
    if (password == NULL) { // check if allocation failed
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    generate_password(password, length); // generate the password
    
    printf("Generated password: %s\n", password);
    
    free(password); // free the allocated memory
    
    return 0;
}