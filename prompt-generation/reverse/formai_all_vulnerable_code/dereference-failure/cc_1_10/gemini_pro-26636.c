//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VIRUS_DEFINITIONS 100

typedef struct {
    char *name;
    char *signature;
    int length;
} VirusDefinition;

VirusDefinition virus_definitions[MAX_VIRUS_DEFINITIONS];
int num_virus_definitions = 0;

bool load_virus_definitions(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return false;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");
        int length = strlen(signature);

        VirusDefinition virus_definition = {
            .name = strdup(name),
            .signature = strdup(signature),
            .length = length
        };

        virus_definitions[num_virus_definitions++] = virus_definition;
    }

    fclose(fp);
    return true;
}

bool scan_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return false;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(file_size);
    fread(buffer, 1, file_size, fp);

    bool infected = false;
    for (int i = 0; i < num_virus_definitions; i++) {
        VirusDefinition virus_definition = virus_definitions[i];
        char *signature = virus_definition.signature;
        int length = virus_definition.length;

        for (int j = 0; j < file_size - length; j++) {
            if (memcmp(&buffer[j], signature, length) == 0) {
                printf("File %s is infected with virus %s\n", filename, virus_definition.name);
                infected = true;
            }
        }
    }

    free(buffer);
    fclose(fp);

    return infected;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <virus definitions file> <file to scan>\n", argv[0]);
        return 1;
    }

    if (!load_virus_definitions(argv[1])) {
        printf("Error loading virus definitions file\n");
        return 1;
    }

    if (scan_file(argv[2])) {
        printf("File %s is infected\n", argv[2]);
        return 1;
    } else {
        printf("File %s is clean\n", argv[2]);
        return 0;
    }
}