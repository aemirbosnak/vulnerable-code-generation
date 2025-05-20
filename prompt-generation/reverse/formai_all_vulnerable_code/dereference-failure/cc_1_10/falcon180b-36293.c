//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to scan
#define VIRUS_SIGNATURE "This is a virus" // Signature to look for
#define VIRUS_FOUND 1 // Flag to indicate virus found
#define LINE_SIZE 1024 // Maximum line size

int is_virus(char *line) {
    int i, j;
    for (i = 0; i < strlen(VIRUS_SIGNATURE); i++) {
        if (tolower(line[i])!= tolower(VIRUS_SIGNATURE[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int virus_found = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &len, file))!= -1) {
        if (is_virus(line)) {
            printf("Virus found in line: %s\n", line);
            virus_found = VIRUS_FOUND;
        }
    }

    if (virus_found) {
        printf("Virus found in file: %s\n", argv[1]);
    } else {
        printf("No virus found in file: %s\n", argv[1]);
    }

    free(line);
    fclose(file);

    return 0;
}