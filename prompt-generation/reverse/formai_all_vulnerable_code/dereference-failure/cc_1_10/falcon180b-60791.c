//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    FILE *file;
} FileEncryptor;

void init_key(char *key, int key_size) {
    FILE *key_file = fopen("/dev/urandom", "r");
    if (key_file == NULL) {
        printf("Error: could not open /dev/urandom\n");
        exit(1);
    }
    if (fread(key, 1, key_size, key_file)!= key_size) {
        printf("Error: could not read from /dev/urandom\n");
        exit(1);
    }
    fclose(key_file);
}

void encrypt_file(FileEncryptor *encryptor) {
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), encryptor->file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= encryptor->key[i % MAX_KEY_SIZE];
        }
        fwrite(buffer, 1, bytes_read, encryptor->file);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char input_file[MAX_FILE_SIZE];
    char output_file[MAX_FILE_SIZE];
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: could not open output file\n");
        return 1;
    }

    char key[MAX_KEY_SIZE];
    init_key(key, MAX_KEY_SIZE);

    FileEncryptor encryptor = {
       .key = key,
       .file = output
    };

    encrypt_file(&encryptor);

    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");
    return 0;
}