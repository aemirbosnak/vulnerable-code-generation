//FormAI DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the input text
char* fileEncryptor(char* inputText, int key)
{
    int length = strlen(inputText);
    char* result = (char*)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        // Check whether it is an alphabet
        if (isalpha(inputText[i])) {
            // Apply the shift according to the key
            if (isupper(inputText[i])) {
                result[i] = (char)((((inputText[i] - 65) + key) % 26) + 65);
            }
            else {
                result[i] = (char)((((inputText[i] - 97) + key) % 26) + 97);
            }
        }
        else {
            result[i] = inputText[i];
        }
    }
    result[length] = '\0';
    return result;
}

int main()
{
    FILE* fp, * fp1;
    char* buffer;
    fp = fopen("input.txt", "r");
    fp1 = fopen("output.txt", "w");

    // Check whether the file exists or not
    if (fp == NULL) {
        printf("File does not exist.");
        return 0;
    }

    int key;
    printf("Enter the key for encryption: ");
    scanf("%d", &key);

    fseek(fp, 0, SEEK_END);
    long fileLength = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char*)malloc(fileLength * sizeof(char));

    // Reading the file content to buffer
    fread(buffer, sizeof(char), fileLength, fp);

    char* encryptedText = fileEncryptor(buffer, key);

    // Writing the encrypted content to file
    fwrite(encryptedText, sizeof(char), strlen(encryptedText), fp1);

    printf("Encryption done successfully.");

    // Close the file pointers
    fclose(fp);
    fclose(fp1);
    // Free the dynamically allocated memory
    free(buffer);
    free(encryptedText);
    return 0;
}