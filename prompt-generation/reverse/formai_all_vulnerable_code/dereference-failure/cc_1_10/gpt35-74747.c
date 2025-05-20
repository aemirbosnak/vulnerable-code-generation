//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encyptFile(char* fileName, int key) {
    FILE* input = fopen(fileName, "rb"); // open file in binary mode
    if (!input) {
        printf("Failed to open file '%s'!\n", fileName);
        exit(1);
    }
    char* outputFileName = malloc(strlen(fileName) + 5); // allocate space for output file name
    sprintf(outputFileName, "%s.enc", fileName); // add ".enc" to the end of the file name
    FILE* output = fopen(outputFileName, "wb"); // open output file in binary mode
    if (!output) {
        printf("Failed to create output file '%s'!\n", outputFileName);
        free(outputFileName);
        exit(1);
    }
    int c;
    while ((c = fgetc(input)) != EOF) { // read one byte at a time
        unsigned char x = (unsigned char)c; // cast to unsigned char
        x ^= key; // XOR with encryption key
        fputc(x, output); // write encrypted byte to output file
    }
    fclose(input);
    fclose(output);
    printf("File '%s' encrypted successfully!\n", fileName);
}

void decyptFile(char* fileName, int key) {
    FILE* input = fopen(fileName, "rb"); // open file in binary mode
    if (!input) {
        printf("Failed to open file '%s'!\n", fileName);
        exit(1);
    }
    char* outputFileName = malloc(strlen(fileName) + 5); // allocate space for output file name
    int len = strlen(fileName);
    if (len < 4 || strcmp(fileName + len - 4, ".enc") != 0) { // check if file name ends with ".enc"
        printf("Error: Input file must have '.enc' extension!\n");
        free(outputFileName);
        exit(1);
    }
    strncpy(outputFileName, fileName, len - 4); // remove ".enc" from file name
    outputFileName[len - 4] = '\0';
    FILE* output = fopen(outputFileName, "wb"); // open output file in binary mode
    if (!output) {
        printf("Failed to create output file '%s'!\n", outputFileName);
        free(outputFileName);
        exit(1);
    }
    int c;
    while ((c = fgetc(input)) != EOF) { // read one byte at a time
        unsigned char x = (unsigned char)c; // cast to unsigned char
        x ^= key; // XOR with encryption key
        fputc(x, output); // write decrypted byte to output file
    }
    fclose(input);
    fclose(output);
    printf("File '%s' decrypted successfully!\n", fileName);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <command> <key> <file1> [<file2> ...]\n", argv[0]);
        printf("Commands: enc - encrypt files, dec - decrypt files\n");
        exit(1);
    }
    char* command = argv[1];
    int key = strtol(argv[2], NULL, 10); // convert key from string to integer
    if (strcmp(command, "enc") == 0) { // encrypt files
        for (int i = 3; i < argc; i++) {
            encyptFile(argv[i], key);
        }
    } else if (strcmp(command, "dec") == 0) { // decrypt files
        for (int i = 3; i < argc; i++) {
            decyptFile(argv[i], key);
        }
    } else {
        printf("Invalid command '%s'!\n", command);
        exit(1);
    }
    return 0;
}