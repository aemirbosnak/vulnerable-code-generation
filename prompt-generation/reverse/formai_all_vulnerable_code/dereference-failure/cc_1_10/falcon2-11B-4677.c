//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

typedef struct {
    char *name;
    int size;
    int type;
} metadata_t;

void extract_metadata(char *file_name, metadata_t *metadata) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char buffer[1024];
    int buffer_size = sizeof(buffer);
    int i = 0;
    while (i < file_size) {
        if (fread(buffer, 1, buffer_size, fp)!= buffer_size) {
            perror("Error reading file");
            return;
        }

        char *metadata_name = strstr(buffer, "Metadata:");
        if (metadata_name!= NULL) {
            char *metadata_type = strstr(metadata_name, ":");
            if (metadata_type!= NULL) {
                metadata_type += 5;
                char *metadata_value = strstr(metadata_type, "=");
                if (metadata_value!= NULL) {
                    metadata_value += 1;
                    metadata->name = strdup(metadata_name);
                    metadata->size = atoi(metadata_value);
                    metadata->type = atoi(metadata_type);
                }
            }
        }
        i += buffer_size;
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s file_name\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    metadata_t metadata;
    extract_metadata(file_name, &metadata);

    printf("Metadata: %s\n", metadata.name);
    printf("Size: %d\n", metadata.size);
    printf("Type: %d\n", metadata.type);

    return 0;
}