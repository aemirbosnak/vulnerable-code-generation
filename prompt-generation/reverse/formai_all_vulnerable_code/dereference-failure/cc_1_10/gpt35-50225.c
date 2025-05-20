//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void encrypt_file(char* file_name, char* key) {
    FILE *fp_in, *fp_out;
    int ch;
    int key_length = strlen(key);
    int key_index = 0;

    fp_in = fopen(file_name, "r");
    if (fp_in == NULL) {
        printf("Error: Cannot open file '%s'\n", file_name);
        exit(1);
    }

    char file_out_name[strlen(file_name) + 5];
    strcpy(file_out_name, file_name);
    strcat(file_out_name, ".enc");
    fp_out = fopen(file_out_name, "w");

    while ((ch = fgetc(fp_in)) != EOF) {
        if (key_index == key_length)
            key_index = 0;

        fputc(ch ^ key[key_index], fp_out);
        key_index++;
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("File encryption complete. Encrypted file saved as '%s'.\n", file_out_name);
}

int main(int argc, char *argv[]) {
    char file_name[MAX_SIZE], key[MAX_SIZE];

    if (argc != 3) {
        printf("Usage: %s <file_name> <key>\n", argv[0]);
        exit(1);
    }

    strcpy(file_name, argv[1]);
    strcpy(key, argv[2]);

    encrypt_file(file_name, key);

    return 0;
}