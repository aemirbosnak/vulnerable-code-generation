//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

struct backup_info {
    char filename[255];
    char path[255];
    char backup_path[255];
};

struct backup_info backups[] = {
    {"file1.txt", "./", "./backup/"},
    {"file2.txt", "./", "./backup/"},
    {"file3.txt", "./", "./backup/"}
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <backup_path>\n", argv[0]);
        return 1;
    }
    
    char *filename = argv[1];
    char *backup_path = argv[2];

    int i;
    for (i = 0; i < sizeof(backups) / sizeof(backups[0]); i++) {
        if (strcmp(backups[i].filename, filename) == 0) {
            break;
        }
    }
    
    if (i == sizeof(backups) / sizeof(backups[0])) {
        printf("File not found in backup directory.\n");
        return 1;
    }
    
    char *path = strcat(backups[i].path, backups[i].backup_path);
    char *backup_file = strcat(path, backups[i].filename);

    FILE *src = fopen(filename, "r");
    if (src == NULL) {
        printf("Failed to open source file.\n");
        return 1;
    }

    FILE *dst = fopen(backup_file, "w");
    if (dst == NULL) {
        printf("Failed to open backup file.\n");
        fclose(src);
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), src)) {
        fputs(buffer, dst);
    }

    fclose(src);
    fclose(dst);
    printf("Backup created successfully.\n");

    return 0;
}