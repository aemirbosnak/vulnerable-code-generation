//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char* filename;
    char* encrypted_filename;
    int key;
} FileInfo;

void encrypt_file(FILE* input_file, FILE* output_file, int key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        ch ^= key;
        fputc(ch, output_file);
    }
}

void decrypt_file(FILE* input_file, FILE* output_file, int key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        ch ^= key;
        fputc(ch, output_file);
    }
}

int main() {
    int num_files;
    FileInfo* files = NULL;

    // Get list of files to encrypt/decrypt
    printf("Enter number of files: ");
    scanf("%d", &num_files);
    files = (FileInfo*) malloc(num_files * sizeof(FileInfo));
    for (int i = 0; i < num_files; i++) {
        printf("Enter filename: ");
        scanf("%s", files[i].filename);
        printf("Enter encrypted/decrypted filename: ");
        scanf("%s", files[i].encrypted_filename);
        printf("Enter key: ");
        scanf("%d", &files[i].key);
    }

    // Encrypt/decrypt files
    for (int i = 0; i < num_files; i++) {
        FILE* input_file = fopen(files[i].filename, "rb");
        if (input_file == NULL) {
            printf("Error: %s does not exist or cannot be opened.\n", files[i].filename);
            exit(1);
        }
        FILE* output_file = fopen(files[i].encrypted_filename, "wb");
        if (output_file == NULL) {
            printf("Error: %s does not exist or cannot be created.\n", files[i].encrypted_filename);
            exit(1);
        }
        if (files[i].key == 0) { // Encrypt
            encrypt_file(input_file, output_file, files[i].key);
        } else { // Decrypt
            decrypt_file(input_file, output_file, files[i].key);
        }
        fclose(input_file);
        fclose(output_file);
    }

    free(files);
    return 0;
}