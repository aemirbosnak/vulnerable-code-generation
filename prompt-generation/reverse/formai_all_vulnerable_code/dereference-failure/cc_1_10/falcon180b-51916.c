//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000000 //10MB

typedef struct {
    char *filename;
    int filesize;
    char *data;
} file_info;

void read_file(file_info *file) {
    FILE *fp = fopen(file->filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file->filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->filesize = ftell(fp);
    rewind(fp);

    file->data = malloc(file->filesize);
    if (file->data == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    fread(file->data, sizeof(char), file->filesize, fp);
    fclose(fp);
}

void write_file(file_info *file) {
    FILE *fp = fopen(file->filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file->filename);
        exit(1);
    }

    fwrite(file->data, sizeof(char), file->filesize, fp);
    fclose(fp);
}

void recover_data(file_info *file) {
    int i, j;
    char *temp_data = malloc(file->filesize);

    for (i = 0; i < file->filesize; i++) {
        temp_data[i] = file->data[file->filesize - i - 1];
    }

    for (i = 0; i < file->filesize; i++) {
        file->data[i] = temp_data[i];
    }

    free(temp_data);
}

int main() {
    file_info file;

    printf("Enter filename: ");
    scanf("%s", file.filename);

    read_file(&file);
    recover_data(&file);
    write_file(&file);

    printf("Data recovery successful!\n");

    return 0;
}