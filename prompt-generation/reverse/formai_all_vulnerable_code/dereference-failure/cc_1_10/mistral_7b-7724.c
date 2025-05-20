//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 16
#define CHAR_NUM 32

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <length>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);
    if (length < 4 || length > LENGTH) {
        printf("Error: Password length must be between 4 and %d.\n", LENGTH);
        return 1;
    }

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Define the character set
    char char_set[CHAR_NUM] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '!', '@', '#', '$', '%', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}',
        '[', ']', '|', '\\', ';', ':', '<', '>', ',', '.', '?'
    };

    // Allocate memory for the password
    char *password = (char *)malloc(length * sizeof(char));

    // Generate the password
    for (int i = 0; i < length; i++) {
        int index = rand() % CHAR_NUM;
        password[i] = char_set[index];
    }

    // Add a pinch of randomness at the end
    password[length - 1] = char_set[rand() % CHAR_NUM];

    // Print the password
    printf("Your new, secure, funny-style, and utterly random password is:\n");
    puts(password);

    // Free the memory
    free(password);

    return 0;
}