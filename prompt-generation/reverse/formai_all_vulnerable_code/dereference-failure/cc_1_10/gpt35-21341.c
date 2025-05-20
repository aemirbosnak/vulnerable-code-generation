//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encrypt(char *text, int shift);

int main()
{
    printf("Welcome to the C File Encryptor program!\n");

    char fileName[100];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", fileName);

    int shift;
    printf("Enter the shift value for encryption: ");
    scanf("%d", &shift);

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file. Please check if file name is correct.\n");
        return -1;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read file into buffer
    char *buffer = malloc(fileSize + 1);
    fread(buffer, 1, fileSize, file);

    fclose(file);

    // Encrypt file content
    char *encryptedText = encrypt(buffer, shift);

    // Write encrypted content back to file
    file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error writing to file. Please try again.\n");
        return -1;
    }
    fwrite(encryptedText, 1, strlen(encryptedText), file);
    fclose(file);

    printf("\nFile encrypted successfully with shift value of %d\n", shift);

    return 0;
}

// Encrypt function using Caesar Cipher
char* encrypt(char *text, int shift)
{
    int n = strlen(text);

    char *result = (char *)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (text[i] == ' ') {
            result[i] = ' ';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            result[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else {
            result[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }

    result[n] = '\0';

    return result;
}