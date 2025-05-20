//FormAI DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_COUNT 5

void backup_file(char *filename);
void restore_file(char *filename, int backup_index);
void delete_file(char *filename, int backup_index);
void list_backups(char *filename);

int main(int argc, char **argv) {
    char filename[MAX_FILENAME_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strncpy(filename, argv[1], MAX_FILENAME_LENGTH);

    while (1) {
        printf("Enter command (backup, restore, delete, list, quit): ");

        char command[10];
        scanf("%s", command);

        if (strcmp(command, "backup") == 0) {
            backup_file(filename);
        } else if (strcmp(command, "restore") == 0) {
            int backup_index;
            printf("Enter backup index to restore: ");
            scanf("%d", &backup_index);
            restore_file(filename, backup_index);
        } else if (strcmp(command, "delete") == 0) {
            int backup_index;
            printf("Enter backup index to delete: ");
            scanf("%d", &backup_index);
            delete_file(filename, backup_index);
        } else if (strcmp(command, "list") == 0) {
            list_backups(filename);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}

void backup_file(char *filename) {
    char backup_filename[MAX_FILENAME_LENGTH];
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s.%04d%02d%02d%02d%02d%02d",
             filename, time_info->tm_year+1900, time_info->tm_mon+1, time_info->tm_mday,
             time_info->tm_hour, time_info->tm_min, time_info->tm_sec);

    char command[MAX_FILENAME_LENGTH + 20];
    snprintf(command, MAX_FILENAME_LENGTH + 20, "cp %s %s", filename, backup_filename);
    system(command);

    printf("Backup created: %s\n", backup_filename);

    char list_command[MAX_FILENAME_LENGTH + 20];
    snprintf(list_command, MAX_FILENAME_LENGTH + 20, "ls -1 %s.* | wc -l", filename);
    FILE *count_file = popen(list_command, "r");

    char count_str[10];
    fgets(count_str, 10, count_file);
    int backup_count = atoi(count_str);

    if (backup_count > MAX_BACKUP_COUNT) {
        int oldest_index = 1;
        time_t oldest_time = raw_time;

        for (int i = 1; i <= backup_count; i++) {
            char backup_list_command[MAX_FILENAME_LENGTH + 20];
            snprintf(backup_list_command, MAX_FILENAME_LENGTH + 20, "ls -1t %s.* | sed -n %dp | cut -d. -f2-",
                     filename, i);

            FILE *backup_file = popen(backup_list_command, "r");
            char backup_filename[256];

            fgets(backup_filename, 256, backup_file);

            struct tm time;
            strptime(backup_filename, "%Y%m%d%H%M%S", &time);

            time_t backup_time = mktime(&time);

            if (backup_time < oldest_time) {
                oldest_time = backup_time;
                oldest_index = i;
            }
        }

        char backup_list_command[MAX_FILENAME_LENGTH + 20];
        snprintf(backup_list_command, MAX_FILENAME_LENGTH + 20, "ls -1t %s.* | sed -n %dp",
                 filename, oldest_index);

        FILE *backup_file = popen(backup_list_command, "r");
        char backup_filename[256];

        fgets(backup_filename, 256, backup_file);

        delete_file(filename, oldest_index);
    }
}

void restore_file(char *filename, int backup_index) {
    char backup_filename[MAX_FILENAME_LENGTH];
    snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s.%0*d", filename, 2, backup_index);

    char command[MAX_FILENAME_LENGTH + 20];
    snprintf(command, MAX_FILENAME_LENGTH + 20, "cp %s.%0*d %s", filename, 2, backup_index,
             filename);
    system(command);

    printf("Backup %d restored.\n", backup_index);
}

void delete_file(char *filename, int backup_index) {
    char backup_filename[MAX_FILENAME_LENGTH];
    snprintf(backup_filename, MAX_FILENAME_LENGTH, "%s.%0*d", filename, 2, backup_index);

    char command[MAX_FILENAME_LENGTH + 20];
    snprintf(command, MAX_FILENAME_LENGTH + 20, "rm %s", backup_filename);
    system(command);

    printf("Backup %d deleted.\n", backup_index);
}

void list_backups(char *filename) {
    char list_command[MAX_FILENAME_LENGTH + 20];
    snprintf(list_command, MAX_FILENAME_LENGTH + 20, "ls -1 %s.* | cut -d. -f2-",
             filename);

    FILE *backup_list = popen(list_command, "r");

    char backup_filename[MAX_FILENAME_LENGTH];
    int backup_index = 1;

    while (fgets(backup_filename, MAX_FILENAME_LENGTH, backup_list) != NULL) {
        printf("%d: %s", backup_index++, backup_filename);
    }

    if (backup_index == 1) {
        printf("No backups available.\n");
    }
}