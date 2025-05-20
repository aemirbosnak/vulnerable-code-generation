//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_VIRUS_LENGTH 1024
#define VIRUS_COUNT 5

// Virus signatures
char virus1[] = "This is virus 1";
char virus2[] = "This is virus 2";
char virus3[] = "This is virus 3";
char virus4[] = "This is virus 4";
char virus5[] = "This is virus 5";

void scan_file(FILE *fp, char **viruses) {
    char buffer[MAX_VIRUS_LENGTH];
    int buffer_index = 0;
    int virus_found = 0;

    while (fgets(buffer, MAX_VIRUS_LENGTH, fp)!= NULL) {
        for (int i = 0; i < VIRUS_COUNT; i++) {
            if (strstr(buffer, viruses[i])!= NULL) {
                printf("Virus found: %s\n", viruses[i]);
                virus_found = 1;
                break;
            }
        }
        if (virus_found) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char **viruses = malloc(VIRUS_COUNT * sizeof(char *));
    viruses[0] = virus1;
    viruses[1] = virus2;
    viruses[2] = virus3;
    viruses[3] = virus4;
    viruses[4] = virus5;

    scan_file(fp, viruses);

    fclose(fp);

    return 0;
}