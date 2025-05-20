//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATH 1024
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char *path;
    char *backup_path;
} File;

void backup_file(File *file) {
    FILE *fp, *bfp;
    char ch;
    int count = 0;

    strcat(file->backup_path, BACKUP_EXTENSION);
    bfp = fopen(file->backup_path, "w");

    if (bfp == NULL) {
        printf("Error creating backup file %s\n", file->backup_path);
        exit(1);
    }

    fp = fopen(file->path, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", file->path);
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        fputc(ch, bfp);
        count++;
    }

    printf("Backup created: %s\n", file->backup_path);
    printf("Number of characters written: %d\n", count);

    fclose(fp);
    fclose(bfp);
}

int main(int argc, char *argv[]) {
    File file;
    int i;

    if (argc!= 3) {
        printf("Usage: %s <file_path> <backup_path>\n", argv[0]);
        exit(1);
    }

    strcpy(file.path, argv[1]);
    strcpy(file.backup_path, argv[2]);

    backup_file(&file);

    return 0;
}