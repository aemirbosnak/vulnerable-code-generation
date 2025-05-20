//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 255

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
} Key;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <key> <file_name>\n", argv[0]);
        return 1;
    }

    Key key;
    strcpy(key.key, argv[1]);
    key.key_length = strlen(key.key);

    FILE *file = fopen(argv[2], "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[2]);
        return 1;
    }

    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, argv[2]);

    char *ext = strrchr(file_name, '.');
    if (ext == NULL) {
        strcat(file_name, ".enc");
    } else {
        strcpy(ext, ".enc");
    }

    FILE *out_file = fopen(file_name, "wb");
    if (out_file == NULL) {
        printf("Error creating output file: %s\n", file_name);
        fclose(file);
        return 1;
    }

    char buffer[1024];
    int buffer_length = 0;

    while (fread(buffer + buffer_length, 1, sizeof(buffer) - buffer_length, file) > 0) {
        buffer_length += fread(buffer + buffer_length, 1, sizeof(buffer) - buffer_length, file);
    }

    fclose(file);

    for (int i = 0; i < buffer_length; i++) {
        buffer[i] ^= key.key[i % key.key_length];
    }

    fwrite(buffer, 1, buffer_length, out_file);

    fclose(out_file);

    printf("File encrypted successfully: %s\n", file_name);

    return 0;
}