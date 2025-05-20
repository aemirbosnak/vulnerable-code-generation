//FormAI DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void encrypt(char *file_path, char *key);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./encrypt <file_path> <key>\n");
        return 1;
    }

    encrypt(argv[1], argv[2]);

    printf("File encrypted successfully!\n");

    return 0;
}

void encrypt(char *file_path, char *key) {
    FILE *fp = fopen(file_path, "r"); // Open file in read mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char buffer[MAX_LEN]; // Define buffer to read file contents into
    size_t len;

    fseek(fp, 0L, SEEK_END); // Set file pointer to end of file
    len = ftell(fp); // Get length of file
    fseek(fp, 0L, SEEK_SET); // Reset file pointer to beginning of file

    fread(buffer, sizeof(char), len, fp); // Read file contents into buffer
    fclose(fp); // Close file

    for (int i = 0; i < len; i++) {
        buffer[i] = buffer[i] ^ key[i % strlen(key)]; // XOR each character in buffer with corresponding key character
    }

    fp = fopen(file_path, "w"); // Open file in write mode to overwrite contents with encrypted data
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fwrite(buffer, sizeof(char), len, fp); // Write encrypted data to file
    fclose(fp); // Close file
}