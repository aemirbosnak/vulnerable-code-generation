//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "POSTAPOCALYPTICVIRUS"
#define VIRUS_LENGTH 22

int is_infected(char *file_content, size_t file_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    size_t virus_length = strlen(virus_signature);

    if (file_size < virus_length) {
        return 0;
    }

    return!memcmp(file_content, virus_signature, virus_length);
}

void scan_file(char *file_name) {
    FILE *file;
    char *file_content = NULL;
    size_t file_size = 0;

    file = fopen(file_name, "rb");
    if (!file) {
        printf("Error opening file: %s\n", file_name);
        return;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    file_content = malloc(file_size + 1);
    if (!file_content) {
        printf("Error allocating memory for file content.\n");
        fclose(file);
        return;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    if (is_infected(file_content, file_size)) {
        printf("File is infected with the POSTAPOCALYPTICVIRUS!\n");
    } else {
        printf("File is clean.\n");
    }

    free(file_content);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}