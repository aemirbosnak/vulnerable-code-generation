//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *str, int key);

int main(int argc, char **argv) {
    char file_path[256], file_ext[10] = ".enc";
    FILE *file_in, *file_out;
    int key, size, i;

    if (argc != 3) {
        printf("Usage: file_enc <file_path> <encryption_key>\n");
        return EXIT_FAILURE;
    }

    strcpy(file_path, argv[1]);
    key = atoi(argv[2]);

    file_in = fopen(file_path, "rb");
    if (file_in == NULL) {
        printf("Error opening input file.\n");
        return EXIT_FAILURE;
    }

    // Get file size
    fseek(file_in, 0L, SEEK_END);
    size = ftell(file_in);
    fseek(file_in, 0L, SEEK_SET);

    // Allocate memory for file content
    char *content = (char*) malloc(size + 1);
    content[size] = '\0';

    // Read file content
    fread(content, 1, size, file_in);

    // Close input file
    fclose(file_in);

    // Encrypt file content
    encrypt(content, key);

    // Generate output file path
    char *out_path = (char*) malloc(strlen(file_path) + strlen(file_ext) + 1);
    strcpy(out_path, file_path);
    strcat(out_path, file_ext);

    // Open output file
    file_out = fopen(out_path, "wb");
    if (file_out == NULL) {
        printf("Error opening output file.\n");
        free(content);
        free(out_path);
        return EXIT_FAILURE;
    }

    // Write encrypted content to output file
    fwrite(content, 1, size, file_out);

    // Close output file
    fclose(file_out);

    // Free memory
    free(content);
    free(out_path);

    printf("File encrypted successfully.\n");

    return EXIT_SUCCESS;
}

void encrypt(char *str, int key) {
    char *ptr = str;

    while (*ptr != '\0') {
        *ptr ^= key;
        ptr++;
    }
}