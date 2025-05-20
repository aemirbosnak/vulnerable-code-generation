//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) /* 10MB */

typedef struct {
    char *name;
    int is_virus;
} virus_t;

virus_t viruses[] = {
    {"my_virus.exe", 1},
    {"your_virus.dll", 1},
    {"their_virus.sys", 1},
    {"not_a_virus.txt", 0}
};

int num_viruses = sizeof(viruses) / sizeof(viruses[0]);

int is_file_infected(const char *filename) {
    int i;
    for (i = 0; i < num_viruses; i++) {
        if (strcmp(filename, viruses[i].name) == 0) {
            return viruses[i].is_virus;
        }
    }
    return 0;
}

void scan_file(const char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int file_size = 0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }

    while (fread(buffer, 1, MAX_FILE_SIZE - file_size, fp) > 0) {
        file_size += fread(buffer, 1, MAX_FILE_SIZE - file_size, fp);
    }

    fclose(fp);

    int is_infected = is_file_infected(filename);

    if (is_infected) {
        printf("Virus found in file '%s'!\n", filename);
    } else {
        printf("File '%s' is clean.\n", filename);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}