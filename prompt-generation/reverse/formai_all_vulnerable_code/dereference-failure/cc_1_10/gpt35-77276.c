//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILE_NAME_LENGTH 200
#define MAX_BACKUP_COUNT 10
#define BUFFER_SIZE 1024

void create_backup_folder(const char *backup_folder_path) {
    // check if folder already exists
    if (access(backup_folder_path, F_OK) == 0) {
        return;
    }

    // create backup folder
    if (mkdir(backup_folder_path, 0777) == -1) {
        printf("Error: failed to create backup folder\n");
        exit(1);
    }
}

void generate_backup_filename(const char *file_name, char *backup_file_name) {
    // get current time
    time_t current_time;
    time(&current_time);

    // format current time as string
    char time_string[40];
    strftime(time_string, sizeof(time_string), "%Y-%m-%d-%H-%M-%S", localtime(&current_time));

    // generate backup file name
    sprintf(backup_file_name, "%s-%s.bak", file_name, time_string);
}

void backup_file(const char *file_path, const char *backup_folder_path) {
    // extract file name
    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, strrchr(file_path, '/') + 1);

    // generate backup file name
    char backup_file_name[MAX_BACKUP_FILE_NAME_LENGTH];
    generate_backup_filename(file_name, backup_file_name);

    // open original file for reading
    FILE *original_file = fopen(file_path, "r");
    if (original_file == NULL) {
        printf("Error: failed to open file for backup\n");
        exit(1);
    }

    // create backup folder if necessary
    create_backup_folder(backup_folder_path);

    // construct backup file path
    char backup_file_path[MAX_BACKUP_FILE_NAME_LENGTH];
    sprintf(backup_file_path, "%s/%s", backup_folder_path, backup_file_name);

    // open backup file for writing
    FILE *backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: failed to create backup file\n");
        exit(1);
    }

    // buffer for holding file contents
    char buffer[BUFFER_SIZE];

    // copy file contents to backup file
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    // close files
    fclose(original_file);
    fclose(backup_file);

    // print success message
    printf("Backup file created: %s\n", backup_file_path);
}

bool confirmation_prompt(const char *message) {
    // display confirmation message
    printf("%s [y/n]: ", message);

    // read user input
    char input[10];
    fgets(input, sizeof(input), stdin);

    // return true if input starts with 'y' or 'Y', false otherwise
    return (input[0] == 'y' || input[0] == 'Y');
}

void delete_oldest_backup(const char *backup_folder_path) {
    // list files in backup folder
    char backup_file_pattern[MAX_BACKUP_FILE_NAME_LENGTH];
    sprintf(backup_file_pattern, "%s/*.bak", backup_folder_path);

    system("ls -t1r /tmp/*.bak > /tmp/backup_list.txt");

    // read file list into array
    char backup_file_list[MAX_BACKUP_COUNT][MAX_BACKUP_FILE_NAME_LENGTH];
    FILE *file_list = fopen("/tmp/backup_list.txt", "r");
    int backup_count = 0;
    while (fgets(backup_file_list[backup_count], MAX_BACKUP_FILE_NAME_LENGTH, file_list) != NULL) {
        backup_count++;
    }
    fclose(file_list);

    // check if there are too many backups
    if (backup_count > MAX_BACKUP_COUNT) {
        // extract oldest backup file path
        char oldest_backup_file_path[MAX_BACKUP_FILE_NAME_LENGTH];
        strcpy(oldest_backup_file_path, backup_file_list[0]);
        oldest_backup_file_path[strlen(oldest_backup_file_path)-1] = '\0';

        // prompt user for confirmation
        if (confirmation_prompt("Delete oldest backup file?")) {
            // delete oldest backup file
            if (remove(oldest_backup_file_path) == -1) {
                printf("Error: failed to delete oldest backup file\n");
                exit(1);
            }

            // print success message
            printf("Oldest backup file deleted: %s\n", oldest_backup_file_path);
        } else {
            printf("Backup deletion cancelled\n");
        }
    }
}

int main(int argc, char **argv) {
    // check command line arguments
    if (argc != 3) {
        printf("Usage: %s <file_path> <backup_folder_path>\n", argv[0]);
        exit(1);
    }

    // perform backup
    backup_file(argv[1], argv[2]);

    // check number of backups and prompt for deletion of oldest backup if necessary
    delete_oldest_backup(argv[2]);

    return 0;
}