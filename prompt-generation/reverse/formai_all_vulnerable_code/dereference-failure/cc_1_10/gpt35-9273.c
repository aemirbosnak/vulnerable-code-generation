//FormAI DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <string.h>

/* Function to encrypt the file */
void encryptFile(char* filename, char* key) {
    FILE* fp = fopen(filename, "rb");
    FILE* fp_enc = fopen("encrypted_file.txt", "wb");

    if (!fp || !fp_enc) {
        printf("Error: Cannot open file\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char buffer[size];
    fread(buffer, 1, size, fp);

    /* XOR encryption */
    for (int i = 0; i < size; i++) {
        buffer[i] = buffer[i] ^ key[i % strlen(key)];
    }

    fwrite(buffer, 1, size, fp_enc);

    printf("File has been encrypted successfully!\n");

    fclose(fp);
    fclose(fp_enc);
}

/* Function to decrypt the file */
void decryptFile(char* filename, char* key) {
    FILE* fp = fopen(filename, "rb");
    FILE* fp_dec = fopen("decrypted_file.txt", "wb");

    if (!fp || !fp_dec) {
        printf("Error: Cannot open file\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char buffer[size];
    fread(buffer, 1, size, fp);

    /* XOR decryption */
    for (int i = 0; i < size; i++) {
        buffer[i] = buffer[i] ^ key[i % strlen(key)];
    }

    fwrite(buffer, 1, size, fp_dec);

    printf("File has been decrypted successfully!\n");

    fclose(fp);
    fclose(fp_dec);
}

int main() {
    char filename[100], key[50], choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Do you want to encrypt or decrypt? (e/d): ");
    scanf(" %c", &choice);

    if (choice == 'e') {
        encryptFile(filename, key);
    }
    else if (choice == 'd') {
        decryptFile(filename, key);
    }
    else {
        printf("Invalid choice\n");
    }

    return 0;
}