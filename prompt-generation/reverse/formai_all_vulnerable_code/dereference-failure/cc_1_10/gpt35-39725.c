//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY 17

int main(int argc, char *argv[]) {

    // Check if file name is provided in command line arguments
    if (argc != 2) {
        printf("Usage: file_encryption <filename>\n");
        return 1;
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "r");

    // Check if file exists and can be opened
    if (file == NULL) {
        printf("Unable to open file!\n");
        return 1;
    }

    // Get the size of the file
    fseek(file, 0L, SEEK_END);
    long int fileSize = ftell(file);
    rewind(file);

    // Allocate memory to store the file content
    char *fileContent = (char*) malloc(fileSize * sizeof(char));

    // Read the file content into a buffer
    fread(fileContent, fileSize, 1, file);

    // Close the file
    fclose(file);

    // Encrypt the file content
    for (int i = 0; i < fileSize; i++) {
        fileContent[i] ^= KEY;
    }

    // Create a new file with .enc extension to store the encrypted content
    char newFileName[255];
    strcpy(newFileName, argv[1]);
    strcat(newFileName, ".enc");

    // Open the new file in write mode
    FILE *newFile = fopen(newFileName, "w");

    // Write the encrypted content to the new file
    fwrite(fileContent, fileSize, 1, newFile);

    // Close the new file
    fclose(newFile);

    // Free the memory allocated for file content
    free(fileContent);

    printf("File has been encrypted successfully!\n");

    return 0;
}