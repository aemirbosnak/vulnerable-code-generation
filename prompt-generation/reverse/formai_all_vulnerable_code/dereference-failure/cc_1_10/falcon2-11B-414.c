//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char* directory = argv[1];
    char* backup_dir = "backup";
    char log_file[100];

    struct stat sb;
    if (stat(backup_dir, &sb)!= 0) {
        if (mkdir(backup_dir, 0755) == 0) {
            printf("Created backup directory: %s\n", backup_dir);
        } else {
            printf("Failed to create backup directory: %s\n", backup_dir);
            exit(1);
        }
    }

    FILE* log = fopen(log_file, "w");
    if (log == NULL) {
        printf("Failed to open log file: %s\n", log_file);
        exit(1);
    }

    DIR* dir = opendir(directory);
    if (dir == NULL) {
        printf("Failed to open directory: %s\n", directory);
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char* file_name = entry->d_name;
        char* full_path = (char*)malloc(strlen(directory) + strlen(file_name) + 2);
        strcpy(full_path, directory);
        strcat(full_path, "/");
        strcat(full_path, file_name);

        struct stat file_stat;
        if (stat(full_path, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) {
                printf("Backing up %s...\n", full_path);

                char* backup_path = (char*)malloc(strlen(backup_dir) + strlen(file_name) + 2);
                strcpy(backup_path, backup_dir);
                strcat(backup_path, "/");
                strcat(backup_path, file_name);

                FILE* fp = fopen(backup_path, "wb");
                if (fp!= NULL) {
                    fclose(fp);
                    printf("Backed up %s to %s\n", full_path, backup_path);
                    fprintf(log, "%s\n", backup_path);
                    free(full_path);
                    free(backup_path);
                } else {
                    printf("Failed to create backup file: %s\n", backup_path);
                }
            } else {
                printf("Not a regular file: %s\n", full_path);
            }
        } else {
            printf("Failed to stat file: %s\n", full_path);
        }
        free(full_path);
    }

    closedir(dir);
    fclose(log);

    return 0;
}