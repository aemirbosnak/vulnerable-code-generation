//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_FILE_SIZE 1048576 // 1MB

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    int size;
    char* data;
} file_t;

int read_file(char* filename, file_t* file) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file!\n");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    if (file_size > MAX_FILE_SIZE) {
        printf("File size too large!\n");
        return -2;
    }
    file->size = file_size;
    strcpy(file->filename, filename);
    file->data = (char*) malloc(file_size);
    if (!file->data) {
        printf("Error allocating memory!\n");
        return -3;
    }
    fread(file->data, sizeof(char), file_size, fp);
    fclose(fp);
    return 0;
}

int write_file(file_t* file) {
    FILE* fp = fopen(file->filename, "wb");
    if (!fp) {
        printf("Error creating file!\n");
        return -1;
    }
    fwrite(file->data, sizeof(char), file->size, fp);
    fclose(fp);
    return 0;
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    printf("Enter filename: ");
    scanf("%s", filename);
    file_t file;
    if (read_file(filename, &file) == 0) {
        printf("File read successfully!\n");
        printf("File data: %s\n", file.data);
        // Perform data recovery operations here
        if (write_file(&file) == 0) {
            printf("File written successfully!\n");
        }
    }
    free(file.data);
    return 0;
}