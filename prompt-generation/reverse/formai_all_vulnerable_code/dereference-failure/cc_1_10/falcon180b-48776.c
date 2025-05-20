//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 512
#define MAX_VIRUS_NAME_LENGTH 256

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_LENGTH];
} Virus;

int num_viruses = 0;
Virus viruses[100];

int load_viruses() {
    FILE *file;
    char line[MAX_VIRUS_LENGTH];
    char *token;
    int i = 0;

    file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: could not open viruses file\n");
        return -1;
    }

    while (fgets(line, MAX_VIRUS_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        strcpy(viruses[i].name, token);
        token = strtok(NULL, ",");
        strcpy(viruses[i].signature, token);
        i++;
    }

    num_viruses = i;
    fclose(file);

    return 0;
}

int scan_file(char *filename) {
    FILE *file;
    char line[MAX_FILE_NAME_LENGTH];
    char buffer[MAX_VIRUS_LENGTH];
    int i, j;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }

    while (fgets(line, MAX_FILE_NAME_LENGTH, file)!= NULL) {
        for (i = 0; i < num_viruses; i++) {
            for (j = 0; j < strlen(viruses[i].signature); j++) {
                if (tolower(line[j])!= tolower(viruses[i].signature[j])) {
                    break;
                }
            }
            if (j == strlen(viruses[i].signature)) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }

    load_viruses();

    scan_file(argv[1]);

    return 0;
}