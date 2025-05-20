//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10MB

typedef struct {
    char *signature;
    int length;
} virus_t;

virus_t viruses[] = {
    {"WannaCry", 7},
    {"Locky", 5},
    {"Petya", 5},
    {"BadRabbit", 9},
    {"Emotet", 7},
    {"TrickBot", 8},
    {"Dridex", 6},
    {"Krablin", 8},
    {"Dorkbot", 8},
    {"Koobface", 9}
};

int num_viruses = sizeof(viruses)/sizeof(virus_t);

void scan_file(FILE *file, virus_t virus) {
    char buffer[MAX_FILE_SIZE];
    int buffer_pos = 0;
    int i;

    fseek(file, 0, SEEK_SET);
    while (fread(buffer+buffer_pos, 1, MAX_FILE_SIZE-buffer_pos, file) > 0) {
        buffer_pos += fread(buffer+buffer_pos, 1, MAX_FILE_SIZE-buffer_pos, file);
    }

    for (i = 0; i < buffer_pos; i++) {
        if (tolower(buffer[i]) == tolower(virus.signature[0])) {
            int j;
            for (j = 1; j < virus.length; j++) {
                if (i+j >= buffer_pos) {
                    break;
                }
                if (tolower(buffer[i+j])!= tolower(virus.signature[j])) {
                    break;
                }
            }
            if (j == virus.length) {
                printf("Virus '%s' found in file!\n", virus.signature);
            }
        }
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

    char *filename = strrchr(argv[1], '/');
    if (filename == NULL) {
        filename = argv[1];
    } else {
        filename++;
    }

    printf("Scanning '%s' for viruses...\n", filename);

    int virus_found = 0;
    int total_scanned = 0;

    for (int i = 0; i < num_viruses; i++) {
        scan_file(file, viruses[i]);
        total_scanned++;
    }

    if (!virus_found) {
        printf("No viruses found in '%s'.\n", filename);
    } else {
        printf("%d virus%s found in '%s'.\n", virus_found, virus_found>1?"es":" ", filename);
    }

    fclose(file);
    return 0;
}