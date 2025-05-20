//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char* filename, char* key) {
    FILE* fp = fopen(filename, "rb+");
    if (!fp) {
        // Error in opening the file; return from function
        return;
    }

    int keyLength = strlen(key);
    int i = 0;
    char ch;

    // Loop through the file character by character
    while (fread(&ch, sizeof(char), 1, fp)) {
        // XOR the character with the corresponding key character
        ch = ch ^ key[i % keyLength];

        // Write the encrypted character back to the file
        fseek(fp, -1, SEEK_CUR);
        fwrite(&ch, sizeof(char), 1, fp);

        i++;
    }

    // Close the file
    fclose(fp);
}

int main(int argc, char* argv[]) {
    char* filename, *key;

    // Check if the arguments are provided correctly
    if (argc < 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    key = argv[2];

    // Encrypt the file
    encryptFile(filename, key);

    printf("File %s encrypted successfully with key %s.\n", filename, key);

    return 0;
}