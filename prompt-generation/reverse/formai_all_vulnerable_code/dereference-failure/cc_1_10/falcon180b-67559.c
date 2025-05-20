//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *filename;
    char *backup_filename;
} FileBackup;

int main() {
    int num_files;
    char *dir_path;
    char **file_list;
    FileBackup *backup_list;
    int i, j;

    // Get directory path and list of files
    printf("Enter directory path: ");
    scanf("%s", dir_path);
    printf("Enter number of files: ");
    scanf("%d", &num_files);
    file_list = (char **) malloc(num_files * sizeof(char *));
    for (i = 0; i < num_files; i++) {
        printf("Enter file %d: ", i+1);
        scanf("%s", file_list[i]);
    }

    // Create backup list
    backup_list = (FileBackup *) malloc(num_files * sizeof(FileBackup));
    for (i = 0; i < num_files; i++) {
        backup_list[i].filename = file_list[i];
        strcat(backup_list[i].filename, ".bak");
        backup_list[i].backup_filename = (char *) malloc(strlen(backup_list[i].filename) * sizeof(char));
        strcpy(backup_list[i].backup_filename, backup_list[i].filename);
    }

    // Backup files
    for (i = 0; i < num_files; i++) {
        FILE *file = fopen(file_list[i], "r");
        if (file == NULL) {
            printf("Error opening file %s\n", file_list[i]);
            exit(1);
        }
        FILE *backup_file = fopen(backup_list[i].backup_filename, "w");
        if (backup_file == NULL) {
            printf("Error creating backup file %s\n", backup_list[i].backup_filename);
            exit(1);
        }
        char c;
        while ((c = fgetc(file))!= EOF) {
            fputc(c, backup_file);
        }
        fclose(file);
        fclose(backup_file);
    }

    printf("Backup completed successfully.\n");

    return 0;
}