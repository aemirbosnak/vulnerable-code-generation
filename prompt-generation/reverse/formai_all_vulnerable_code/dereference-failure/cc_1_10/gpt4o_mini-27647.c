//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 128

// Function prototypes
void generatePassword(char *password, int length, int includeNumbers, int includeSymbols);
void printUsage();
int isValidInput(int length, int includeNumbers, int includeSymbols);

const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *numbers = "0123456789";
const char *symbols = "!@#$%^&*()-=_+[]{}|;:,.<>?";

int main(int argc, char *argv[]) {
    int length = 12;    // Default password length
    int includeNumbers = 1; // Default to include numbers
    int includeSymbols = 1; // Default to include symbols
    char password[MAX_LENGTH + 1]; // Password buffer

    // Process command line arguments
    if (argc > 1) {
        length = atoi(argv[1]);
        if (length < 8 || length > MAX_LENGTH) {
            fprintf(stderr, "Password length must be between 8 and %d.\n", MAX_LENGTH);
            return 1;
        }

        if (argc > 2) {
            includeNumbers = atoi(argv[2]);
            if (includeNumbers < 0 || includeNumbers > 1) {
                fprintf(stderr, "Include numbers flag must be 0 (false) or 1 (true).\n");
                return 1;
            }
        }

        if (argc > 3) {
            includeSymbols = atoi(argv[3]);
            if (includeSymbols < 0 || includeSymbols > 1) {
                fprintf(stderr, "Include symbols flag must be 0 (false) or 1 (true).\n");
                return 1;
            }
        }
    }

    // Generate password
    generatePassword(password, length, includeNumbers, includeSymbols);
    printf("Generated Password: %s\n", password);

    return 0;
}

void generatePassword(char *password, int length, int includeNumbers, int includeSymbols) {
    char characterPool[256];
    int poolIndex = 0;

    // Fill character pool with allowed characters
    strcpy(characterPool, lowercase);
    poolIndex += strlen(lowercase);
    strcpy(characterPool + poolIndex, uppercase);
    poolIndex += strlen(uppercase);

    // Optionally add numbers
    if (includeNumbers) {
        strcpy(characterPool + poolIndex, numbers);
        poolIndex += strlen(numbers);
    }

    // Optionally add special characters
    if (includeSymbols) {
        strcpy(characterPool + poolIndex, symbols);
        poolIndex += strlen(symbols);
    }

    // Seed random number generator
    srand(time(0));

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = characterPool[rand() % poolIndex];
    }
    password[length] = '\0'; // Null-terminate the password string
}

void printUsage() {
    printf("Usage: password_generator <length> [include_numbers] [include_symbols]\n");
    printf("  <length>            - Length of password (between 8 and %d)\n", MAX_LENGTH);
    printf("  [include_numbers]   - 0 to exclude numbers, 1 to include (default is 1)\n");
    printf("  [include_symbols]   - 0 to exclude symbols, 1 to include (default is 1)\n");
}

int isValidInput(int length, int includeNumbers, int includeSymbols) {
    return (length >= 8 && length <= MAX_LENGTH) && 
           (includeNumbers == 0 || includeNumbers == 1) && 
           (includeSymbols == 0 || includeSymbols == 1);
}