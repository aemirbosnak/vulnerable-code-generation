//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void encryptDecrypt(char *input, char *output, char key) {
    FILE *inFile, *outFile;
    char ch;

    inFile = fopen(input, "rb");
    if (inFile == NULL) {
        fprintf(stderr, "\033[31mError: Could not open input file.\033[0m\n");
        exit(1);
    }

    outFile = fopen(output, "wb");
    if (outFile == NULL) {
        fprintf(stderr, "\033[31mError: Could not open output file.\033[0m\n");
        fclose(inFile);
        exit(1);
    }

    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile);
    }

    printf("\033[32mFile encrypted successfully!\033[0m\n");
    
    fclose(inFile);
    fclose(outFile);
}

void displayInstructions() {
    printf("\033[34m----------------------------------------\033[0m\n");
    printf("\033[34m       C File Encryptor Program        \033[0m\n");
    printf("\033[34m----------------------------------------\033[0m\n");
    printf("\033[34mUsage:\n\033[0m");
    printf("\033[34m  1. Provide input file name.\n\033[0m");
    printf("\033[34m  2. Provide output file name.\n\033[0m");
    printf("\033[34m  3. Provide encryption key (single character).\n\033[0m");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayInstructions();
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char key = argv[3][0]; // Use the first character as the key

    printf("\033[33mStarting encryption...\033[0m\n");

    encryptDecrypt(inputFile, outputFile, key);

    printf("\033[34m----------------------------------------\033[0m\n");
    printf("\033[34m         Thank you for using!          \033[0m\n");
    printf("\033[34m----------------------------------------\033[0m\n");

    return 0;
}