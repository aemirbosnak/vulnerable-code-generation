//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    size_t size;
    char *data;
} File;

void read_file(File *file) {
    FILE *fptr = fopen(file->filename, "r");
    fseek(fptr, 0, SEEK_END);
    file->size = ftell(fptr);
    rewind(fptr);

    file->data = malloc(file->size + 1);
    fread(file->data, sizeof(char), file->size, fptr);
    fclose(fptr);
}

void write_file(File *file) {
    FILE *fptr = fopen(file->filename, "w");
    fwrite(file->data, sizeof(char), file->size, fptr);
    fclose(fptr);
}

void backup_file(File *source, File *backup) {
    if (source->size!= backup->size) {
        printf("Error: Backup file size does not match source file size.\n");
        return;
    }

    read_file(source);
    read_file(backup);
    write_file(backup);
}

int main() {
    File source, backup;
    char filename[] = "example.txt";

    read_file(&source);
    read_file(&backup);
    backup_file(&source, &backup);

    write_file(&source);

    return 0;
}