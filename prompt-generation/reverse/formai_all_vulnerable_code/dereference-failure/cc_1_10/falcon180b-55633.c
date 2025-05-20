//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define BACKUP_EXT ".bak"

typedef struct {
    char *filename;
    FILE *fp;
} File;

void backup_file(char *filename) {
    char *bak_filename = malloc(strlen(filename) + strlen(BACKUP_EXT) + 1);
    strcpy(bak_filename, filename);
    strcat(bak_filename, BACKUP_EXT);

    FILE *bak_fp = fopen(bak_filename, "w");
    if (bak_fp == NULL) {
        printf("Error creating backup file '%s'\n", bak_filename);
        exit(1);
    }

    free(bak_filename);
}

void process_line(char *line, size_t len) {
    char *word = strtok(line, " \t\n\r\f\v");
    while (word!= NULL) {
        printf("%s ", word);
        word = strtok(NULL, " \t\n\r\f\v");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    File file = {.filename = filename,.fp = fopen(filename, "r") };

    if (file.fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        return 1;
    }

    char line[MAX_LINE_LEN];
    backup_file(filename);

    while (fgets(line, MAX_LINE_LEN, file.fp)!= NULL) {
        process_line(line, strlen(line));
    }

    fclose(file.fp);
    free(file.filename);
    return 0;
}