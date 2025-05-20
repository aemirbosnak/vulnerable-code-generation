//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the scroll content
void encryptScroll(const char *inputFile, const char *outputFile, int key) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    
    if (input == NULL || output == NULL) {
        perror("Error opening file");
        return;
    }
    
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        // Shield the character using a simple caesar cipher
        char enchantedChar = ch + key;
        fputc(enchantedChar, output);
    }
    
    fclose(input);
    fclose(output);
}

// Function to decrypt the scroll content
void decryptScroll(const char *inputFile, const char *outputFile, int key) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");
    
    if (input == NULL || output == NULL) {
        perror("Error opening file");
        return;
    }
    
    char ch;
    while ((ch = fgetc(input)) != EOF) {
        // Unshield the character by reversing the encryption
        char restoredChar = ch - key;
        fputc(restoredChar, output);
    }
    
    fclose(input);
    fclose(output);
}

// Function to create an enchanted lock with given key
void createEnchantedLock(int *key) {
    *key = rand() % 26;  // key is between 0 and 25
}

// Main function - the sorcerer's command center
int main() {
    int enchantedKey;
    createEnchantedLock(&enchantedKey);
    
    char *inputFile = "scroll.txt";
    char *encryptedFile = "encrypted_scroll.txt";
    char *decryptedFile = "decrypted_scroll.txt";
    
    printf("A wizard has spoken: Encrypting the scroll with enchanted key %d...\n", enchantedKey);
    encryptScroll(inputFile, encryptedFile, enchantedKey);
    
    printf("The scroll has been cloaked. Now, unveiling the secrets...\n");
    decryptScroll(encryptedFile, decryptedFile, enchantedKey);
    
    printf("The scroll has been restored with all its secrets revealed.\n");
    
    // Opening the decrypted scroll to show its content
    FILE *decryptedScroll = fopen(decryptedFile, "r");
    if (decryptedScroll) {
        printf("Content of the revealed scroll:\n");
        char line[256];
        while (fgets(line, sizeof(line), decryptedScroll)) {
            printf("%s", line);
        }
        fclose(decryptedScroll);
    }

    return 0;
}