//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ENCRYPT 1
#define DECRYPT 2

int main(int argc, char *argv[]) {
    FILE *file;
    char mode = 'E';
    if (argc == 3) {
        if (strcmp(argv[1], "-e") == 0) {
            mode = ENCRYPT;
        } else if (strcmp(argv[1], "-d") == 0) {
            mode = DECRYPT;
        } else {
            printf("Invalid mode specified.\n");
            exit(1);
        }
        file = fopen(argv[2], "rb+");
        if (file == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }
    } else {
        printf("Invalid number of arguments.\n");
        exit(1);
    }

    int key = 0;
    for (int i = 0; i < strlen(argv[1]); i++) {
        key += tolower(argv[1][i]);
    }

    char buffer[1024];
    int bytes_read, bytes_written;

    while ((bytes_read = fread(buffer, 1, 1024, file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (mode == ENCRYPT) {
                buffer[i] ^= key;
            } else {
                buffer[i] ^= key;
            }
        }
        fseek(file, -bytes_read, SEEK_CUR);
        bytes_written = fwrite(buffer, 1, bytes_read, file);
        if (bytes_read!= bytes_written) {
            printf("Error writing to file.\n");
            exit(1);
        }
    }

    fclose(file);
    printf("Done.\n");
    return 0;
}