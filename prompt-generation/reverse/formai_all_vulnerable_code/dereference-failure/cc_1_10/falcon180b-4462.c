//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 100
#define VIRUS_NAME_LEN 50
#define VIRUS_SIG_LEN 100
#define FILE_NAME_LEN 256

typedef struct virus {
    char name[VIRUS_NAME_LEN];
    char signature[VIRUS_SIG_LEN];
} Virus;

Virus viruses[MAX_VIRUSES];
int num_viruses;

void load_viruses() {
    FILE *fp;
    char line[1024];
    int i = 0;

    fp = fopen("viruses.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open viruses.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_VIRUSES) {
            printf("Error: Too many viruses in viruses.txt\n");
            exit(1);
        }

        strcpy(viruses[i].name, strtok(line, ":"));
        strcpy(viruses[i].signature, strtok(NULL, ":"));

        i++;
    }

    fclose(fp);
    num_viruses = i;
}

int scan_file(char *filename) {
    FILE *fp;
    char buffer[1024];
    int file_size;
    int i;

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Unable to open %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    for (i = 0; i < num_viruses; i++) {
        while (fread(buffer, 1, viruses[i].signature[0], fp) > 0) {
            if (memcmp(buffer, viruses[i].signature, viruses[i].signature[0]) == 0) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    load_viruses();

    if (scan_file(argv[1]) == 1) {
        exit(1);
    }

    printf("No viruses found\n");
    return 0;
}