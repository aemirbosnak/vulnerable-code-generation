//FormAI DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/* Function to copy files from source to destination */
void copyFile(char *source, char *destination) {
    FILE *fptr1, *fptr2;
    char c;

    fptr1 = fopen(source, "r");
    fptr2 = fopen(destination, "w");

    if (fptr1 == NULL || fptr2 == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }

    while ((c = fgetc(fptr1)) != EOF) {
        fputc(c, fptr2);
    }

    printf("File copied successfully!\n");

    fclose(fptr1);
    fclose(fptr2);
}

/* Function to backup files */
void backup(char *sourceDir, char *backupDir) {
    struct dirent *de;
    DIR *dr = opendir(sourceDir);

    if (dr == NULL) {
        printf("Could not open directory!\n");
        exit(1);
    }

    /* Create backup directory if it does not exist */
    struct stat st = {0};
    if (stat(backupDir, &st) == -1) {
        mkdir(backupDir, 0777);
    }

    while ((de = readdir(dr)) != NULL) {
        /* Skip directories . and .. */
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }

        char filePath[100];
        sprintf(filePath, "%s/%s", sourceDir, de->d_name);

        struct stat fileStat;
        if (stat(filePath,&fileStat) < 0) {
            continue;
        }

        /* Check if file is a regular file */
        if (S_ISREG(fileStat.st_mode)) {
            char backupPath[100];
            sprintf(backupPath, "%s/%s", backupDir, de->d_name);
            copyFile(filePath, backupPath);
        }
    }

    closedir(dr);
}

int main(int argc, char **argv) {
    char *sourceDir = argv[1];
    char *backupDir = argv[2];

    if (argc != 3) {
        printf("Usage: ./backup <source_directory> <backup_directory>\n");
        exit(1);
    }

    backup(sourceDir, backupDir);

    return 0;
}