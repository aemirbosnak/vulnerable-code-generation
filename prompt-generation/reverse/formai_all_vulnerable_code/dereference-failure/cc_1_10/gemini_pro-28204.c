//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

// Define the maximum file name length
#define MAX_FILE_NAME_LENGTH 256

// Define the maximum number of files to backup
#define MAX_FILES 100

// Define the backup directory
#define BACKUP_DIR "/tmp/backups"

// Declare the main function
int main() {
    // Get the current time
    time_t now = time(NULL);

    // Create the backup directory if it doesn't exist
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0755);
    }

    // Get a list of all the files in the current directory
    DIR *dir = opendir(".");
    struct dirent *entry;
    char files[MAX_FILES][MAX_FILE_NAME_LENGTH];
    int num_files = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            strcpy(files[num_files], entry->d_name);
            num_files++;
        }
    }
    closedir(dir);

    // Backup each file
    for (int i = 0; i < num_files; i++) {
        // Open the original file
        FILE *fp_in = fopen(files[i], "r");
        if (fp_in == NULL) {
            perror("fopen");
            continue;
        }

        // Open the backup file
        char backup_file_name[MAX_FILE_NAME_LENGTH];
        sprintf(backup_file_name, "%s/%s-%ld.bak", BACKUP_DIR, files[i], now);
        FILE *fp_out = fopen(backup_file_name, "w");
        if (fp_out == NULL) {
            perror("fopen");
            fclose(fp_in);
            continue;
        }

        // Copy the contents of the original file to the backup file
        char buffer[1024];
        while (fread(buffer, 1, sizeof(buffer), fp_in) > 0) {
            fwrite(buffer, 1, sizeof(buffer), fp_out);
        }

        // Close the files
        fclose(fp_in);
        fclose(fp_out);
    }

    // Return 0 to indicate success
    return 0;
}