//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VIRUS_LENGTH 32

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[] = {
    {"MyDoom", "mydoom.exe"},
    {"Sasser", "sasser.exe"},
    {"Conficker", "autorun.inf"},
    {"Stuxnet", "~WrL0.tmp"},
    {"WannaCry", "mssecsvc.exe"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

bool is_virus(char *file_name) {
    int i;
    for (i = 0; i < num_viruses; i++) {
        if (strcmp(viruses[i].name, file_name) == 0) {
            return true;
        }
    }
    return false;
}

void scan_file(FILE *file, char *file_name) {
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int i, j, k;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                for (j = 0; j < num_viruses; j++) {
                    k = 0;
                    while (isalpha(viruses[j].signature[k]) && (line[i + k] == tolower(viruses[j].signature[k]))) {
                        k++;
                    }
                    if (k == strlen(viruses[j].signature)) {
                        printf("Virus found in file '%s' at line %d: %s\n", file_name, line_number, viruses[j].name);
                        exit(1);
                    }
                }
            }
        }
        line_number++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        exit(1);
    }
    char file_name[MAX_LINE_LENGTH];
    strcpy(file_name, argv[1]);
    scan_file(file, file_name);
    fclose(file);
    printf("No viruses found in file '%s'\n", argv[1]);
    exit(0);
}