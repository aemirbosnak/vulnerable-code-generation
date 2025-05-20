//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIZE 1024
#define VIRUS_NAME "SurrealVirus"
#define ANTIVIRUS_NAME "SurrealAntivirus"
#define CLEAN_MSG "Your system is clean.\n"
#define INFECTED_MSG "Your system is infected with %s.\n"

typedef struct {
    char magic[8];
    int version;
    char virusname[32];
    int virussize;
} virus_header_t;

int is_infected(FILE *file) {
    virus_header_t header;
    fseek(file, 0, SEEK_SET);
    fread(&header, sizeof(header), 1, file);

    if (memcmp(header.magic, "SURVIRUS", sizeof(header.magic)) == 0 &&
        header.version == 1 &&
        strlen(header.virusname) == sizeof(header.virusname) - 1 &&
        header.virussize == VIRUS_SIZE) {
        return 1;
    }

    return 0;
}

int clean_file(FILE *file) {
    virus_header_t header;
    char buffer[VIRUS_SIZE];

    fseek(file, 0, SEEK_SET);
    fread(&header, sizeof(header), 1, file);

    if (is_infected(file)) {
        printf(INFECTED_MSG, ANTIVIRUS_NAME);
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_SET);
    fread(buffer, sizeof(buffer), 1, file);

    if (memcmp(buffer, VIRUS_NAME, sizeof(VIRUS_NAME) - 1) == 0) {
        printf(INFECTED_MSG, VIRUS_NAME);
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int result = clean_file(file);

    if (result) {
        printf(CLEAN_MSG);
    }

    return 0;
}