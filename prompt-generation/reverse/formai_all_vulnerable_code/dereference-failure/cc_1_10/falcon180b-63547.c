//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int size;
    char *buffer;
} File;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int filesize, chunksize, chunknum;
    File *file = malloc(sizeof(File));
    file->filename = filename;

    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        free(file);
        return 1;
    }

    fseek(f, 0, SEEK_END);
    filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    chunknum = 1;
    while (filesize > 0) {
        chunksize = filesize > BUFFER_SIZE? BUFFER_SIZE : filesize;
        file->buffer = realloc(file->buffer, chunksize + 1);
        if (file->buffer == NULL) {
            printf("Error: could not allocate memory\n");
            fclose(f);
            free(file);
            return 1;
        }

        size_t bytesread = fread(file->buffer, 1, chunksize, f);
        if (bytesread!= chunksize) {
            printf("Error: could not read file\n");
            fclose(f);
            free(file);
            return 1;
        }

        file->size += bytesread;
        filesize -= bytesread;
        printf("Recovered chunk %d of size %d\n", chunknum++, bytesread);
    }

    fclose(f);
    printf("Recovery complete!\n");

    return 0;
}