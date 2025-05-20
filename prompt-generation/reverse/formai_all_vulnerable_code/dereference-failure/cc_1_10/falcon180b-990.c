//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB

typedef struct {
    char *filename;
    char *extension;
    int filesize;
    char data[MAX_FILE_SIZE];
} FileInfo;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    char *extension = strrchr(filename, '.');
    if (extension == NULL) {
        printf("Error: Invalid file extension.\n");
        fclose(fp);
        return 1;
    }

    FileInfo *fileinfo = malloc(sizeof(FileInfo));
    if (fileinfo == NULL) {
        printf("Error: Out of memory.\n");
        fclose(fp);
        return 1;
    }

    strcpy(fileinfo->filename, filename);
    strcpy(fileinfo->extension, extension);
    fileinfo->filesize = filesize;

    if (filesize > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        free(fileinfo);
        fclose(fp);
        return 1;
    }

    fread(fileinfo->data, filesize, 1, fp);
    fclose(fp);

    printf("File information:\n");
    printf("Filename: %s\n", fileinfo->filename);
    printf("Extension: %s\n", fileinfo->extension);
    printf("File size: %d bytes\n", fileinfo->filesize);

    printf("File contents:\n");
    printf("%s\n", fileinfo->data);

    free(fileinfo);
    return 0;
}