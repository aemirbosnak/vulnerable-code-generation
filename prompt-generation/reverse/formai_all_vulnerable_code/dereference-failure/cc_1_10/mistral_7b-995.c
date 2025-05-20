//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// Carrot structure
typedef struct {
    int rotations;
} Carrot;

// Function to generate random carrot rotations
Carrot generate_carrot() {
    Carrot carrot = {0};
    carrot.rotations = rand() % 26;
    return carrot;
}

// Function to encrypt a message using the carrot key
void encrypt_message(const char* message, Carrot carrot) {
    int i, length = strlen(message);
    for (i = 0; i < length; i++) {
        putchar((message[i] + carrot.rotations - 'a') % 26 + 'a');
    }
    putchar('\n');
}

// Function to read a message from the user
void get_message(char* message) {
    int i = 0, c;
    printf("Enter a message: ");
    while ((c = getchar()) != '\n') {
        message[i++] = c;
        message[i] = '\0';
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize carrot
    Carrot carrot = generate_carrot();

    // Read message from user
    char message[100];
    get_message(message);

    // Encrypt message using carrot key
    printf("Encrypting message...\n");
    encrypt_message(message, carrot);

    // Print encrypted message
    printf("Encrypted message: ");
    encrypt_message(message, carrot);

    // Free memory
    free(message);

    return 0;
}