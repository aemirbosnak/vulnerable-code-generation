//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (10*1024*1024) // 10MB

typedef struct {
    char *name;
    bool is_virus;
} VirusDefinition;

VirusDefinition viruses[] = {
    {"WannaCry", true},
    {"Petya", true},
    {"Locky", true},
    {"Cerber", true},
    {"TeslaCrypt", true},
    {"Cryptolocker", true},
    {"Dridex", true},
    {"Emotet", true},
    {"TrickBot", true},
    {"Ryuk", true},
};

int num_viruses = sizeof(viruses) / sizeof(VirusDefinition);

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    if (bytes_read == 0) {
        printf("File is empty: %s\n", filename);
        return;
    }

    for (int i = 0; i < num_viruses; i++) {
        VirusDefinition virus = viruses[i];
        bool found_virus = false;

        for (int j = 0; j < bytes_read; j++) {
            if (buffer[j] == tolower(virus.name[j])) {
                found_virus = true;
                break;
            }
        }

        if (found_virus) {
            printf("Virus found: %s\n", virus.name);
            return;
        }
    }

    printf("No viruses found in file: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    scan_file(filename);

    return 0;
}