//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

struct backup_file {
    char filename[MAX_FILENAME_LENGTH];
    time_t backup_time;
};

struct backup_file backup_files[MAX_FILES];
int num_backup_files = 0;

void backup_files_add(char* filename) {
    if (num_backup_files >= MAX_FILES) {
        printf("Too many backup files!\n");
        return;
    }

    struct backup_file backup;
    strncpy(backup.filename, filename, MAX_FILENAME_LENGTH);
    backup.backup_time = time(NULL);

    backup_files[num_backup_files++] = backup;

    printf("File %s backed up.\n", filename);
}

void backup_files_list() {
    printf("Backup files:\n");

    for (int i = 0; i < num_backup_files; i++) {
        time_t backup_time = backup_files[i].backup_time;
        char* backup_time_str = ctime(&backup_time);
        backup_time_str[strlen(backup_time_str) - 1] = '\0';  // Remove newline character
        
        printf("%s, backed up on %s\n", backup_files[i].filename, backup_time_str);
    }
}

bool backup_files_remove(char* filename) {
    for (int i = 0; i < num_backup_files; i++) {
        if (strcmp(backup_files[i].filename, filename) == 0) {
            for (int j = i + 1; j < num_backup_files; j++) {
                backup_files[j - 1] = backup_files[j];
            }
            num_backup_files--;
            printf("File %s removed from backups.\n", filename);
            return true;
        }
    }

    printf("File %s not found in backups.\n", filename);
    return false;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [command] [filename]\n", argv[0]);
        return 1;
    }

    char* command = argv[1];
    char* filename = argv[2];

    if (strcmp(command, "add") == 0) {
        backup_files_add(filename);
    } else if (strcmp(command, "list") == 0) {
        backup_files_list();
    } else if (strcmp(command, "remove") == 0) {
        backup_files_remove(filename);
    } else {
        printf("Invalid command!\n");
        return 1;
    }

    return 0;
}