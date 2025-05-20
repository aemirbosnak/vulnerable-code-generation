//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VIRUS_COUNT 100

typedef struct {
    char *name;
    char *signature;
    int length;
} virus;

int virus_count = 0;
virus viruses[MAX_VIRUS_COUNT];

void load_viruses() {
    FILE *fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error loading viruses.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");
        int length = strlen(signature);

        if (virus_count >= MAX_VIRUS_COUNT) {
            printf("Maximum virus count exceeded.\n");
            exit(1);
        }

        viruses[virus_count].name = strdup(name);
        viruses[virus_count].signature = strdup(signature);
        viruses[virus_count].length = length;

        virus_count++;
    }

    fclose(fp);
}

int scan_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i;
        for (i = 0; i < virus_count; i++) {
            char *signature = viruses[i].signature;
            int length = viruses[i].length;

            if (strstr(line, signature)!= NULL) {
                printf("Virus found in file %s: %s\n", filename, viruses[i].name);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    load_viruses();

    int result = scan_file(argv[1]);

    if (result == 0) {
        printf("File is clean.\n");
    }

    return result;
}