//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 256
#define MAX_LINE_SIZE 1024
#define MAX_VIRUS_SIGNATURES 100

typedef struct {
    char *name;
    char *signature;
} virus_signature_t;

virus_signature_t virus_signatures[MAX_VIRUS_SIGNATURES] = {
    {"MyDoom", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"},
    {"Slammer", "1234567890"},
    {"CodeRed", "qwertyuiopQWERTYUIOPASDFGHJKLZXCVBNM"},
    {"ILOVEYOU", "ILOVEYOU"},
    {"Melissa", "Melissa"}
};

int num_virus_signatures = sizeof(virus_signatures) / sizeof(virus_signature_t);

void scan_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_SIZE];
    int line_num = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_num++;
        for (int i = 0; i < num_virus_signatures; i++) {
            if (strstr(line, virus_signatures[i].signature)!= NULL) {
                printf("Virus found in file %s at line %d: %s\n", filename, line_num, virus_signatures[i].name);
                return;
            }
        }
    }

    printf("No viruses found in file %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file.ext\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}