//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 1024
#define MAX_VIRUS_NAME 1024
#define MAX_LINE_SIZE 1024
#define MAX_VIRUS_COUNT 100

typedef struct {
    char name[MAX_VIRUS_NAME];
    char pattern[MAX_LINE_SIZE];
} virus_t;

int virus_count = 0;
virus_t viruses[MAX_VIRUS_COUNT];

void add_virus(char* name, char* pattern) {
    if (virus_count >= MAX_VIRUS_COUNT) {
        printf("Error: Maximum virus count reached!\n");
        exit(1);
    }

    strcpy(viruses[virus_count].name, name);
    strcpy(viruses[virus_count].pattern, pattern);

    virus_count++;
}

int scan_file(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    int line_number = 1;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int i;
        for (i = 0; i < virus_count; i++) {
            if (strstr(line, viruses[i].pattern)!= NULL) {
                printf("Virus found on line %d: %s\n", line_number, viruses[i].name);
                return 1;
            }
        }

        line_number++;
    }

    fclose(file);

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_NAME];
    strcpy(filename, argv[1]);

    int result = scan_file(filename);

    if (result == 0) {
        printf("File is clean.\n");
    }

    return result;
}