//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024
#define MAX_VIRUS_NAMES 100
#define MAX_VIRUS_NAME_LENGTH 50

char *virus_names[MAX_VIRUS_NAMES];
int num_viruses = 0;

void load_virus_names(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char name[MAX_VIRUS_NAME_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open virus names file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int j = 0;
        while (isspace(line[j])) {
            j++;
        }
        if (line[j]!= '#' && line[j]!= '\n') {
            strcpy(name, &line[j]);
            virus_names[i] = (char *)malloc(strlen(name) + 1);
            strcpy(virus_names[i], name);
            i++;
        }
    }

    num_viruses = i;
    fclose(file);
}

int is_virus(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int j = 0;
        while (isspace(line[j])) {
            j++;
        }
        if (line[j]!= '#' && line[j]!= '\n') {
            for (i = 0; i < num_viruses; i++) {
                if (strstr(line, virus_names[i])!= NULL) {
                    printf("Virus found in file '%s': %s\n", filename, virus_names[i]);
                    fclose(file);
                    return 1;
                }
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    load_virus_names("viruses.txt");

    is_virus(argv[1]);

    return 0;
}