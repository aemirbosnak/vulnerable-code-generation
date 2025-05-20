//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[] = {
    {"Dummy Virus", "1234567890"},
    {"Another Virus", "0987654321"},
    {"Yet Another Virus", "1112223333"},
    {"Last Virus", "5555555555"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

int scan_file(FILE *file, virus_t *virus) {
    char buffer[MAX_VIRUS_LENGTH];
    int i, j;

    for (i = 0; i < MAX_VIRUS_LENGTH - strlen(virus->signature); i++) {
        if (fgetc(file)!= virus->signature[i]) {
            return 0;
        }
    }

    for (i = 0; i < MAX_VIRUS_LENGTH - strlen(virus->signature); i++) {
        if (fgetc(file)!= virus->signature[i]) {
            break;
        }
    }

    if (i == strlen(virus->signature)) {
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    int i, infected = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    for (i = 0; i < num_viruses; i++) {
        if (scan_file(file, &viruses[i])) {
            printf("Virus '%s' found in file '%s'.\n", viruses[i].name, argv[1]);
            infected = 1;
        }
    }

    if (!infected) {
        printf("File '%s' is clean.\n", argv[1]);
    }

    fclose(file);

    return 0;
}