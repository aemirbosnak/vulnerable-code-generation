//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_LINE_LENGTH 4096
#define VIRUS_NAME_LENGTH 64

typedef struct {
    char *filename;
    char *virus_name;
} virus_t;

virus_t viruses[] = {
    {"myvirus.exe", "myvirus"},
    {"yourvirus.exe", "yourvirus"},
    {"ourvirus.exe", "ourvirus"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

void scan_file(FILE *file, virus_t *viruses, int num_viruses) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;

        for (int i = 0; i < num_viruses; i++) {
            if (strstr(line, viruses[i].virus_name)!= NULL) {
                printf("Virus found in file '%s' at line %d: %s\n", viruses[i].filename, line_number, viruses[i].virus_name);
                exit(1);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", argv[1]);
        exit(1);
    }

    struct stat file_stat;
    if (fstat(fileno(file), &file_stat) == -1) {
        printf("Error getting file information for '%s'\n", argv[1]);
        exit(1);
    }

    if (!S_ISREG(file_stat.st_mode)) {
        printf("'%s' is not a regular file\n", argv[1]);
        exit(1);
    }

    char filename[MAX_FILE_NAME_LENGTH];
    memset(filename, 0, MAX_FILE_NAME_LENGTH);
    strncpy(filename, argv[1], strlen(argv[1]));

    for (int i = 0; i < num_viruses; i++) {
        if (strstr(filename, viruses[i].virus_name)!= NULL) {
            printf("Virus found in filename '%s': %s\n", filename, viruses[i].virus_name);
            exit(1);
        }
    }

    scan_file(file, viruses, num_viruses);

    fclose(file);
    exit(0);
}