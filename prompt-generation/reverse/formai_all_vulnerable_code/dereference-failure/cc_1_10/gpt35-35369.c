//FormAI DATASET v1.0 Category: File Backup System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h> // for scanning directories

#define MAX 1024 // Maximum buffer size for file paths
#define MAX_BACKUPS 10 // Maximum number of file backups to keep
#define BACKUP_DIR "backups/" // Directory to store backups in
#define CONFIG_FILE "config.txt" // Config file name

// Function prototypes
void create_backup(char* file_path);
void delete_backup(char* backup_path);
char* get_timestamp();
void read_config();
void save_config();

// Global variables
int max_backups = MAX_BACKUPS;
char backup_dir[MAX] = BACKUP_DIR;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: cbackup [file_path]\n");
        exit(1);
    }

    char* file_path = argv[1];

    // Create backup of file
    create_backup(file_path);

    // Read the configuration file to get max backups and backup directory
    read_config();

    // Delete excess backups
    DIR* dir = opendir(backup_dir);
    if (dir != NULL) {
        struct dirent* dp;
        int count = 0;
        while ((dp = readdir(dir)) != NULL) {
            if (count >= max_backups) {
                char backup_path[MAX];
                snprintf(backup_path, MAX, "%s%s", backup_dir, dp->d_name);
                delete_backup(backup_path);
            }
            count++;
        }
        closedir(dir);
    } else {
        printf("Error: Failed to open backup directory\n");
        exit(1);
    }

    // Save config changes
    save_config();

    return 0;
}

void create_backup(char* file_path) {
    char backup_path[MAX];
    snprintf(backup_path, MAX, "%s%s_%s", backup_dir, file_path, get_timestamp());

    FILE* file = fopen(file_path, "r");
    FILE* backup = fopen(backup_path, "w");

    if (file == NULL || backup == NULL) {
        printf("Error: Failed to open file or backup\n");
        exit(1);
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        fputc(c, backup);
    }

    fclose(file);
    fclose(backup);

    printf("Created backup %s\n", backup_path);
}

void delete_backup(char* backup_path) {
    if (remove(backup_path) == 0) {
        printf("Deleted backup %s\n", backup_path);
    } else {
        printf("Error: Failed to delete backup %s\n", backup_path);
    }
}

char* get_timestamp() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    static char timestamp[MAX];
    strftime(timestamp, MAX, "%Y%m%d-%H%M%S", tm);
    return timestamp;
}

void read_config() {
    FILE* config_file = fopen(CONFIG_FILE, "r");

    if (config_file != NULL) {
        char line[MAX];
        while (fgets(line, MAX, config_file) != NULL) {
            char key[MAX], value[MAX];

            if (sscanf(line, "%s %s", key, value) != 2) {
                printf("Error: Invalid config file format\n");
            }

            if (strcmp(key, "max_backups") == 0) {
                max_backups = atoi(value);
            } else if (strcmp(key, "backup_dir") == 0) {
                strncpy(backup_dir, value, MAX);
            }
        }

        fclose(config_file);
    } else {
        printf("Error: Failed to open config file\n");
        exit(1);
    }
}

void save_config() {
    FILE* config_file = fopen(CONFIG_FILE, "w");

    if (config_file != NULL) {
        fprintf(config_file, "max_backups %d\n", max_backups);
        fprintf(config_file, "backup_dir %s\n", backup_dir);
        fclose(config_file);
    } else {
        printf("Error: Failed to save config changes\n");
    }
}