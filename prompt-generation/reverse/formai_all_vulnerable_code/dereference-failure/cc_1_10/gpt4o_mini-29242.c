//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BACKUPS 10

void print_help() {
    printf("Usage: ./backup_system [source_directory] [backup_directory]\n");
    printf("This program backs up files from source_directory to backup_directory.\n");
    printf("Add -h or --help for help.\n");
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void create_backup(const char *source, const char *backup) {
    struct stat sb;
    if (stat(source, &sb) == -1) {
        perror("Error accessing source directory");
        return;
    }

    char backup_path[MAX_PATH_LENGTH];
    snprintf(backup_path, sizeof(backup_path), "%s/backup", backup);
    mkdir(backup_path, 0700);

    const char *current_backup_dirs[MAX_BACKUPS];
    int backup_count = 0;
    struct dirent *entry;
    DIR *dp = opendir(source);

    if (dp == NULL) {
        perror("Error opening source directory");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            current_backup_dirs[backup_count] = entry->d_name;
            backup_count++;
        }
    }
    closedir(dp);

    for (int i = 0; i < backup_count; i++) {
        char source_file[MAX_PATH_LENGTH];
        char backup_file[MAX_PATH_LENGTH];

        snprintf(source_file, sizeof(source_file), "%s/%s", source, current_backup_dirs[i]);
        snprintf(backup_file, sizeof(backup_file), "%s/%s", backup_path, current_backup_dirs[i]);

        if (access(source_file, F_OK) != -1) {
            FILE *src = fopen(source_file, "rb");
            FILE *dest = fopen(backup_file, "wb");

            if (src == NULL || dest == NULL) {
                perror("Error opening file");
                continue;
            }

            char buffer[BUFSIZ];
            size_t n;
            while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
                fwrite(buffer, 1, n, dest);
            }

            fclose(src);
            fclose(dest);
            printf("Backed up: %s to %s\n", source_file, backup_file);
        }
    }
}

void list_backups(const char *backup) {
    char backup_path[MAX_PATH_LENGTH];
    snprintf(backup_path, sizeof(backup_path), "%s/backup", backup);
    DIR *dp = opendir(backup_path);
    struct dirent *entry;

    if (dp == NULL) {
        perror("Error opening backup directory");
        return;
    }

    printf("Backed up files:\n");
    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            printf("%s\n", entry->d_name);
        }
    }
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_help();
        return 1;
    }

    const char *source_directory = argv[1];
    const char *backup_directory = argv[2];

    if (!is_directory(source_directory)) {
        fprintf(stderr, "Error: Source directory does not exist or is not a directory.\n");
        return 1;
    }

    if (!is_directory(backup_directory)) {
        fprintf(stderr, "Error: Backup directory does not exist or is not a directory.\n");
        return 1;
    }

    create_backup(source_directory, backup_directory);
    list_backups(backup_directory);

    return 0;
}