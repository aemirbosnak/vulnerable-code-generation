//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_LEN 1000

char* encrypt(char* file_path, char* key) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char* file_content = malloc((MAX_FILE_LEN + 1) * sizeof(char));
    int file_size = 0;

    while ((file_content[file_size] = fgetc(file))!= EOF) {
        file_size++;
    }

    fclose(file);

    char* result = malloc((MAX_FILE_LEN + 1) * sizeof(char));
    int result_size = 0;

    for (int i = 0; i < file_size; i++) {
        char c = file_content[i];

        if (isalpha(c)) {
            int key_index = toupper(key[i % MAX_KEY_LEN]) - 65;
            c += key_index;

            if (c > 'Z') {
                c = 'A' + (c - 'Z' - 1);
            } else if (c < 'A') {
                c = 'Z' + (c - 'A' + 1);
            }
        }

        result[result_size++] = c;
    }

    result[result_size] = '\0';

    return result;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_path> <key>\n", argv[0]);
        exit(1);
    }

    char* file_path = argv[1];
    char* key = argv[2];

    char* encrypted_content = encrypt(file_path, key);

    printf("Encrypted content:\n%s\n", encrypted_content);

    free(encrypted_content);
    return 0;
}