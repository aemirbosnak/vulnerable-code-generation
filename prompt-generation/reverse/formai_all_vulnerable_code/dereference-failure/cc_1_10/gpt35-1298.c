//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }

    FILE *file = fopen(argv[1], "rb");
    if(!file) {
        printf("Could not open file: %s\n", argv[1]);
        return 0;
    }

    char header[2];
    fread(header, 2, 1, file);
    if(header[0] != 'C' || header[1] != 'A') {
        printf("File is not a C Antivirus file.\n");
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file) - 2;
    fseek(file, 2, SEEK_SET);

    char *data = malloc(size);
    fread(data, size, 1, file);

    int i;
    for(i = 0; i < size; i++) {
        data[i] = ~data[i];
    }

    for(i = 0; i < size; i++) {
        if(data[i] != 0x00) {
            printf("File is infected with a virus.\n");
            fclose(file);
            free(data);
            return 0;
        }
    }

    printf("File is clean.\n");
    fclose(file);
    free(data);
    return 0;
}