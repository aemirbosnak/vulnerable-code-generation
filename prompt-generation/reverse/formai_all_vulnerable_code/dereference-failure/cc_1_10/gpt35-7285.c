//FormAI DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 100000
#define MAX_FILENAME_SIZE 256

char* recover_data(char* filename);

int main() {
    char filename[MAX_FILENAME_SIZE];
    printf("Enter file name: ");
    scanf("%s", filename);

    char* data = recover_data(filename);
    printf("Recovered data: %s\n", data);

    free(data);
    return 0;
}

char* recover_data(char* filename) {
    // open file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    // allocate memory
    char* data = malloc(sizeof(char) * (file_size + 1));
    if (data == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // read file
    int bytes_read = fread(data, sizeof(char), MAX_FILE_SIZE, fp);
    data[bytes_read] = '\0';

    // close file
    fclose(fp);

    // recover lost data
    for (int i = 0; i < bytes_read; i++) {
        if (data[i] == '\0') {
            data[i] = 'x';
        }
    }

    return data;
}