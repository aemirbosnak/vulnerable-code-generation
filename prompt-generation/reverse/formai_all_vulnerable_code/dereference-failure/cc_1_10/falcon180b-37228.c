//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 10
#define MAX_VIRUS_NAME_LEN 50
#define MAX_FILE_NAME_LEN 100

typedef struct {
    char name[MAX_VIRUS_NAME_LEN];
    char pattern[MAX_FILE_NAME_LEN];
} Virus;

Virus viruses[MAX_VIRUSES] = {
    {"WannaCry", "WannaCry.exe"},
    {"Petya", "Petya.exe"},
    {"Locky", "Locky.exe"}
};

int numViruses = sizeof(viruses) / sizeof(Virus);

void scanFile(char* fileName, Virus* virus) {
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", fileName);
        return;
    }

    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        int i = 0;
        while (i < strlen(buffer)) {
            if (strstr(buffer + i, virus->pattern)!= NULL) {
                printf("Virus found: %s\n", virus->name);
                exit(1);
            }
            i++;
        }
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    char* fileName = argv[1];
    int fileLen = strlen(fileName);

    if (fileLen < 4) {
        printf("Invalid file name\n");
        exit(1);
    }

    char* ext = fileName + fileLen - 4;

    int i = 0;
    while (i < numViruses) {
        if (strcmp(ext, viruses[i].pattern) == 0) {
            scanFile(fileName, &viruses[i]);
        }
        i++;
    }

    printf("No virus found\n");
    return 0;
}