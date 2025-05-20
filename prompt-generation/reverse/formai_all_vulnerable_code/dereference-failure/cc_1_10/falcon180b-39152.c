//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 1024
#define MAX_FILE_SIZE (1024 * 1024) // 1MB

typedef struct {
    char name[32];
    unsigned char signature[MAX_VIRUS_SIZE];
    size_t size;
} Virus;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large (%zu bytes).\n", file_size);
        fclose(file);
        return 1;
    }

    rewind(file);

    Virus *viruses = calloc(MAX_VIRUS_SIZE / sizeof(Virus), sizeof(Virus));
    size_t num_viruses = 0;

    while (fread(&viruses[num_viruses], sizeof(Virus), 1, file) == 1) {
        if (++num_viruses >= MAX_VIRUS_SIZE / sizeof(Virus)) {
            printf("Error: Too many viruses found.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    for (size_t i = 0; i < num_viruses; ++i) {
        printf("Found virus: %s\n", viruses[i].name);
    }

    return 0;
}