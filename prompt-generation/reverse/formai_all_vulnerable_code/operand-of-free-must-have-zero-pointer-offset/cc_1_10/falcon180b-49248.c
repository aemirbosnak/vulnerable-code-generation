//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VIRUS_SIGNATURE "VIRUS"
#define FILE_CHUNK_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    char buffer[FILE_CHUNK_SIZE];
    int file_size;
} ScanFile;

int is_virus(ScanFile *file) {
    char *signature = strstr(file->buffer, VIRUS_SIGNATURE);
    if (signature!= NULL) {
        printf("Virus found in file %s\n", file->filename);
        return 1;
    }
    return 0;
}

void scan_file(ScanFile *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file->file))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
        strcat(file->buffer, line);
    }
    is_virus(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    ScanFile file;
    file.filename = argv[1];
    file.file = fopen(file.filename, "r");

    if (file.file == NULL) {
        printf("Error opening file %s\n", file.filename);
        return 1;
    }

    fseek(file.file, 0, SEEK_END);
    file.file_size = ftell(file.file);
    rewind(file.file);

    scan_file(&file);

    fclose(file.file);
    free(file.buffer);

    return 0;
}