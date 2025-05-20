//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

// Function to generate a random upper or lowercase letter
char generate_letter() {
    if ((rand() % 2) == 0) {
        return (char)(rand() % 26 + 'a');
    } else {
        return (char)(rand() % 26 + 'A');
    }
}

// Function to generate a random digit
char generate_digit() {
    return (char)(rand() % 10 + '0');
}

// Function to generate a random special character
char generate_special() {
    char special_chars[] = "!@#$%^&*()-=_+[]{}|;:,.<>?";
    return special_chars[rand() % strlen(special_chars)];
}

// Function to generate a password of specified length
char *generate_password(int length) {
    char *password = malloc((length + 1) * sizeof(char));
    int i;
    
    for (i = 0; i < length; i++) {
        int category = rand() % 4;
        switch (category) {
            case 0: password[i] = generate_letter(); break;
            case 1: password[i] = generate_digit(); break;
            case 2: password[i] = generate_special(); break;
            default: password[i] = generate_letter(); break;
        }
    }
    
    password[length] = '\0';
    return password;
}

int main() {
    srand(time(NULL));
    
    int password_length;
    printf("Enter password length (max %d): \n", MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);
    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Maximum length is %d.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }
    
    char *password = generate_password(password_length);
    printf("Generated password: %s\n", password);
    
    free(password);
    return 0;
}