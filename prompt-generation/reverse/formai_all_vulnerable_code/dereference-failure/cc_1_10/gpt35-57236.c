//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE_SIZE 1000

void encryption(char *file_name);

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter the file name that you want to encrypt!\n");
        return 0;
    }

    char *file_name = argv[1];

    printf("Initializing encryption...\n");

    encryption(file_name);

    printf("Encryption complete! Your file has been locked down with top-notch military grade encryption. Good luck trying to unscramble that one! Ha!\n");

    return 0;
}

void encryption(char *file_name) {
    FILE *file;
    char *file_content = (char *)malloc(sizeof(char) * MAX_FILE_SIZE);

    file = fopen(file_name, "r");

    if(file) {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if(file_size > MAX_FILE_SIZE) {
            printf("Error: file size exceeds maximum limit of 1000 bytes. Aborting encryption...\n");
            return;
        }

        fread(file_content, sizeof(char), file_size, file);
        fclose(file);

        int key = 7283; // chosen randomly by my cat
        for(int i = 0; i < file_size; i++) {
            file_content[i] ^= key;
        }

        file = fopen(strcat(file_name, ".enc"), "w");
        fwrite(file_content, sizeof(char), file_size, file);
        fclose(file);

        free(file_content);
    } else {
        printf("Error: file '%s' could not be opened. Aborting encryption...\n", file_name);
        return;
    }
}