//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} file_t;

int is_infected(unsigned char *data, size_t size) {
    const unsigned char virus_signature[] = {0x55, 0xAA, 0x00, 0x3C};
    for (size_t i = 0; i < size - sizeof(virus_signature); i++) {
        if (memcmp(data + i, virus_signature, sizeof(virus_signature)) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file_t file = {0};
    file.name = argv[1];

    FILE *fp = fopen(file.name, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", file.name);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    if (file.size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (%zu bytes).\n", file.name, file.size);
        fclose(fp);
        return 1;
    }

    rewind(fp);
    file.data = malloc(file.size);
    if (file.data == NULL) {
        printf("Error: Could not allocate memory for file '%s'.\n", file.name);
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(file.data, 1, file.size, fp);
    if (bytes_read!= file.size) {
        printf("Error: Could not read entire file '%s'.\n", file.name);
        free(file.data);
        fclose(fp);
        return 1;
    }

    int is_infected_result = is_infected(file.data, file.size);

    free(file.data);
    fclose(fp);

    if (is_infected_result) {
        printf("File '%s' is infected with a virus.\n", file.name);
    } else {
        printf("File '%s' is clean.\n", file.name);
    }

    return 0;
}