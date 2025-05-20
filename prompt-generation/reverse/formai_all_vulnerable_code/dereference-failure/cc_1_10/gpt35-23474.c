//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_LENGTH 10

/*
This program takes in a filename as input and a key as a command-line argument.
It then reads the contents of the file into a buffer, performs an XOR with the key on each byte of the buffer and writes the encrypted content back to the file.
*/

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <key>\n", argv[0]);
        exit(1);
    }

    char key[KEY_LENGTH + 1];
    strncpy(key, argv[1], KEY_LENGTH);
    key[KEY_LENGTH] = '\0'; // truncate key if it's longer than KEY_LENGTH

    printf("Enter the filename: ");
    char filename[256];
    scanf("%s", filename);
    
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char *buffer = malloc(sizeof(char) * file_size);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(fp);
        exit(1);
    }

    fread(buffer, file_size, 1, fp);
    fclose(fp);

    int i;
    for (i = 0; i < file_size; i++) {
        buffer[i] = buffer[i] ^ key[i % KEY_LENGTH];
    }

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(buffer, file_size, 1, fp);
    fclose(fp);

    free(buffer);

    printf("File %s has been encrypted with key %s\n", filename, key);

    return 0;
}