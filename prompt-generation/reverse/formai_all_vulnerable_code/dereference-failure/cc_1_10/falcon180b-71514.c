//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define VIRUS_COUNT 5
#define FILE_BUFFER_SIZE 1024

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[VIRUS_COUNT] = {
    {"MyDoom", "mydoom"},
    {"CodeRed", "codered"},
    {"Slammer", "slammer"},
    {"ILOVEYOU", "iloveyou"},
    {"Stuxnet", "stuxnet"}
};

int scan_file(FILE *file, virus_t *viruses) {
    char buffer[FILE_BUFFER_SIZE];
    int buffer_size;
    int virus_found = 0;

    while ((buffer_size = fread(buffer, 1, FILE_BUFFER_SIZE, file)) > 0) {
        char *p = buffer;
        while (p < buffer + buffer_size) {
            for (int i = 0; i < VIRUS_COUNT; i++) {
                virus_t *v = &viruses[i];
                if (strstr(p, v->signature)) {
                    printf("Virus found: %s\n", v->name);
                    virus_found = 1;
                    break;
                }
            }
            if (virus_found) break;
            p++;
        }
    }

    return virus_found;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int virus_found = 0;
    for (int i = 0; i < VIRUS_COUNT; i++) {
        virus_t *v = &viruses[i];
        virus_found |= scan_file(file, v);
    }

    fclose(file);

    if (!virus_found) {
        printf("No viruses found.\n");
    }

    return 0;
}