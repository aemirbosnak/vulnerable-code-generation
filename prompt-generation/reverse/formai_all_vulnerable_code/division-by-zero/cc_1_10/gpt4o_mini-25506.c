//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void encryptDecrypt(char *inputFile, char *outputFile, char *key) {
    FILE *input, *output;
    char ch;
    int keyLength = strlen(key);
    
    input = fopen(inputFile, "rb");
    if (input == NULL) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }
    
    output = fopen(outputFile, "wb");
    if (output == NULL) {
        fclose(input);
        perror("Could not open output file");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    
    while ((ch = fgetc(input)) != EOF) {
        // XOR the character with the key character, cycling through the key
        fputc(ch ^ key[index % keyLength], output);
        index++;
    }

    fclose(input);
    fclose(output);
}

void menu() {
    printf("****************************************\n");
    printf("      C File Encryptor & Decryptor     \n");
    printf("****************************************\n");
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char inputFile[256], outputFile[256], key[256];

    do {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                printf("Enter input file name for encryption: ");
                scanf("%s", inputFile);
                printf("Enter output file name for encryption: ");
                scanf("%s", outputFile);
                printf("Enter encryption key: ");
                scanf("%s", key);
                encryptDecrypt(inputFile, outputFile, key);
                printf("File encrypted successfully!\n\n");
                break;
                
            case 2: 
                printf("Enter input file name for decryption: ");
                scanf("%s", inputFile);
                printf("Enter output file name for decryption: ");
                scanf("%s", outputFile);
                printf("Enter decryption key: ");
                scanf("%s", key);
                encryptDecrypt(inputFile, outputFile, key);
                printf("File decrypted successfully!\n\n");
                break;
                
            case 3: 
                printf("Exiting the program. Goodbye!\n");
                break;
                
            default: 
                printf("Invalid choice, please try again.\n\n");
        }
    } while (choice != 3);

    return 0;
}