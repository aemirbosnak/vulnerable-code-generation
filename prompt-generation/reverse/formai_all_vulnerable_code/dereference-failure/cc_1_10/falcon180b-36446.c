//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *filename;
char *backup_filename;
char *extension;
char *backup_extension;
char *backup_path;

void get_filename(char *filename) {
    printf("Enter filename: ");
    scanf("%s", filename);
}

void get_extension(char *extension) {
    printf("Enter extension: ");
    scanf("%s", extension);
}

void get_backup_path(char *backup_path) {
    printf("Enter backup path: ");
    scanf("%s", backup_path);
}

void backup_file(char *filename, char *backup_filename, char *backup_path) {
    FILE *file;
    FILE *backup_file;
    char buffer[1000];

    strcat(backup_filename, ".bak");
    strcat(backup_path, backup_filename);

    backup_file = fopen(backup_path, "w");
    if (backup_file == NULL) {
        printf("Error creating backup file.\n");
        exit(1);
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(file);
    fclose(backup_file);
}

void main() {
    printf("Welcome to the Retro File Backup System!\n");
    printf("Please enter the filename, extension, and backup path:\n");

    get_filename(filename);
    get_extension(extension);
    get_backup_path(backup_path);

    backup_filename = malloc(strlen(filename) + strlen(extension) + 2);
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".");

    backup_extension = malloc(strlen(extension));
    strcpy(backup_extension, extension);

    backup_file(filename, backup_filename, backup_path);

    printf("Backup completed successfully!\n");
}