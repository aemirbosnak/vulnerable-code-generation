//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/time.h>

// Function to encrypt a file using RC4 algorithm
void encryptFile(const char* filename) {
    FILE *inputFile, *outputFile;
    unsigned char iv[16];
    unsigned char key[16];
    unsigned char output[4096];
    unsigned char cipher[4096];
    unsigned char plaintext[4096];
    int i, j, k, length;
    ssize_t bytesRead;

    inputFile = fopen(filename, "rb");
    if (!inputFile) {
        printf("Error opening input file!\n");
        return;
    }

    // Generate random IV and key
    for (i = 0; i < 16; i++) {
        iv[i] = rand() % 256;
        key[i] = rand() % 256;
    }

    // Encrypt the input file using RC4 algorithm
    bytesRead = fread(plaintext, 1, sizeof(plaintext), inputFile);
    while (bytesRead > 0) {
        for (i = 0; i < 16; i++) {
            k = key[i];
            j = iv[i];
            for (j = 0; j < 256; j++) {
                k ^= (key[i + 1] << 8) + key[i + 2];
                iv[i] = key[i + 3];
                key[i + 3] = k ^ (j << 8);
                k = iv[i];
            }
            for (j = 0; j < bytesRead; j++) {
                k ^= iv[i] ^ plaintext[j];
                cipher[j] = (plaintext[j] + (k & 0xff)) ^ 0xff;
            }
        }
        bytesRead = fread(plaintext, 1, sizeof(plaintext), inputFile);
    }

    // Write the encrypted data to a new file
    outputFile = fopen(filename, "wb");
    if (!outputFile) {
        printf("Error opening output file!\n");
        return;
    }
    fwrite(cipher, 1, sizeof(cipher), outputFile);
    fclose(outputFile);

    // Print success message
    printf("File '%s' encrypted successfully!\n", filename);
}

// Main function
int main() {
    const char* filename = "input.txt";
    encryptFile(filename);
    return 0;
}