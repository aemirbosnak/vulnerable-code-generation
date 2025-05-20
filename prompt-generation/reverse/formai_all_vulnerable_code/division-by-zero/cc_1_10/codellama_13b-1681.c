//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: minimalist
// C File Encyptor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int encrypt(char *file_name, char *key) {
    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    if (!buffer) {
        printf("Error: Could not allocate memory for file buffer\n");
        fclose(fp);
        return 1;
    }

    int i, j;
    for (i = 0; i < MAX_FILE_SIZE; i++) {
        buffer[i] = fgetc(fp);
        if (buffer[i] == EOF) break;
    }

    for (j = 0; j < i; j++) {
        buffer[j] = (char) (buffer[j] + key[j % strlen(key)]);
    }

    fclose(fp);

    fp = fopen(file_name, "w");
    if (!fp) {
        printf("Error: Could not open file %s for writing\n", file_name);
        free(buffer);
        return 1;
    }

    for (j = 0; j < i; j++) {
        fputc(buffer[j], fp);
    }

    fclose(fp);
    free(buffer);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s file_name key\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *key = argv[2];

    if (encrypt(file_name, key)) {
        printf("Error: Could not encrypt file %s\n", file_name);
        return 1;
    }

    printf("File %s encrypted successfully\n", file_name);
    return 0;
}