//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan(char *filename);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Please enter a filename to scan.\n");
        exit(1);
    }

    char *filename = strdup(argv[1]);

    printf("Scanning file: %s\n", filename);
    scan(filename);

    free(filename);

    return 0;
}

void scan(char *filename) {

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Cannot open file.\n");
        return;
    }

    int virus_count = 0;
    char *buffer = malloc(1024 * sizeof(char));

    while (!feof(file)) {
        fread(buffer, 1, 1024, file);

        if (strstr(buffer, "zombie") || strstr(buffer, "apocalypse") || strstr(buffer, "survival")) {
            virus_count++;
        }
    }

    if (virus_count > 0) {
        printf("Virus detected! %d infected files found.\n", virus_count);
    } else {
        printf("No virus detected.\n");
    }

    free(buffer);
    fclose(file);
}