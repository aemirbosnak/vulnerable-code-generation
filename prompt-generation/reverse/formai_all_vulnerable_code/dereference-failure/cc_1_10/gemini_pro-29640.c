//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome message
void welcome() {
    printf("******************************************************************************\n");
    printf("* Welcome to the CryptoCrypt-X, the next-gen file encryption system.        *\n");
    printf("* Prepare to witness your files transform into an unbreakable enigma.        *\n");
    printf("******************************************************************************\n");
}

// Help message
void help() {
    printf("------------------------------------------------------------------------------\n");
    printf("- Usage: cryptocrypt-x [-e | -d] [-f <filename>] [-p <password>]            -\n");
    printf("- Options:                                                                  -\n");
    printf("-   -e : Encrypt a file                                                     -\n");
    printf("-   -d : Decrypt a file                                                     -\n");
    printf("-   -f : Specify the file to encrypt/decrypt                               -\n");
    printf("-   -p : Specify the password for encryption/decryption                     -\n");
    printf("------------------------------------------------------------------------------\n");
}

// Error message
void error(char *msg) {
    printf("** ERROR: %s **\n", msg);
    exit(1);
}

// Cipher function
void cipher(char *buffer, int len, char *password) {
    int keylen = strlen(password);
    for (int i = 0; i < len; i++) {
        buffer[i] ^= password[i % keylen];
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc < 5) {
        error("Not enough arguments provided.");
    }

    // Parse arguments
    char *mode = argv[1];
    char *filename = argv[3];
    char *password = argv[5];

    // Open file
    FILE *fp = fopen(filename, mode[1] == 'e' ? "rb" : "wb");
    if (!fp) {
        error("Could not open file.");
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate buffer
    char *buffer = malloc(filesize);
    if (!buffer) {
        error("Could not allocate buffer.");
    }

    // Read file into buffer
    fread(buffer, filesize, 1, fp);

    // Cipher file
    cipher(buffer, filesize, password);

    // Write buffer to file
    fwrite(buffer, filesize, 1, fp);

    // Close file
    fclose(fp);

    // Success message
    char *msg = mode[1] == 'e' ? "File encrypted successfully." : "File decrypted successfully.";
    printf("** %s **\n", msg);

    return 0;
}