//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char *filename;
    FILE *file;
} File;

void backup_file(const char *filename) {
    char backup_filename[strlen(filename) + strlen(BACKUP_EXTENSION)];
    strcpy(backup_filename, filename);
    strcat(backup_filename, BACKUP_EXTENSION);

    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", backup_filename);
        exit(1);
    }

    File original_file = {
       .filename = filename,
       .file = fopen(filename, "r")
    };

    if (original_file.file == NULL) {
        printf("Error opening original file: %s\n", original_file.filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, original_file.file)!= NULL) {
        fputs(line, backup_file);
    }

    fclose(original_file.file);
    fclose(backup_file);

    printf("Backup created: %s\n", backup_filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    backup_file(argv[1]);

    return 0;
}