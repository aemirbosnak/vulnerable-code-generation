//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VIRUS_COUNT 100
#define MAX_FILE_SIZE (1024 * 1024)

typedef struct {
    char *name;
    int count;
} virus_info;

virus_info viruses[MAX_VIRUS_COUNT];
int virus_count = 0;

void add_virus(char *name) {
    if (virus_count >= MAX_VIRUS_COUNT) {
        printf("Error: too many viruses.\n");
        exit(1);
    }
    viruses[virus_count].name = strdup(name);
    viruses[virus_count].count = 0;
    virus_count++;
}

int scan_file(FILE *file, int *total_viruses) {
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_count++;
        int i;
        for (i = 0; i < virus_count; i++) {
            if (strstr(line, viruses[i].name)!= NULL) {
                viruses[i].count++;
                (*total_viruses)++;
            }
        }
    }
    return line_count;
}

void print_viruses(int total_viruses) {
    printf("Total viruses found: %d\n", total_viruses);
    printf("Virus\t\tCount\n");
    for (int i = 0; i < virus_count; i++) {
        printf("%s\t\t%d\n", viruses[i].name, viruses[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    int total_viruses = 0;
    int file_size = 0;
    while (file_size < MAX_FILE_SIZE) {
        int bytes_read = fread(NULL, 1, MAX_FILE_SIZE - file_size, file);
        if (bytes_read == 0) {
            break;
        }
        file_size += bytes_read;
    }
    rewind(file);
    int lines_scanned = scan_file(file, &total_viruses);
    fclose(file);
    if (total_viruses > 0) {
        printf("The following viruses were found:\n");
    } else {
        printf("No viruses found.\n");
    }
    print_viruses(total_viruses);
    return 0;
}