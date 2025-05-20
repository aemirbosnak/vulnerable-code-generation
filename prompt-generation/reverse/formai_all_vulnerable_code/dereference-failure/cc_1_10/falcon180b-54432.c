//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

typedef struct {
    char filename[100];
    int filesize;
    char *data;
} File;

void read_file(File *file) {
    FILE *fp;
    char ch;
    int count = 0;

    fp = fopen(file->filename, "rb");

    if (fp == NULL) {
        printf("Error opening file: %s\n", file->filename);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        file->data[count] = ch;
        count++;
    }

    fclose(fp);
}

void write_file(File *file) {
    FILE *fp;

    fp = fopen(file->filename, "wb");

    if (fp == NULL) {
        printf("Error opening file: %s\n", file->filename);
        exit(1);
    }

    fwrite(file->data, 1, file->filesize, fp);

    fclose(fp);
}

int main() {
    char filename[100];
    File file;

    printf("Enter the filename: ");
    scanf("%s", filename);

    strcpy(file.filename, filename);
    read_file(&file);

    printf("Enter the number of bytes to be deleted: ");
    scanf("%d", &file.filesize);

    file.data = (char *)malloc(file.filesize * sizeof(char));

    if (file.data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    memset(file.data, 0, file.filesize);

    write_file(&file);

    free(file.data);

    return 0;
}