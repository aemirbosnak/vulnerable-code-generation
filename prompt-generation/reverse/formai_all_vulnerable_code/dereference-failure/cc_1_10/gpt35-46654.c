//FormAI DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *filename, int key) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    // Open a new file for writing
    char new_filename[strlen(filename) + 5];
    sprintf(new_filename, "%s%s", filename, ".enc");
    FILE *new_file = fopen(new_filename, "w");
    if (!new_file) {
        printf("Error: could not create new file\n");
        return;
    }
    
    // Read the file in chunks and encrypt each chunk
    char buffer[BUFFER_SIZE];
    int read_count;
    while ((read_count = fread(buffer, sizeof(char), BUFFER_SIZE, file))) {
        for (int i = 0; i < read_count; i++) {
            buffer[i] = buffer[i] ^ key;
        }
        fwrite(buffer, sizeof(char), read_count, new_file);
    }

    // Close the files
    fclose(file);
    fclose(new_file);

    // Delete the original file
    if (remove(filename) != 0) {
        printf("Error: could not delete original file %s\n", filename);
    } else {
        printf("File %s encrypted and original deleted\n", filename);
    }
}

void decrypt(char *filename, int key) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    // Open a new file for writing
    char new_filename[strlen(filename) - 4];
    strncpy(new_filename, filename, strlen(filename) - 4);
    new_filename[strlen(filename) - 4] = '\0';
    FILE *new_file = fopen(new_filename, "w");
    if (!new_file) {
        printf("Error: could not create new file\n");
        return;
    }
    
    // Read the file in chunks and decrypt each chunk
    char buffer[BUFFER_SIZE];
    int read_count;
    while ((read_count = fread(buffer, sizeof(char), BUFFER_SIZE, file))) {
        for (int i = 0; i < read_count; i++) {
            buffer[i] = buffer[i] ^ key;
        }
        fwrite(buffer, sizeof(char), read_count, new_file);
    }

    // Close the files
    fclose(file);
    fclose(new_file);

    // Delete the encrypted file
    if (remove(filename) != 0) {
        printf("Error: could not delete encrypted file %s\n", filename);
    } else {
        printf("File %s decrypted and encrypted deleted\n", filename);
    }
}

int main() {
    // Get filename and encryption key from user
    char filename[256];
    int key;
    char choice;
    printf("Enter filename to encrypt or decrypt (with .enc extension): ");
    scanf("%s", filename);
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Determine whether to encrypt or decrypt the file
    if (strstr(filename, ".enc")) {
        printf("Do you want to decrypt %s (y/n)? ", filename);
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            decrypt(filename, key);
        } else {
            printf("Exiting program\n");
        }
    } else {
        printf("Do you want to encrypt %s (y/n)? ", filename);
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            encrypt(filename, key);
        } else {
            printf("Exiting program\n");
        }
    }

    return 0;
}