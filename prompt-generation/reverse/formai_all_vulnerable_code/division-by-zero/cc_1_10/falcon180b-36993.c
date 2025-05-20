//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_LENGTH 1000000

typedef struct {
    int key_length;
    char key[MAX_KEY_LENGTH];
} Key;

typedef struct {
    FILE *file;
    char filename[100];
    int file_length;
} File;

void read_key(Key *key) {
    printf("Enter key: ");
    fgets(key->key, MAX_KEY_LENGTH, stdin);
    key->key_length = strlen(key->key);
}

void read_file(File *file) {
    printf("Enter filename: ");
    fgets(file->filename, 100, stdin);
    file->file = fopen(file->filename, "r");
    if (file->file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fseek(file->file, 0, SEEK_END);
    file->file_length = ftell(file->file);
    rewind(file->file);
}

void encrypt(File *file, Key *key) {
    char buffer[MAX_FILE_LENGTH];
    int buffer_length = 0;
    int key_index = 0;

    while ((buffer_length = fread(buffer, 1, MAX_FILE_LENGTH, file->file)) > 0) {
        for (int i = 0; i < buffer_length; i++) {
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                c = (c - 'a' + key->key[key_index % key->key_length]) % 26 + 'a';
                key_index++;
            }
            fprintf(stdout, "%c", c);
        }
    }
}

int main() {
    Key key;
    File file;

    read_key(&key);
    read_file(&file);

    encrypt(&file, &key);

    fclose(file.file);

    return 0;
}