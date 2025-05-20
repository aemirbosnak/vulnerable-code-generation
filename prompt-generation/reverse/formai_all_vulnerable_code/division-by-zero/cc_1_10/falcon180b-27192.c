//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} encryption_data;

void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
}

void encrypt_file(encryption_data* data) {
    FILE* input_file;
    FILE* output_file;
    char ch;
    int i;

    input_file = fopen(data->file_name, "r");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    output_file = fopen("encrypted_file.txt", "w");
    if (output_file == NULL) {
        printf("Error: Failed to create output file.\n");
        fclose(input_file);
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            i = ch - 'a';
            ch = (ch + data->key[i % strlen(data->key)] - 'a' + 26) % 26 + 'a';
        }
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    encryption_data data;
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter encryption key: ");
    scanf("%s", key);

    strcpy(data.key, key);
    strcpy(data.file_name, file_name);

    generate_key(data.key);
    encrypt_file(&data);

    printf("File encrypted successfully.\n");

    return 0;
}