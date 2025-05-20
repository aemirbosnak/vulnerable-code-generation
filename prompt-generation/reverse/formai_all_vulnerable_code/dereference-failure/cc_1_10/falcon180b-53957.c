//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define VIRUS_SIGNATURE "medievalvirus"

int is_infected(FILE *file, char *buffer) {
    int i;
    for (i = 0; i < strlen(VIRUS_SIGNATURE) && i < strlen(buffer); i++) {
        if (VIRUS_SIGNATURE[i]!= buffer[i]) {
            return 0;
        }
    }
    return 1;
}

void scan_file(FILE *file, char *filename) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    int is_infected_flag = 0;

    printf("Scanning %s...\n", filename);
    rewind(file);
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file))!= 0) {
        if (is_infected(file, buffer)) {
            is_infected_flag = 1;
            break;
        }
    }

    if (is_infected_flag) {
        printf("Virus detected in %s!\n", filename);
    } else {
        printf("%s is clean.\n", filename);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char filename[strlen(argv[1]) + 1];
    strcpy(filename, argv[1]);
    scan_file(file, filename);

    fclose(file);
    return 0;
}