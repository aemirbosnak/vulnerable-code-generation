//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scientific
/*
 * C File Synchronizer Example Program
 * Author: [Your Name]
 * Date: [Today's Date]
 *
 * This program synchronizes two directories by copying all files from one directory 
 * to another if the file does not already exist in the destination directory or if 
 * the file in the source directory is newer than the one in the destination directory.
 * The program also logs all actions taken during the synchronization process.
 * 
 * NOTE: This program only synchronizes files, not directories or subdirectories.
 *
 * Usage: sync <source_dir> <dest_dir>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

// Function prototypes
void synchronize(char *source_dir, char *dest_dir);
int should_copy(struct dirent *entry, char *source_dir, char *dest_dir);
void log_action(char *action, char *filename);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    synchronize(argv[1], argv[2]);
    
    return 0;
}

/*
 * Synchronize two directories by copying all files from source to destination if the 
 * file is newer in the source directory or if the file does not exist in the destination
 * directory.
 */
void synchronize(char *source_dir, char *dest_dir) {
    DIR *source_dp, *dest_dp;
    struct dirent *entry;
    struct stat stat_buf;
    char source_path[256], dest_path[256];
    
    // Open source and destination directories
    if ((source_dp = opendir(source_dir)) == NULL) {
        fprintf(stderr, "Unable to open directory %s\n", source_dir);
        exit(EXIT_FAILURE);
    }
    if ((dest_dp = opendir(dest_dir)) == NULL) {
        fprintf(stderr, "Unable to open directory %s\n", dest_dir);
        exit(EXIT_FAILURE);
    }
    
    // Read files from source directory
    while ((entry = readdir(source_dp)) != NULL) {
        // Only copy regular files and skip hidden files
        if (entry->d_type == DT_REG && entry->d_name[0] != '.') {
            // Check if file needs to be copied or updated
            if (should_copy(entry, source_dir, dest_dir)) {
                // Generate file paths
                sprintf(source_path, "%s/%s", source_dir, entry->d_name);
                sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
                
                // Copy file and set modification time to source file's modification time
                FILE *source_fp, *dest_fp;
                char ch;
                if ((source_fp = fopen(source_path, "rb")) == NULL) {
                    fprintf(stderr, "Unable to open file %s\n", source_path);
                    continue;
                }
                if ((dest_fp = fopen(dest_path, "wb")) == NULL) {
                    fprintf(stderr, "Unable to create file %s\n", dest_path);
                    fclose(source_fp);
                    continue;
                }
                while ((ch = fgetc(source_fp)) != EOF) {
                    fputc(ch, dest_fp);
                }
                fclose(source_fp);
                fclose(dest_fp);
                stat(source_path, &stat_buf);
                utime(dest_path, &stat_buf.st_mtime);
                
                // Log action
                log_action("Copied", entry->d_name);
            }
        }
    }
    
    closedir(source_dp);
    closedir(dest_dp);
}

/*
 * Determines whether a file needs to be copied by comparing the modification time of
 * the source file and the destination file. Returns 1 if the file needs to be copied,
 * 0 otherwise.
 */
int should_copy(struct dirent *entry, char *source_dir, char *dest_dir) {
    struct stat source_buf, dest_buf;
    char source_path[256], dest_path[256];
    
    // Generate file paths
    sprintf(source_path, "%s/%s", source_dir, entry->d_name);
    sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
    
    // Get modification times of source and destination files
    stat(source_path, &source_buf);
    if (stat(dest_path, &dest_buf) == -1) {
        // If destination file does not exist, copy file
        return 1;
    }
    
    // Compare modification times and return result
    if (difftime(source_buf.st_mtime, dest_buf.st_mtime) > 0) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * Logs an action taken during the synchronization process to the console.
 */
void log_action(char *action, char *filename) {
    time_t now;
    struct tm *timeinfo;
    
    time(&now);
    timeinfo = localtime(&now);
    printf("[%02d:%02d:%02d] %s %s\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, action, filename);
}