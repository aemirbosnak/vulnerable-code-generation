//FormAI DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_LENGTH 10000
#define MAX_BACKUP_FILES 10

typedef struct BackupFile {
    char name[MAX_FILENAME_LENGTH];
    char created_at[30];
    char content[MAX_BUFFER_LENGTH];
} BackupFile;

// Function to create a timestamp with current date and time
char* create_timestamp() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    return asctime(timeinfo);
}

// Function to prompt user for input
char* prompt(char* message) {
    printf("%s", message);

    char* input = (char*) malloc(MAX_FILENAME_LENGTH);
    fgets(input, MAX_FILENAME_LENGTH, stdin);

    // Remove newline character at the end of string
    input[strcspn(input, "\n")] = 0;

    return input;
}

int main() {
    char* filename = prompt("Enter filename: ");
    char* content = prompt("Enter content: ");

    // Create backup file
    BackupFile backup_file;
    strcpy(backup_file.name, filename);
    strcpy(backup_file.created_at, create_timestamp());
    strcpy(backup_file.content, content);

    printf("Backup file created:\n");
    printf("Name: %s\n", backup_file.name);
    printf("Created at: %s", backup_file.created_at);
    printf("Content: %s\n", backup_file.content);

    // Write backup file to disk
    FILE* fp = fopen("backup.bin", "ab");
    fwrite(&backup_file, sizeof(BackupFile), 1, fp);
    fclose(fp);

    // Read backup files from disk
    printf("Recent backup files:\n");
    fp = fopen("backup.bin", "rb");
    BackupFile backup_files[MAX_BACKUP_FILES];
    int num_backup_files = 0;

    while(fread(&backup_files[num_backup_files], sizeof(BackupFile), 1, fp)) {
        if(num_backup_files >= MAX_BACKUP_FILES) {
            printf("Max number of backup files reached. Exiting...\n");
            exit(1);
        }

        // Print backup file details
        printf("Name: %s\n", backup_files[num_backup_files].name);
        printf("Created at: %s", backup_files[num_backup_files].created_at);
        printf("Content: %s\n", backup_files[num_backup_files].content);
        printf("\n");
        
        num_backup_files++;
    }

    fclose(fp);
    return 0;
}