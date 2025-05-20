//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB
#define VIRUS_SIGNATURE "This is a virus!"

typedef struct {
    char *filename;
    FILE *fp;
    unsigned char buffer[MAX_FILE_SIZE];
    size_t size;
} FileInfo;

void read_file(FileInfo *file) {
    if (fread(file->buffer, 1, MAX_FILE_SIZE, file->fp)!= file->size) {
        fprintf(stderr, "Error reading file %s\n", file->filename);
        exit(1);
    }
}

int is_infected(const unsigned char *data, size_t size) {
    const unsigned char *signature = (const unsigned char *)VIRUS_SIGNATURE;
    while (size >= strlen((const char *)signature)) {
        if (memcmp(data, signature, strlen((const char *)signature)) == 0) {
            return 1;
        }
        data += strlen((const char *)signature);
        size -= strlen((const char *)signature);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FileInfo file;
    file.filename = argv[1];
    file.fp = fopen(file.filename, "rb");
    if (!file.fp) {
        fprintf(stderr, "Error opening file %s\n", file.filename);
        return 1;
    }

    fseek(file.fp, 0, SEEK_END);
    file.size = ftell(file.fp);
    if (file.size > MAX_FILE_SIZE) {
        fprintf(stderr, "File %s is too large (%zu bytes)\n", file.filename, file.size);
        return 1;
    }

    rewind(file.fp);
    read_file(&file);

    if (is_infected(file.buffer, file.size)) {
        fprintf(stdout, "File %s is infected with a virus!\n", file.filename);
    } else {
        fprintf(stdout, "File %s is clean.\n", file.filename);
    }

    fclose(file.fp);
    return 0;
}