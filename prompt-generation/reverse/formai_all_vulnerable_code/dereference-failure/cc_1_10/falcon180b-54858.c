//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define NUM_VIRUSES 3
#define VIRUS_NAMES {"virus1", "virus2", "virus3"}

struct virus {
    char *name;
    char *signature;
};

struct virus viruses[NUM_VIRUSES];

int main(int argc, char **argv) {
    char *file_data = NULL;
    size_t file_size = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: could not open file '%s'.\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file is too large.\n");
        fclose(file);
        return 1;
    }

    file_data = malloc(file_size + 1);
    if (!file_data) {
        printf("Error: could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(file_data, file_size, 1, file);
    fclose(file);

    for (i = 0; i < NUM_VIRUSES; i++) {
        if (strstr(file_data, viruses[i].signature)) {
            printf("Virus found: %s\n", viruses[i].name);
            return 1;
        }
    }

    printf("No viruses found.\n");
    return 0;
}