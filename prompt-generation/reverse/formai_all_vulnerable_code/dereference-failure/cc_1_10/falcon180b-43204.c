//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *name;
    char *signature;
    int length;
} Virus;

Virus viruses[] = {
    {"MyDoom", "abcdefghijklmnopqrstuvwxyz", 26},
    {"Slammer", "edcba", 4},
    {"CodeRed", "admin", 5},
    {"ILOVEYOU", "vbs", 4},
    {"Melissa", "qwert", 6}
};

int numViruses = sizeof(viruses) / sizeof(Virus);

int isInfected(char *fileContent, int fileSize, Virus *virus) {
    int i = 0;
    while (i < fileSize && i < virus->length) {
        if (fileContent[i]!= virus->signature[i]) {
            return 0;
        }
        i++;
    }
    if (i == virus->length) {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    if (fileSize > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(file);
        return 1;
    }

    char *fileContent = (char *) malloc(fileSize + 1);
    if (fileContent == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    fread(fileContent, fileSize, 1, file);
    fileContent[fileSize] = '\0';

    int infected = 0;
    for (int i = 0; i < numViruses; i++) {
        if (isInfected(fileContent, fileSize, &viruses[i])) {
            printf("File is infected with %s.\n", viruses[i].name);
            infected = 1;
            break;
        }
    }

    if (!infected) {
        printf("File is clean.\n");
    }

    free(fileContent);
    fclose(file);

    return 0;
}