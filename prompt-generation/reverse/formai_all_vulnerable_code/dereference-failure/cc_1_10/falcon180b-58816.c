//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FILE_MODE "rb"
#define FILE_MODE_WRITE "wb"

typedef struct {
    char *filename;
    FILE *file;
    unsigned char *buffer;
    int buffersize;
    int filesize;
} FileData;

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage: %s <filename> <filesize>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int filesize = atoi(argv[2]);

    FileData *data = malloc(sizeof(FileData));

    data->filename = filename;
    data->buffer = malloc(BUFFER_SIZE);
    data->buffersize = BUFFER_SIZE;
    data->filesize = filesize;

    data->file = fopen(filename, FILE_MODE);
    if (data->file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    int bytesread = 0;
    while (bytesread < data->filesize) {
        int readbytes = fread(data->buffer, 1, BUFFER_SIZE, data->file);
        if (readbytes <= 0) {
            printf("Error reading file %s\n", filename);
            return 1;
        }
        bytesread += readbytes;
    }

    fclose(data->file);

    printf("File %s recovered successfully!\n", filename);

    free(data->buffer);
    free(data);

    return 0;
}