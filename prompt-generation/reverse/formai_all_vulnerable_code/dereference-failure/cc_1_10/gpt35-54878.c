//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey123" // replace with your own secret key

void encrypt(char *file_name);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./encrypt file1 file2 file3 ...\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        encrypt(argv[i]);
    }

    printf("Encryption completed successfully.\n");
    return 0;
}

void encrypt(char *file_name) {
    char *new_file_name = malloc(strlen(file_name) + 5); // add ".enc" to the end of the filename
    strcpy(new_file_name, file_name);
    strcat(new_file_name, ".enc");

    FILE *file_in = fopen(file_name, "rb");
    if (file_in == NULL) {
        printf("Error: Unable to open %s for reading.\n", file_name);
        return;
    }

    FILE *file_out = fopen(new_file_name, "wb");
    if (file_out == NULL) {
        printf("Error: Unable to open %s for writing.\n", new_file_name);
        fclose(file_in);
        return;
    }

    // read input file in chunks
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof buffer, file_in)) > 0) {
        // encrypt data by XORing with key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }
        fwrite(buffer, 1, bytes_read, file_out);
    }

    fclose(file_in);
    fclose(file_out);

    printf("%s successfully encrypted as %s.\n", file_name, new_file_name);
}