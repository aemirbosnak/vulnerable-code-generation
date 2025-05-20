//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recover_file(const char* filename, const char* destination) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Failed to open file %s.\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(size);
    if (buffer == NULL) {
        printf("Failed to allocate memory.\n");
        fclose(file);
        return;
    }

    size_t bytes_read = fread(buffer, 1, size, file);
    if (bytes_read!= size) {
        printf("Failed to read file.\n");
        free(buffer);
        fclose(file);
        return;
    }

    fclose(file);

    char* new_filename = destination? destination : filename;
    new_filename[strlen(new_filename) - 4] = '.';
    new_filename[strlen(new_filename) - 3] = '.';
    new_filename[strlen(new_filename) - 2] = '.';
    new_filename[strlen(new_filename) - 1] = '\0';
    new_filename[strlen(new_filename) - 2] = 'b';
    new_filename[strlen(new_filename) - 1] = '\0';

    FILE* new_file = fopen(new_filename, "wb");
    if (new_file == NULL) {
        printf("Failed to create new file %s.\n", new_filename);
        free(buffer);
        return;
    }

    fwrite(buffer, 1, size, new_file);
    fclose(new_file);
    free(buffer);

    printf("Data recovered to %s.\n", new_filename);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <destination>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    const char* destination = argv[2];

    recover_file(filename, destination);

    return 0;
}