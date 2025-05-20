//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_VIRUS_NAME_SIZE 64
#define MAX_VIRUS_SIGNATURE_SIZE 1024

typedef struct {
    char name[MAX_VIRUS_NAME_SIZE];
    char signature[MAX_VIRUS_SIGNATURE_SIZE];
} virus_t;

typedef struct {
    int count;
    virus_t *viruses;
} virus_list_t;

void read_viruses(virus_list_t *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening virus list file.\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");

        strcpy(list->viruses[list->count].name, name);
        strcpy(list->viruses[list->count].signature, signature);

        list->count++;
    }

    fclose(file);
}

void scan_file(const char *filename, virus_list_t *list) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        return;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int i, j;
        for (i = 0; i < list->count; i++) {
            j = 0;
            while (line[j]!= '\0' && list->viruses[i].signature[j]!= '\0' && tolower(line[j]) == tolower(list->viruses[i].signature[j])) {
                j++;
            }

            if (list->viruses[i].signature[j] == '\0') {
                printf("Virus found: %s\n", list->viruses[i].name);
            }
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <virus_list_file> <file_to_scan>\n", argv[0]);
        return 1;
    }

    virus_list_t list;
    read_viruses(&list, argv[1]);

    scan_file(argv[2], &list);

    return 0;
}