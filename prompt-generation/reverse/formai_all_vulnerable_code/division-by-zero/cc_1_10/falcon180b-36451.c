//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16

int main() {
    char key[MAX_KEY_LENGTH];
    char filename[100];
    FILE* file;
    char buffer[100];
    int i, j, k, n;

    // Get key from user
    printf("Enter encryption key (up to %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);

    // Get filename from user
    printf("Enter filename to encrypt: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read file contents into buffer
    fseek(file, 0, SEEK_END);
    n = ftell(file);
    rewind(file);
    fread(buffer, n, 1, file);
    fclose(file);

    // Encrypt buffer using key
    for (i = 0; i < n; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write encrypted buffer to new file
    strcat(filename, ".enc");
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not create file '%s'\n", filename);
        exit(1);
    }
    fwrite(buffer, n, 1, file);
    fclose(file);

    // Print success message
    printf("File '%s' encrypted successfully.\n", filename);

    return 0;
}