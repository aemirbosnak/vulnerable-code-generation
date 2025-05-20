//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    char input[SIZE];
    char output[SIZE];
    char key[SIZE];
    int i, j, n;

    // Get input from user
    printf("Enter your message: ");
    fgets(input, SIZE, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Get key from user
    printf("Enter your key: ");
    fgets(key, SIZE, stdin);

    // Remove newline character
    key[strcspn(key, "\n")] = '\0';

    // Encrypt message
    for (i = 0, j = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j] = 'A' + (input[i] - 'A' + key[j % strlen(key)] - 'A') % 26;
            } else {
                output[j] = 'a' + (input[i] - 'a' + key[j % strlen(key)] - 'a') % 26;
            }
            j++;
        } else {
            output[j] = input[i];
            j++;
        }
    }
    output[j] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", output);

    // Decrypt message
    for (i = 0, j = 0; output[i]; i++) {
        if (isalpha(output[i])) {
            if (isupper(output[i])) {
                n = (output[i] - 'A' - key[j % strlen(key)] + 26) % 26;
                input[j] = 'A' + n;
            } else {
                n = (output[i] - 'a' - key[j % strlen(key)] + 26) % 26;
                input[j] = 'a' + n;
            }
            j++;
        } else {
            input[j] = output[i];
            j++;
        }
    }
    input[j] = '\0';

    // Print decrypted message
    printf("Decrypted message: %s\n", input);

    return 0;
}