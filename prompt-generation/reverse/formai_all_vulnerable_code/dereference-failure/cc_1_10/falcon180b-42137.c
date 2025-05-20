//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MAX_FILE_SIZE 5000000

struct file_info {
    char *filename;
    int size;
    char *backup_filename;
};

int main() {
    char *filename = "test.txt";
    struct file_info file_info;

    file_info.filename = filename;
    file_info.size = 0;
    file_info.backup_filename = "test.bak";

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_info.size = ftell(fp);

    fclose(fp);

    if (file_info.size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        return 1;
    }

    char *buffer = malloc(file_info.size + 1);

    if (buffer == NULL) {
        printf("Memory error.\n");
        return 1;
    }

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("File not found.\n");
        free(buffer);
        return 1;
    }

    fread(buffer, file_info.size, 1, fp);

    fclose(fp);

    fp = fopen(file_info.backup_filename, "wb");

    if (fp == NULL) {
        printf("Error creating backup file.\n");
        free(buffer);
        return 1;
    }

    fwrite(buffer, file_info.size, 1, fp);

    fclose(fp);

    printf("Backup created successfully.\n");

    free(buffer);

    return 0;
}