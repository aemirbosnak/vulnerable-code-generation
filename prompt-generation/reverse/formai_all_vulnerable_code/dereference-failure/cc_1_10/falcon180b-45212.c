//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_LINE_SIZE 1000

typedef struct {
    char filename[MAX_FILE_NAME];
    char backup_filename[MAX_FILE_NAME];
    FILE *file;
    FILE *backup_file;
} FILE_BACKUP;

void backup_file(FILE_BACKUP *backup) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, backup->file)!= NULL) {
        fputs(line, backup->backup_file);
    }
    fclose(backup->file);
    fclose(backup->backup_file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <backup_filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_NAME] = "";
    char backup_filename[MAX_FILE_NAME] = "";

    strcpy(filename, argv[1]);
    strcpy(backup_filename, argv[2]);

    FILE_BACKUP backup = {
       .filename = filename,
       .backup_filename = backup_filename,
       .file = fopen(filename, "r"),
       .backup_file = fopen(backup_filename, "w")
    };

    if (backup.file == NULL || backup.backup_file == NULL) {
        printf("Error opening file(s)\n");
        return 1;
    }

    backup_file(&backup);

    printf("Backup completed successfully!\n");
    return 0;
}