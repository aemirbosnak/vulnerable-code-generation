//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }

        text[i] = ch; // Assign the encrypted character back
    }
}

// Function to read the contents of a file into a string
char* readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(fileSize + 1);
    if (!content) {
        perror("Unable to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(content, 1, fileSize, file);
    content[fileSize] = '\0'; // Null-terminate the string
    fclose(file);
    return content;
}

// Function to write the encrypted contents to a file
void writeFile(const char *fileName, const char *content) {
    FILE *file = fopen(fileName, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "%s", content);
    fclose(file);
}

// Main function to drive the program
int main() {
    printf("Welcome to the Enthusiastic C File Encryptor!\n");
    printf("Let's make your file secure with our vibrant encryption.\n\n");

    char inputFileName[100];
    printf("Enter the name of the file to encrypt (e.g., input.txt): ");
    scanf("%99s", inputFileName);

    char *fileContent = readFile(inputFileName);
    if (!fileContent) {
        return 1; // Read error
    }

    int shift;
    printf("Enter the encryption shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Oops! The shift value must be between 1 and 25. Let's try again from the start.\n");
        free(fileContent);
        return 1;
    }

    printf("Encrypting the content with a shift of %d...\n", shift);
    encrypt(fileContent, shift);

    char outputFileName[100];
    snprintf(outputFileName, sizeof(outputFileName), "encrypted_%s", inputFileName);
    writeFile(outputFileName, fileContent);
    printf("The content has been encrypted and saved to: %s\n", outputFileName);

    free(fileContent);
    printf("Thank you for using the Enthusiastic C File Encryptor! Stay safe and keep coding!\n");

    return 0;
}